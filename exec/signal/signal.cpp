#include <csignal>
#include <map>

#include <STDExtras.hpp>

#include "signal.hpp"

void LLCCEP_exec::cAttachSignalsHandler()
{
	::std::signal(SIGABRT, LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGFPE, LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGILL, LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGINT, LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGSEGV, LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGTERM, LLCCEP_exec::cSignalsHandler);
}

void LLCCEP_exec::cSignalsHandler(int signo)
{
	::std::map<int, ::std::string> sigmsg = {
		{SIGABRT, "Abnormal termination, alike abort()'s call gives."},
		{SIGFPE, "Erroneous arithmetic operation. Maybe FPU divide by zero, or overflow."},
		{SIGILL, "Illegal instruction found."},
		{SIGINT, "Termination requested by application."},
		{SIGSEGV, "Segmentation violation: don't permitted to use some data."},
		{SIGTERM, "Termination requested by application."}
	};

	QUITE_ERROR(yes, "Program was interrupted by a signal(%d):\n%s",
			 signo, sigmsg[signo].c_str())
}
