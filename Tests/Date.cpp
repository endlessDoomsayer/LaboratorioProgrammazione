#include "Date.hpp"

Date::Date(Day d, Month m, unsigned int y)
	: d{d}, m{m}, y{y}
{
}

Date::~Date()
{
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << date.d << date.m << date.y;
	return os;
}
	
std::ostream& operator<<(std::ostream& os, Day d){
	os << int(d);
	return os;
}

std::ostream& operator<<(std::ostream& os, Month m){
	os << int(m);
	return os;
}

Day operator+(Day& d, int n){
	int r = int(Day::Sunday)%n;
	return d = Day(int(d)+r);
}

Month operator+(Month& m, int n){
	int r = int(Month::Dec)%n;
	return m = Month(int(m)+r);
}