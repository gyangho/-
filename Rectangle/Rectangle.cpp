#include "Rectangle.h"

Rectangle::Rectangle()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}
Rectangle::~Rectangle()
{

}

ostream& operator << (ostream& os, Rectangle& r)
{
	os << "X: " << r.x << " Y: " << r.y << " WIDTH: " << r.width << " HEIGHT: " << r.height << endl;
	
	return os;
}
Rectangle Rectangle::operator+(Rectangle& r)
{
	Rectangle result;

	if (x < r.x)
	{
		result.x = x;
		result.width = (r.x + r.width - x);
	}
	else
	{
		result.x = r.x;
		result.width = (x + width - r.x);
	}

	if (y < r.x)
	{
		result.y = y;
		result.height = (r.y + r.height - y);
	}
	else
	{
		result.y = r.y;
		result.height = (y + height - r.y);
	}

	return result;
}
Rectangle Rectangle::operator / (Rectangle& r)
{
	Rectangle result;

	if (x < r.x)
	{
		result.x = r.x;
		if (x + width < r.x)
			result.width = 0;
		else
			result.width = x + width - r.x;
	}
	else
	{
		result.x = x;
		if (r.x + r.width < x)
			result.width = 0;
		else
			result.width = r.x + r.width - x;
	}
	if (y < r.y)
	{
		result.y = r.y;
		if (y + height < r.y)
			result.height = 0;
		else
			result.height = y + height - r.y;
	}
	else
	{
		result.y = y;
		if (r.y + r.height < y)
			result.height = 0;
		else
			result.height = r.y + r.height - y;
	}
	return result;
}
bool Rectangle::operator==(const Rectangle& s)
{
	if (this == &s)
		return true;
	if ((x == s.x) && (y == s.y) && (height == s.height) && (width == s.width))
		return true;
	else 
		return false;
}
void Rectangle::read()
{
	cout << "INPUT X Y: ";
	cin >> x;
	cin >> y;
	cout << "INPUT WIDTH: ";
	cin >> width;
	cout << "INPUT HEIGHT: ";
	cin >> height;
}
void Rectangle::getArea()
{
	cout << "AREA: "<< width*height << endl;
}