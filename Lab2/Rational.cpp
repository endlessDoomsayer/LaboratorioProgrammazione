#include "Rational.hpp"

Rational::Rational(const int num, const int den)
{
	this->num = num;
	if(den) this->den = den;
	else throw DenException("den = 0\n");
}

Rational::~Rational()
{
}

Rational& Rational::operator=(const Rational& r){
	if(this != &r){
		this->num = r.num;
		this->den = r.den;
	}
	return *this;
}

Rational Rational::operator+(const Rational& r){
	int newden = this->findMCM(r);
	
	int newnum = newden/this->den * this->num + newden/r.den * r.num;
	
	return Rational(newnum, newden);
}

Rational operator+(const int& n, const Rational& r){
	int newnum = r.num + n*r.den;
	return Rational(newnum, r.den);
}

Rational Rational::operator-(const Rational& r){
	int newden = this->findMCM(r);
	
	int newnum = newden/this->den * this->num - newden/r.den * r.num;
	
	return Rational(newnum, newden);
}

Rational Rational::operator*(const Rational& r){
	
	return Rational(this->num * r.num, this->den * r.den);
}

Rational Rational::operator/(const Rational& r){
	
	return Rational(this->num * r.den, this->den * r.num);
}

bool Rational::operator<(const Rational& r){
	int mcm = this->findMCM(r);
	
	if((mcm/this->den * this->num) < (mcm/r.den * r.num))
		return true;
	return false;
}

bool Rational::operator>(const Rational& r){
	int mcm = this->findMCM(r);
	
	if((mcm/this->den * this->num) > (mcm/r.den * r.num))
		return true;
	return false;
}

bool Rational::operator==(const Rational& r){
	if(*this > r || *this < r)
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Rational& r){
	os << r.num << "/" << r.den;
	return os;
}

double Rational::to_double(){
	return (static_cast<double>(this->num)/this->den);
}

int Rational::findMCM(const Rational& r){
	int mcm = this->den;
	
	while((mcm%this->den)!=0 || (mcm%r.den)!=0){
		mcm+=this->den;
	}
	
	return mcm;
}