#pragma once
#include <iostream>

class Rational
{
public:
	Rational(const int num = 0, const int den = 1);
	~Rational();

	Rational& operator=(const Rational& r);
	
	Rational operator+(const Rational& r);
	
	friend Rational operator+(const int& n, const Rational& r);
	
	Rational operator-(const Rational& r);
	
	Rational operator*(const Rational& r);
	
	Rational operator/(const Rational& r);
	
	bool operator<(const Rational& r);
	
	bool operator>(const Rational& r);
	
	bool operator==(const Rational& r);
	
	friend std::ostream& operator<<(std::ostream& os, const Rational& r);

	double to_double();

private:
	int num, den;

	int findMCM(const Rational& n2);

};

class DenException : public std::exception {
private:
	std::string message;
public:
	DenException(std::string message)
		:message{message}
	{
		
	}
	std::string text(){
		return this->message;
	}
};