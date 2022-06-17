/*
	Universidad de las Fuerzas Armadas "ESPE"
	Proceso transformacion infijo y postifijo
	Arias Sebastián, Escobar David, Portilla Diego, Ramírez Erick, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 15/06/2022
	Fecha de modificación: 16/06/2022
	Grupo 2
	Grupo 5
	Grupo 9
	https://github.com/DarwinValdiviezo/Polaca-Inversa	
*/

#ifndef INFIX_H
#define INFIX_H

#include "Pila.h"
int precedence(char x);
void infix2postfix(char* infix, char* postfix);

#endif
