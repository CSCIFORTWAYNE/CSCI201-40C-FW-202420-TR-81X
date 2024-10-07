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
	void Paint(Draw&);
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
		flavor[i].SetLabel(flavStr[i].c_str()).SetFont(Upp::StdFont());
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
	
	// = in the [] means local variables are passed by value
	// class members are passed by reference or maybe value
	// [&, this] everything is by reference
	scroller_view.base << [&, this]
	{
		baseType b = static_cast<baseType>((int)scroller_view.base);
		d.setBase(b);
		if((int)scroller_view.temp != -1 && (int)scroller_view.size != -1)
		{
			std::ostringstream priceStr;
			priceStr << std::setprecision(2) << std::fixed << std::showpoint;
			priceStr << "$" << d.getPrice();
			scroller_view.price.SetData(priceStr.str());	
		}
	};
	
	scroller_view.size << [&, this]
	{
		sizeType s = static_cast<sizeType>((int)scroller_view.size);
		d.setSize(s);
		if((int)scroller_view.temp != -1 && (int)scroller_view.base != -1)
		{
			std::ostringstream priceStr;
			priceStr << std::setprecision(2) << std::fixed << std::showpoint;
			priceStr << "$" << d.getPrice();
			scroller_view.price.SetData(priceStr.str());	
		}
	};
	scroller_view.temp << [&, this]
	{
		tempType t = static_cast<tempType>((int)scroller_view.temp);
		d.setTemperature(t);
		if((int)scroller_view.size != -1 && (int)scroller_view.base != -1)
		{
			std::ostringstream priceStr;
			priceStr << std::setprecision(2) << std::fixed << std::showpoint;
			priceStr << "$" << d.getPrice();
			scroller_view.price.SetData(priceStr.str());	
		}
	};
	
}

void MyAppWindow::Paint(Draw& w)
{
	w.DrawRect(GetSize(), Color(218, 218,218));
}


GUI_APP_MAIN
{
	
	
	SetStdFont(Arial(16));
	MyAppWindow app;
	app.Run();
}
