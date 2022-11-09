#include "Link.h"

int main(void) {

	Link* head = new Link("head");

	head->add(new Link("d1"));
	head->insert(new Link("s1"));
	head->add(new Link("d2"));
	head->insert(new Link("s2"));
	head->add(new Link("d3"));
	head->insert(new Link("s3"));
	head->add(new Link("d4"));
	head->insert(new Link("s4"));

	head->print_all();
	
	head->push_back(new Link("d200"));
	head->push_front(new Link("s200"));
	head->next()->erase();

	head->print_all();

	std::cout << head->find("s2")->getValue() << std::endl;

	head->pop_back();
	head->pop_front();

	head->print_all();

	return 0;
}