/*
	Universidad de las Fuerzas Armadas "ESPE"
	Ejemplo de Pilas con memoria dinamica
	Arias Sebastián, Escobar David, Portilla Diego, Ramírez Erick, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 15/06/2022
	Fecha de modificación: 16/06/2022
	Grupo 2
	Grupo 5
	Grupo 9
	https://github.com/ErickRamirezO/Trabajos-Grupo-9
	https://github.com/DarwinValdiviezo/Polaca-Inversa
	
*/

#pragma once
#include "Pila.h"
#include "postfija.h"
#include "Arbol.h"

float eval_postfix(char* postfix){
    stack<string> operands; 
    istringstream stin;
    float evaluated;
    string character;	
    string expression(postfix); 
    stin.str(expression);
	Arbol bTree;	

    while(stin >> character){
        if(character == "+" || character == "-" || character == "*" || character == "/" || character == "^"|| character == ">" || character == "<"||character == "=" || character == "!"|| character == "s"|| character == "c"|| character == "t"|| character == "e"|| character == "x"|| character == "g" || character == "p"){
		bTree.insertar(character);
            	compute(character, operands);
        }
        else{
		bTree.insertar(character);
            	operands.push(character);
        }
    }
    evaluated = atof(operands.topAndPop().c_str());
	bTree.inorder(bTree.getRaiz());
    return evaluated;
}

void compute(string operation, stack<string>& operands){
    
    float first, second, solved;
    bool solution;
    second = atof(operands.topAndPop().c_str());
    first = atof(operands.topAndPop().c_str());
    ostringstream output;
    string result;
    
    if(operation == "+"){
        solved = first + second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "-"){
        solved = first - second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "*"){
        solved = first * second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "/"){
        solved = first / second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "^"){
        solved = pow(first, second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "s"){
        solved = sin(first*second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "c"){
        solved = cos(first*second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "t"){
        solved = tan(first*second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "e"){
        solved = 1/(cos(first*second));
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "x"){
        solved = 1/(sin(first*second));
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "g"){
        solved = 1/(tan(first*second));
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "p"){
        solved = 3.141592653589793;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == ">"){
        if(first > second){
            solved = 1;
        }
        else{
            solved = 0;
        }
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "<"){
        if(first < second){
            solved = 1;
        }
        else{
            solved = 0;
        }
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "="){
        if(first == second){
            solved = 1;
        }
        else{
            solved = 0;
        }
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "!"){
        if(first != second){
            solved = 1;
        }
        else{
            solved = 0;
        }
        output << solved;
        result = output.str();
        operands.push(result);
    }
}

