#include<vector>
#include<iostream>
#include "Shape.h"
#include "Canvas.h"

using namespace std;
using namespace Graphics;

int main()
{
	Canvas b(750,400);
	Rect ra(Point(137, 290),113,40);
	b.Attach(ra);
	Rect rb(Point(250, 240), 210,90);
	b.Attach(rb);
	Rect rc(Point(460, 290), 113, 40);
	b.Attach(rc);
	Rect rd(Point(260, 250), 80, 30);
	b.Attach(rd);
	Rect re(Point(365, 250), 80, 30);
	b.Attach(re);
	Rect rf(Point(353, 240), 1, 90);
	b.Attach(rf);
	Rect rg(Point(550, 300), 23, 6);
	b.Attach(rg);
	Circle ca(Point(330, 295), 4);
	b.Attach(ca);
	Circle cb(Point(438, 295), 4);
	b.Attach(cb);
	Circle cc(Point(250, 350), 30);
	Circle cd(Point(438, 350), 30);
	b.Attach(cc);
	b.Attach(cd);
	Circle ce(Point(250, 350), 17);
	Circle cf(Point(438, 350), 17);
	b.Attach(ce);
	b.Attach(cf);
	Circle cg(Point(250, 350), 4);
	Circle ch(Point(438, 350), 4);
	b.Attach(cg);
	b.Attach(ch);
	b.ConvertToBitmap();
	b.FloodFill(203, 308, Color::blue);
	b.FloodFill(399, 300, Color::blue);
	b.FloodFill(295, 309, Color::blue);
	b.FloodFill(488, 318, Color::blue);
	b.FloodFill(330, 295, Color::black);
	b.FloodFill(438, 295, Color::black);
	b.FloodFill(565, 303, Color::yellow);
	b.FloodFill(244, 326, Color::black);
	b.FloodFill(256, 325, Color::black);
	b.FloodFill(272, 348, Color::black);
	b.FloodFill(250, 350, Color::black);
	b.FloodFill(438, 350, Color::black);
	b.FloodFill(442, 324, Color::black);
	b.FloodFill(461, 347, Color::black);
	b.FloodFill(261, 348, Color::grey);
	b.FloodFill(447, 355, Color::grey);
	b.SaveToBitmap("MyYellowCar");

	return 0;
}