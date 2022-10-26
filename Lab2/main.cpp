#include <iostream>
#include "Rational.hpp"

int main(void)
{
	try{
		Rational num1 {2,10};
		Rational num2 {1,5};
		
		std::cout << "sum " << num1+num2 << std::endl;
		std::cout << "dif " << num1-num2 << std::endl;
		std::cout << "mul " << num1*num2 << std::endl;
		std::cout << "div " << num1/num2 << std::endl;
	
		std::cout << "sum int " << num1+5<< std::endl;
	
		std::cout << "to double " << num1.to_double();
		
		if(num1<num2)std::cout << "n1 < n2" << std::endl;
		if(num1>num2)std::cout << "n1 > n2" << std::endl;
		if(num1==num2)std::cout << "n1 == n2" << std::endl;	
	
		num1 = num2;
		std::cout << "= " << num1;
	
	}catch(DenException e){
		std::cout << e.text();
	}
	
	return 0;
}
