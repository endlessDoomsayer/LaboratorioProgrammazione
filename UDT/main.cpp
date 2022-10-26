#include <iostream>
#include "Elem.hpp"

int main(void)
{
	
	Elem* head = new Elem("testa");
	
	head = head->insSucc(new Elem("vagone1"));
	head = head->insSucc(new Elem("vagone2"));
	head = head->insSucc(new Elem("vagone3"));
	head->insSucc(new Elem("vagone4"));
	
	std::cout << head->advance(4);
	
	Elem* trovato = Elem::find(head, "testa");
	
	std::cout << trovato;
	
	delete head;
	return 0;
}
