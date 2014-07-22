#include "stdafx.h"
#include "RGB.h"
#include <math.h>



RGB::RGB()
{
	set(0);
}

RGB::RGB(val r, val g, val b):
	R(r), G(g), B(b)
{
}

void RGB::set(val value)
{
	R = G = B = value;
}



val RGB::distance_squared_from(RGB other)
{
	val r_diff = other.R - R;
	val g_diff = other.G - G;
	val b_diff = other.B - B;
	return r_diff*r_diff + g_diff*g_diff + b_diff*b_diff;
}
double RGB::distance_from(RGB other)
{
	return sqrt(static_cast<double>(distance_squared_from(other)));
}




RGB & RGB::operator=(const RGB& other)
{
	R = other.R;
	G = other.G;
	B = other.B;
	return *this;
}

RGB & RGB::operator+=(const RGB& other)
{
	R += other.R;
	G += other.G;
	B += other.B;
	return *this;
}
RGB & RGB::operator-=(const RGB& other)
{
	R -= other.R;
	G -= other.G;
	B -= other.B;
	return *this;
}
RGB & RGB::operator*=(int scale)
{
	R *= scale;
	G *= scale;
	B *= scale;
	return *this;
}
RGB & RGB::operator*=(double scale)
{
	R *= scale; //static_cast<int>(scale * static_cast<double>(R));;
	G *= scale; //static_cast<int>(scale * static_cast<double>(G));;
	B *= scale; //static_cast<int>(scale * static_cast<double>(B));;
	return *this;
}
RGB & RGB::operator/=(int scale)
{
	R /= scale;
	G /= scale;
	B /= scale;
	return *this;
}
RGB & RGB::operator/=(double scale)
{
	R /= scale; //static_cast<int>(static_cast<double>(R) / scale);
	G /= scale; //static_cast<int>(static_cast<double>(G) / scale);
	B /= scale; //static_cast<int>(static_cast<double>(B) / scale);
	return *this;
}



const RGB RGB::operator+(const RGB& other)
{
	RGB rtrn;
	rtrn.R = R + other.R;
	rtrn.G = G + other.G;
	rtrn.B = B + other.B;
	return rtrn;
}
const RGB RGB::operator-(const RGB& other)
{
	RGB rtrn;
	rtrn.R = R - other.R;
	rtrn.G = G - other.G;
	rtrn.B = B - other.B;
	return rtrn;
}
const RGB RGB::operator*(int scale)
{
	RGB rtrn;
	rtrn.R = R * scale;
	rtrn.G = G * scale;
	rtrn.B = B * scale;
	return rtrn;
}
const RGB RGB::operator*(double scale)
{
	RGB rtrn;
	rtrn.R = R * scale; //static_cast<int>(scale * static_cast<double>(R));
	rtrn.G = G * scale; //static_cast<int>(scale * static_cast<double>(G));
	rtrn.B = B * scale; //static_cast<int>(scale * static_cast<double>(B));
	return rtrn;
}
const RGB RGB::operator/(int scale)
{
	RGB rtrn;
	rtrn.R = R / scale;
	rtrn.G = G / scale;
	rtrn.B = B / scale;
	return rtrn;
}
const RGB RGB::operator/(double scale)
{
	RGB rtrn;
	rtrn.R = R/scale; //static_cast<int>(static_cast<double>(R) / scale);
	rtrn.G = G/scale; //static_cast<int>(static_cast<double>(G) / scale);
	rtrn.B = B/scale; //static_cast<int>(static_cast<double>(B) / scale);
	return rtrn;
}
