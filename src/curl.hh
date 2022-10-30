#ifndef YCRAFT_CURL_HH
#define YCRAFT_CURL_HH

#include "_components.hh"

class CurlComponents {
	public:
		#ifndef __vita__
			CURL* handle;
		#endif

		CurlComponents();
		void        Init();
		void        Free();
		void        Download(std::string url, std::string whereTo);
		std::string Curl(std::string url);
};

#endif