#include <iostream>
#include <vector>

void print(std::string output,const std::vector<int>& v);
void fibonacci(int x, int y, std::vector<int>& v, int n);
void maxIntFib(int x, int y, std::vector<int>& v);
void call_counter(void);

int main(void){
	
	std::vector<int> v;

	fibonacci(1,2,v,10);
	print("fibonacci 10 elementi" , v);
	
	maxIntFib(1,2,v);
	//1836311903 è la più vicina approssimazione del numero intero massimo rappresentabile usando la funzione fibonacci
	
	print("fibonacci approssimazione int:", v);	
	
	std::cout << "funzione conta chiamate: ";
	call_counter();
	call_counter();
	call_counter();
	call_counter();
	call_counter();
	
	
	return 0;
}

void print(std::string output,const std::vector<int>& v){
	
	std::cout << output;
	//i indice unsigned perchè 1)è solo positivo e 2)non ci sono warning nel comparare i con v.size()
	for(unsigned int i = 0; i < v.size(); i++){
		std::cout << " " << std::to_string(v[i]);
													//ho usato la funzione std::to_string() perchè scrivere direttamente 
													//la concatenazione faceva sorgere problemi di compatibilità dei tipi
	}
	std::cout << std::endl;
}

void fibonacci(int x, int y, std::vector<int>& v, int n){
	//assumo che v sia vuoto, se non lo è lo svuoto
	v.clear();
	
	//inserisco i primi due elementi, restano da calcolare n-2 elementi
	v.push_back(x);
	v.push_back(y);
	
	for(int i=2; i < n; i++){		//parto dall'indice 2 in quanto 0 e 1 sono già stati usati
		v.push_back(v[i-2]+v[i-1]);	//usando la formula di fibonacci aggiungo un elemento come somma dei precedenti due
	}
	
}

void maxIntFib(int x, int y, std::vector<int>& v){
	//assumo che v sia vuoto, se non lo è lo svuoto
	v.clear();
	//inserisco i primi due elementi
	v.push_back(x);
	v.push_back(y);
	
	int fib=1, i=2;		//setto fibonacci a 1 (semplicemente per entrare nel while, avrei potuto usare un do while o un >=)
	while(fib > 0){		
		fib = v[i-2]+v[i-1];
		if(fib > 0){			//se fib < 0 allora c'è stato un overflow nella somma dei due elementi di v,
								//quindi si va a modificare il bit di segno che fa diventare il numero negativo,
								//ecco perchè nel while la condizione è fib>0
			v.push_back(fib);
			i++;
		}
	}
}

void call_counter(void){
	
	//per tenere conto del numero di chiamate di questa funzione bisogna usare una variabile statica; lo scope è interno a questa funzione
	//in quanto la variabile interessa solo qui
	static int call = 0;
	
	call++;
	std::cout << call;
}