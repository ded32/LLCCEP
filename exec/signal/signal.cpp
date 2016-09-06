#include <csignal>
#include <map>

#include <STDExtras.hpp>
#include <convert.hpp>

#include "../messageBox/messageBox.hpp"
#include "signal.hpp"

void LLCCEP_exec::cAttachSignalsHandler()
{
#if !defined DEBUGGER
	::std::signal(SIGABRT, LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGFPE,  LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGILL,  LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGINT,  LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGSEGV, LLCCEP_exec::cSignalsHandler);
	::std::signal(SIGTERM, LLCCEP_exec::cSignalsHandler);
#endif
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

	::std::string msg = ::std::string("Program was interrupted by a signal(") +
			    to_string(signo) + ::std::string("):\n") + sigmsg[signo] +
			    ::std::string("\n");

	messageBox("Program was interrupted by a signal",
		   msg.c_str(),
		   QMessageBox::Close,
		   QMessageBox::Close,
		   QMessageBox::Critical).spawn();

	QUITE_ERROR(yes, "%s", msg.c_str())
}
