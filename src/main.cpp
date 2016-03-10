#include <iostream>
#include <fstream>

using namespace std;

#include "../aux/parser.hpp"
#include "../aux/stack_template_t.hpp"
#include "../aux/number_t.hpp"

int main(void)
{
	parser_t parser;
	ifstream file ("example.txt");
	parser.read(file);
	parser_item_t* aux;
	stack_template_t<number_t> pila;


	while(!parser.empty()){

		aux = parser.get_element();
		if (aux->get_type() == 1){
			switch (aux->get_id()){
				case 4:
					pila.push(pila.pop() + pila.pop());
					break;
				case 5:
					pila.push(pila.pop() - pila.pop());
					break;
				case 6:
					pila.push(pila.pop() * pila.pop());
					break;
				case 7:
					pila.push(pila.pop() / pila.pop());
					break;
			}
		}
		else{
			if (aux->get_type() == 0){
				switch (aux->get_id()){
					case 0:{
						integer_t a(aux->get_item());
						pila.push(a);
						break;}
					case 1:{
						real_t b(aux->get_item());
						pila.push(b);
						break;}
					case 2:{
						rational_t c(aux->get_item());
						pila.push(c);
						break;}
					case 3:{
						complex_t d(aux->get_item());
						pila.push(d);
						break;}
				}
			}
			else{
				cout << "Ha ocurrido un error"<< endl;
			}
		}
	}
	cout << endl;
	cout << "Resultado" << endl;
	cout << pila.pop() << endl;


}
