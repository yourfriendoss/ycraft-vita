#ifndef YCRAFT_UTIL_HH
#define YCRAFT_UTIL_HH

#include "_components.hh"

class Logs {
	public:
		void                      Log(const char* format, ...);
		void                      Error(const char* format, ...);

		std::vector <std::string> logs;
		static Logs& 		      Instance();
};

namespace Util {
	std::string               CurrentTime();
	std::string               GetExecutableLocation();
	std::string               DirName(std::string path);
	double                    Clamp(double x, double min, double max);
	std::string               Trim(const std::string& str);
	std::vector <std::string> GetFilesInDirectory(std::string path);
	std::string               BaseName(std::string path);
	bool                      IsNumber(std::string str);
	std::string               CorrectURL(std::string str);
	bool                      StringEndsWith(std::string base, std::string end);
	std::vector <std::string> GetFilesOfType(std::string path, std::string type);
	int                       RandomRange(int min, int max);
	float                     FRandomRange(float min, float max);
}

#endif
