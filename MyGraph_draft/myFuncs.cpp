#include "myFuncs.h"

void line(int x0, int y0, int x1, int y1, TGAImage& img, TGAColor clr)
{
	bool steep = false;
	if (std::abs(x0 - x1) < std::abs(y0 - y1))
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
		steep = true;
	}
	if (x0 > x1)
	{ // make it left-to-right
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	int deltax = abs(x1 - x0);
	int deltay = abs(y1 - y0);
	int error = 0;
	int deltaerr = deltay + 1;
	int diry = y1 - y0 > 0 ? 1 : -1;
	for (int x = x0, y = y0; x < x1; ++x)
	{
		if (steep)
		{
			img.set(y, x, clr);
		}
		else  img.set(x, y, clr);
		
		error += deltaerr;
		if (error >= deltax + 1)
		{
			y += diry;
			error -= deltax + 1;
		}
	}
}