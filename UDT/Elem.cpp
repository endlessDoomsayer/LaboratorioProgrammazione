#include "Elem.hpp"

Elem::Elem(std::string name, Elem* prec, Elem* succ)
	: name{name}, prec{prec}, succ{succ}
{
}

Elem::~Elem()
{
	Elem* curr = this;
	curr = removeNext(curr);
	curr = removePrev(curr);
	delete this;
}

Elem* Elem::removeNext(Elem* elem){
	if(elem->next()) elem = removeNext(elem->next());
	Elem* curr = elem->prev();
	delete elem;
	return curr;
}

Elem* Elem::removePrev(Elem* elem){
	if(elem->prev()) removePrev(elem->prev());
	Elem* curr = elem->next();
	delete elem;
	return curr;
}

Elem* Elem::insSucc(Elem* n) {
	
	if(this->succ) this->succ->prec = n;
	n->succ = this->succ;
	this->succ = n;
	n->prec = this;
	
	return n;
}

Elem* Elem::insPrec(Elem* n) {
	
	if(this->prec) this->prec->succ = n;
	n->prec = this->prec;
	this->prec = n;
	n->succ = this;
	
	return n;
}

std::string Elem::erase() {
	
	if(this->succ) this->succ->prec = this->prec;
	if(this->prec) this->prec->succ = this->succ;
	
	std::string name = this->name;
	
	delete this;
	return name;
}

Elem* Elem::find(const std::string& name) {
	return (this->name == name) ? this : nullptr;
}

Elem* Elem::advance(int n) const {
	
	Elem* curr = nullptr;
	
	if(this){
		if(n>0){
			curr = this->next();
			for(int i=1; curr->next() && i<n; i++){
				curr = curr->next();
			}
		}
		else{
			curr = this->prev();
			for(int i=-1; curr->prev() && i>n; i--){
				curr = curr->prev();
			}
		}
	}
	return curr;
}

Elem* Elem::find(Elem* elem, const std::string& name) {
	
	Elem* found = nullptr;
	Elem* start = elem;
	
	while(!found && elem){
		if(elem->find(name)) found = elem;
		else elem = elem->next();
	}
	
	if(!found){
		elem = start;
		while(!found && elem){
			if(elem->find(name)) found = elem;
			else elem = elem->prev();
		}
	}
	
	return found;
}

std::ostream& operator<<(std::ostream& os, const Elem& el){
	os << el.getName();
	return os;
}