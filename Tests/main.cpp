#include <iostream>
#include "Date.hpp"

int main(void)
{
	//prova dell'ipotesi reference di reference
	std::cout << std::endl << "ref di ref: ";
	int a = 7;
	int& ref = a;
	std::cout  << "a " << a << " ref " << ref;
	ref = 3;
	std::cout << "a " << a << " ref " << ref;
	int& poi = ref;
	poi++;
	std::cout << "a " << a << " ref " << ref << " poi " << poi;
	//la reference di reference si comporta come una reference singola, ovvero se viene modificato poi(reference di reference)
	//viene modificata direttamente la variabile intera a, dunque "poi" non modifica l'indirizzo di "ref"
	
	
	
	Date today = Date(Day::Thursday, Month::Oct, 2022);
	
	std::cout << DateUtils::Days::next(today) << std::endl;
	
	std::cout << DateUtils::Months::next_spec(today, Month(3));
	
	return 0;
}
