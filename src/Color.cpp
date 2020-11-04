#include "Color.h"

Color::Color (void):
	red_ ((unsigned char) 0),
	green_ ((unsigned char) 0),
	blue_ ((unsigned char) 0),
	alpha_ ((unsigned char) 0)
{}

Color::Color (unsigned int r, unsigned int g, unsigned int b, unsigned int a):
	red_ ((unsigned char) r),
	green_ ((unsigned char) g),
	blue_ ((unsigned char) b),
	alpha_ ((unsigned char) a)
{
	check(r, g, b, a);
}

Color::Color (const Color & rhs):
	red_ ((unsigned char) rhs.red_),
	green_ ((unsigned char) rhs.green_),
	blue_ ((unsigned char) rhs.blue_),
	alpha_ ((unsigned char) rhs.alpha_)
{
	check((int)rhs.red_, (int)rhs.green_, (int)rhs.blue_, (int)rhs.alpha_);
}

Color::~Color (void) {}

void Color::check (int r, int g, int b, int a)
{
	if (r > 255)
		red_ = (unsigned char) 255;
	if (g > 255)
		green_ = (unsigned char) 255;
	if (b > 255)
		blue_ = (unsigned char) 255;
	if (a > 255)
		alpha_ = (unsigned char) 255;
	
	if (r < 0)
		red_ = (unsigned char) 0;
	if (g < 0)
		green_ = (unsigned char) 0;
	if (b < 0)
		blue_ = (unsigned char) 0;
	if (a < 0)
		alpha_ = (unsigned char) 0;
}

unsigned int Color::red (void) const
{
	return (unsigned int) red_;
}

unsigned int Color::green (void) const
{
	return (unsigned int) green_;
}

unsigned int Color::blue (void) const
{
	return (unsigned int) blue_;
}

unsigned int Color::alpha (void) const
{
	return (unsigned int) alpha_;
}

const Color & Color::operator = (const Color & rhs)
{
	if ( &rhs != &(*this) )
	{
		red_ = rhs.red_;
		green_ = rhs.green_;
		blue_ = rhs.blue_;
	}

	return *this;	
}

Color Color::make (int r, int g, int b, int a)
{
	Color color1(r, g, b, a);
	return color1;
}
