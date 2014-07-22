#include "stdafx.h"
#include "RGB.h"
#include <math.h>
#include <random>


void RGB::bound()
{
	R = R < 0 ? 0 : R > 255 ? 255 : R;
	G = G < 0 ? 0 : G > 255 ? 255 : G;
	B = B < 0 ? 0 : B > 255 ? 255 : B;
}
void RGB::speckle(int scale)
{
	R += rand()%(2*scale+1) - scale;
	G += rand()%(2*scale+1) - scale;
	B += rand()%(2*scale+1) - scale;
	bound();
}
val RGB::value()
{
	return (R+G+B)/3;
}
