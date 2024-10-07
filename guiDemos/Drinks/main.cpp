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
	void checkPrice();
	void SaveOrder();
private:
	AutoScroller scroller;
	WithDrinks<ParentCtrl> scroller_view;
	
	drink d;
	Option flavor[NUM_FLAV];
	std::vector<drink> order;
	Button writeBtn;
	OptionTree optree;
};

MyAppWindow::MyAppWindow()
{
	CtrlLayout(*this, "Drink Order Form");
	Sizeable().Zoomable();
	scroller.EnableScroll();
	Add(scroller.SizePos());
	
	CtrlLayout(scroller_view);
	scroller.AddPane(scroller_view);
	writeBtn.SetLabel("Complete Order");
	
	
	scroller_view.base = -1;
	scroller_view.size = -1;
	scroller_view.temp = -1;
	for(int i = 0; i < NUM_DAIRY; i++)
	{
		scroller_view.dairy.Add(dairyStr[i]);
	}
	scroller_view.dairy.GoBegin();
	/*for(int i = 0; i < NUM_FLAV; i++)
	{
		flavor[i].SetLabel(flavStr[i].c_str()).SetFont(Upp::StdFont());
	}*/
	int l = 0;
	int optionSize = 120;
	int checkDist = 20;
	int checkCount = 0;
	optree.SetRoot("All Flavors");
	for(int i = 0; i < NUM_FLAV; i++)
	{
		//scroller_view.flavorOptions.Add(flavor[i].LeftPosZ(l+optionSize*(i%2), optionSize).TopPosZ(0 + checkDist * checkCount));
		//if(i %2 == 1)
		//{
		//	checkCount++;
		//}
		optree.Add(0, flavor[i], flavStr[i].c_str());
		flavor[i] << [&, this,i]
		{
			if(flavor[i].Get())
			{
				d.addFlavor(flavs[i]);
			}
			else
			{
				d.removeFlavor(flavs[i]);
			}
			checkPrice();
		};
	}
	scroller_view.flavorOptions.Add(optree.SizePos());
	/* this code does not work.
	optree << [&, this]
	{
		if(optree.Get(0) == 1)
			for(int i = 0; i < NUM_FLAV; i++)
				d.addFlavor(flavs[i]);
		else
			d.removeAllFlavor();
		checkPrice();
	};*/
	// = in the [] means local variables are passed by value
	// class members are passed by reference or maybe value
	// [&, this] everything is by reference
	scroller_view.base << [&, this]
	{
		baseType b = static_cast<baseType>((int)scroller_view.base);
		d.setBase(b);
		checkPrice();
	};
	
	scroller_view.size << [&, this]
	{
		sizeType s = static_cast<sizeType>((int)scroller_view.size);
		d.setSize(s);
		checkPrice();
	};
	scroller_view.temp << [&, this]
	{
		tempType t = static_cast<tempType>((int)scroller_view.temp);
		d.setTemperature(t);
		checkPrice();
	};
	
	scroller_view.dairy << [&, this]
	{
		d.setDairy(scroller_view.dairy.GetData().ToStd());
		checkPrice();
		
	};
	scroller_view.createDrink << [&, this]
	{
		if((int)scroller_view.temp == -1 || (int)scroller_view.size == -1 || (int)scroller_view.base == -1)
		{
			ErrorOK("Please choose the base, size, and temperature");
			return;
		}
		order.push_back(d);
		std::ostringstream drinkStr;
		drinkStr << d << std::endl;
		scroller_view.drinkList.Append(drinkStr.str());
		scroller_view.base = -1;
		d.setBase(CREAM);
		scroller_view.temp = -1;
		d.setTemperature(HOT);
		scroller_view.size = -1;
		d.setSize(SMALL);
		scroller_view.dairy.GoBegin();
		d.setDairy("None");
		d.removeAllFlavor();
		for(int i = 0; i < 10; i++)
		{
			flavor[i] = 0;
		}
		scroller_view.price.SetData("");
		scroller_view.writeBtnHolder.Add(writeBtn.HSizePosZ().VSizePosZ());
	};
	writeBtn << [&, this]{SaveOrder();};
	
	
	
	
	
	
	Image m = StreamRaster::LoadFileAny("snowball.jpg");
	
	Size rsz = scroller_view.snowball.GetSize();
	Size isz = m.GetSize();
	if(isz.cx >= rsz.cx || isz.cy >= rsz.cy) {
		if(isz.cx * rsz.cx < rsz.cy * isz.cy)
			rsz.cx = isz.cx * rsz.cy / isz.cy;
		else
			rsz.cy = isz.cy * rsz.cx / isz.cx;
		m = Rescale(m, rsz);
		scroller_view.snowball.SetImage(Rescale(m,rsz));
	}
	scroller_view.snowball.SetImage(m);
}

void MyAppWindow::Paint(Draw& w)
{
	w.DrawRect(GetSize(), Color(218, 218,218));
}
void MyAppWindow::SaveOrder()
{
	std::ofstream out("order.txt");
	out << std::setprecision(2) << std::fixed << std::showpoint;
	double total = 0;
	for(int i = 0; i < order.size(); i++)
	{
		out << order[i] << std::endl;
		total += order[i].getPrice();
	}
	out << "Total: $" << total;
	out.close();
	Close();
	MyAppWindow().Run();
}

void MyAppWindow::checkPrice()
{
	if((int)scroller_view.temp != -1 && (int)scroller_view.size != -1 && (int)scroller_view.base != -1)
	{
			std::ostringstream priceStr;
			priceStr << std::setprecision(2) << std::fixed << std::showpoint;
			priceStr << "$" << d.getPrice();
			scroller_view.price.SetData(priceStr.str());
	}
}

GUI_APP_MAIN
{
	
	
	SetStdFont(Arial(16));
	MyAppWindow app;
	app.Run();
}
