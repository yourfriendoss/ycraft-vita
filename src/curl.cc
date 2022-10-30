#ifdef __vita__
	#include <psp2/net/net.h>
	#include <psp2/net/netctl.h>
	#include <psp2/net/http.h>
	#include <psp2/io/fcntl.h> 

	#include <psp2/sysmodule.h>
#endif

#include "util.hh"
#include "curl.hh"

#ifndef __vita__
	// write function
	size_t CurlWriteFunction(char* buf, size_t size, size_t nmemb, void* userp) {
		auto fstream = static_cast <std::ofstream*>(userp);
		fstream->write(buf, nmemb * size);
		return nmemb * size;
	}
#endif

#ifdef __vita__
	CurlComponents::CurlComponents() {

	}
#else
	CurlComponents::CurlComponents(): handle(nullptr) {

	}
#endif

void CurlComponents::Init() {
	#ifndef __vita__
		if (curl_global_init(CURL_GLOBAL_ALL) != 0) {
			Util::Error("curl_global_init failed");
		}

		handle = curl_easy_init();
		if (!handle) {
			Util::Error("curl_easy_init returned NULL");
		}
		Util::Log("Initialised libcurl");

	#else
		// VITA: Start modules
		sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
		
		SceNetInitParam netInitParam;
		int size = 1*1024*1024;
		netInitParam.memory = malloc(size);
		netInitParam.size = size;
		netInitParam.flags = 0;
		sceNetInit(&netInitParam);

		sceNetCtlInit();

		sceSysmoduleLoadModule(SCE_SYSMODULE_HTTP);

		sceHttpInit(1*1024*1024);
	#endif
}

void CurlComponents::Free() {
	#ifndef __vita__
		curl_easy_cleanup(handle);
		curl_global_cleanup();
		Util::Log("Cleaned up libcurl");
	#else
		// VITA: Terminate both the NET and HTTP modules
		sceNetCtlTerm();
		sceNetTerm();
		sceSysmoduleUnloadModule(SCE_SYSMODULE_NET);

		sceHttpTerm();
		sceSysmoduleUnloadModule(SCE_SYSMODULE_HTTP);
	#endif
}

void CurlComponents::Download(std::string url, std::string whereTo) {
	#ifndef __vita__
		std::ofstream fhnd(whereTo);
		std::string   corrected = Util::CorrectURL(url);

		curl_easy_reset(handle);
		curl_easy_setopt(handle, CURLOPT_URL,           Util::CorrectURL(url).c_str());
		curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, CurlWriteFunction);
		curl_easy_setopt(handle, CURLOPT_WRITEDATA,     &fhnd);
		curl_easy_setopt(handle, CURLOPT_FAILONERROR,   true);

		auto rc = curl_easy_perform(handle);
		if (rc != CURLE_OK) {
			Util::Error(
				"curl_easy_perform failed: %s\nURL: %s",
				curl_easy_strerror(rc), Util::CorrectURL(url).c_str()
			);
		}
		Util::Log("Downloaded to %s", whereTo.c_str());
	#else
		int tpl = sceHttpCreateTemplate("ycraft-vita (Mozilla/5.0)", 1, 1);
		int conn = sceHttpCreateConnectionWithURL(tpl, url.c_str(), 0);

		int request = sceHttpCreateRequestWithURL(conn, SCE_HTTP_METHOD_GET, url.c_str(), 0);

		int handle = sceHttpSendRequest(request, NULL, 0);
		int fh = sceIoOpen(whereTo.c_str(), SCE_O_WRONLY | SCE_O_CREAT, 0777);

		unsigned char data[16*1024];
		int read = 0;

		while ((read = sceHttpReadData(request, &data, sizeof(data))) > 0) {
			int write = sceIoWrite(fh, data, read);
		}

		sceIoClose(fh);
	#endif
}