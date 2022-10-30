#include "app.hh"
#include "util.hh"

#ifdef __vita__
	unsigned int _newlib_heap_size_user = 200 * 1024 * 1024;
	#include <psp2/power.h>
#endif

int main(int, char**) {
	#ifdef __vita__
		scePowerSetArmClockFrequency(444);
		scePowerSetBusClockFrequency(222);
		scePowerSetGpuClockFrequency(222);
		scePowerSetGpuXbarClockFrequency(166);
	#endif

	#ifndef DEBUG_EXCEPTION
	try {
	#endif
		App app;

		while (app.run) {
			app.Update();
		}
	#ifndef DEBUG_EXCEPTION
	}
	catch (std::exception& error) {
		Util::Error(error.what());
	}
	#endif
	return 0;
}