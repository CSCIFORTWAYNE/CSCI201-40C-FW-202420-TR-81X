#include <CtrlLib/CtrlLib.h>
#include <iostream>

using namespace Upp;

GUI_APP_MAIN
{
	int x = ErrorRetryCancel("Hello World!");
	
	std::cout << x << std::endl;
}
