#include <CtrlLib/CtrlLib.h>
#include <AutoScroller/AutoScroller.h>
#define LAYOUTFILE <Drinks/drinks.lay>
#include <CtrlCore/lay.h>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "drinks.h"

using namespace Upp;

class MyAppWindow : public WithMainAppWindow<TopWindow> //with layout name from layout file
{
public:
	MyAppWindow();
private:
	AutoScroller scroller;
	WithDrinks<ParentCtrl> scroller_view;
	drink d;
	Option flavor[NUM_FLAV];
};

MyAppWindow::MyAppWindow()
{
	CtrlLayout(*this, "Drink Order Form");
	Sizeable().Zoomable();
	scroller.EnableScroll();
	Add(scroller.SizePos());
	CtrlLayout(scroller_view);
	scroller.AddPane(scroller_view);
	scroller_view.base = -1;
	scroller_view.size = -1;
	scroller_view.temp = -1;
	for(int i = 0; i < NUM_DAIRY; i++)
	{
		scroller_view.dairy.Add(dairyStr[i]);
	}
	
	for(int i = 0; i < NUM_FLAV; i++)
	{
		flavor[i].SetLabel(flavStr[i].c_str()).SetFont(Upp::StdFontZ(14));
	}
	int l = 0;
	int optionSize = 120;
	int checkDist = 20;
	int checkCount = 0;
	for(int i = 0; i < NUM_FLAV; i++)
	{
		scroller_view.flavorOptions.Add(flavor[i].LeftPosZ(l+optionSize*(i%2), optionSize).TopPosZ(0 + checkDist * checkCount));
		if(i %2 == 1)
		{
			checkCount++;
		}
		
	}
}

GUI_APP_MAIN
{
	MyAppWindow app;
	app.Run();
}
