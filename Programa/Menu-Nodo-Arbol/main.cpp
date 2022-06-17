/*
	Universidad de las Fuerzas Armadas "ESPE"
	Proceso Postfijo
	Arias Sebastián, Escobar David, Portilla Diego, Ramírez Erick, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 15/06/2022
	Fecha de modificación: 16/06/2022
	Grupo 2
	Grupo 5
	Grupo 9
	https://github.com/DarwinValdiviezo/Polaca-Inversa
	
*/
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "postfija.h"
#include "postfija.cpp"
#include "infija.h"
#include "infija.cpp"
#include "Menu.h"
#include "Menu.cpp"
#include "Arbol.h"
#include "Arbol.cpp"
#include "props.h"
#include "props.cpp"


using namespace std;


void format_input(string input, string &output);

int main(){
	Menu menu;
	int option, opcion;	
	Arbol bArbol();
	string in, out, expression;
	char *infix; 	
	char *postfix;
	double x = 0;


	do {
		option = menu.makeMenu(4,"Ingresar Expresion","Expresion Ingresada","Expresion en Postfija", "Salir");
		system("cls");
		switch (option) {
		case 1:{
			Console screen;
			screen.hideCursor(true);
			in = "";
			expression = "";
			x = 0;
			infix,postfix = NULL;
			cout << "\t\tCalculadora Polaca "<<endl;
			cout << "Ingrese la expresion-> ";
			getline(cin, in);
			format_input(in, expression);
			cout << endl; //
			out.resize(expression.length() * 100);
			infix = &expression[0];
			postfix = &out[0];
			infix2postfix(infix, postfix);
			cout << "Transformado a Prefijo -> ";
			x = eval_postfix(postfix);
			cout << endl;
			cout << "Resultado de la expresion : " << x << endl;
			system("pause");
			break;


		}
		case 2:{
			cout << "\nExpresion Ingresada: " << infix << endl;
			system("pause");
			break;
		}
		case 3:{
			infix2postfix(infix, postfix);
			cout << "\nExpresion en Posfija: " <<  out << endl;
			system("pause");
			break;
		}
		case 4:{
			cout << "Saliendo....." << endl;
			cout << endl;
			system("pause");
			exit(1);
		}
		break;

	}


	}while (option != 4);

	

	return EXIT_SUCCESS;
}

// s = seno
// c = coseno
// t = tangente
// e = secante
// x = cosecante
// z = cotangente



void format_input(string input, string &output){
	for(unsigned int i = 0; i < input.length(); i++){
		if(input[i] != ' '){
            if(input[i] == '^' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '+'|| input[i] == '>'|| input[i] == '<'|| input[i] == '='|| input[i] == '!'|| input[i] == 's'|| input[i] == 'c'|| input[i] == 't'|| input[i] == 'e'|| input[i] == 'x'|| input[i] == 'g'|| input[i] == 'p'){
				output.push_back(' ');
				output.push_back(input[i]);
				output.push_back(' ');
			}
			else if(input[i] == '-'){
				if((i != 0) && (*output.rbegin() != 's' && *output.rbegin() != 'c' && *output.rbegin() != 't' && *output.rbegin() != 'e' && *output.rbegin() != 'x' && *output.rbegin() != 'g' && *output.rbegin() != 'p' && *output.rbegin() != '(' && *output.rbegin() != ' '&& *output.rbegin() != '^' && *output.rbegin() != '*' && *output.rbegin() != '/' && *output.rbegin() != '%' && *output.rbegin() != '+' && *output.rbegin() != '-'&& *output.rbegin() != '>'&& *output.rbegin() != '<'&& *output.rbegin() != '='&& *output.rbegin() != '!')){
					output.push_back(' ');
					output.push_back(input[i]);
					output.push_back(' ');
				}
				else{
					output.push_back(input[i]);
				}	
			}
			else if(input[i] == '('){
				output.push_back(input[i]);
				output.push_back(' ');
			}
			else if(input[i] == ')'){
				output.push_back(' ');
				output.push_back(input[i]);
			}
			else
			{
				output.push_back(input[i]);
			}
		}
	}
}