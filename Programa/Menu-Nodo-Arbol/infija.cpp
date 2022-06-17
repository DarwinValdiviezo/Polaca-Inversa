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

#ifndef INFIX_CPP
#define INFIX_CPP

#include "Pila.cpp"
#include "Pila.h"
#include "infija.h"

using namespace std;

void infix2postfix(char* infix, char* postfix){
    stack<char> operators;
    char symbol;
    int i = 0;
    int j = 0;

    while(infix[i]){    
        symbol = infix[i];

        if(symbol && (symbol == '^' || symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'|| symbol == '>'|| symbol == '<'|| symbol == '='|| symbol == '!'|| symbol == 's'|| symbol == 'c'|| symbol == 't'|| symbol == 'e'|| symbol == 'x'|| symbol == 'g'|| symbol == 'p'|| symbol == '(' || symbol == ')')){
            if(symbol == '-' && infix[i + 1] != ' '){
                while(symbol != ' '){
                    postfix[j++] = symbol;
                    i += 1;
                    if(!infix[i]){
                        break;
                    }
                    symbol = infix[i];
                }
                continue;
            }
            else if(operators.isEmpty() || operators.top() == '('){
                operators.push(symbol);
            }
            else if(symbol == '('){
                operators.push(symbol);
            }
            else if(symbol == ')'){
                while(operators.top() != '('){
                    postfix[j++] = ' ';
                    postfix[j++] = operators.topAndPop();
                }
                operators.pop();
            }
            else if(precedence(symbol) > precedence(operators.top())){
                operators.push(symbol);
            }
            else if(precedence(symbol) == precedence(operators.top())){
                if(symbol == 's'|| symbol == 'c'|| symbol == 't'|| symbol == 'e'|| symbol == 'x'|| symbol == 'g'){
                    operators.push(symbol);
                }
                else{
                    postfix[j++] = operators.topAndPop();
                    operators.push(symbol);
                }
            }
            else if(precedence(symbol) < precedence(operators.top())){
                while((operators.isEmpty() != 1) && precedence(symbol) < precedence(operators.top())){
                    postfix[j++] = operators.topAndPop();
                    postfix[j++] = ' '; 
                };
                if(operators.isEmpty() == 1){
                    operators.push(symbol);
                }
                else if(precedence(symbol) > precedence(operators.top())){
                    operators.push(symbol);
                }
                else if(precedence(symbol) == precedence(operators.top())){
                    if(symbol == 's'|| symbol == 'c'|| symbol == 't'|| symbol == 'e'|| symbol == 'x'|| symbol == 'g'){
                        operators.push(symbol);
                    }
                    else{
                        postfix[j++] = operators.topAndPop();
                        operators.push(symbol);
                    }
                }
                else{
                    operators.push(symbol);
                }
            };
        }
        else{
            postfix[j++] = symbol;
        }
        i++;
    };
    while(operators.isEmpty() != 1){
        postfix[j++] = ' ';
        postfix[j++] = operators.topAndPop();
    };
};

int precedence(char symbol){
    int priority;
    if(symbol == 's'|| symbol == 'c'|| symbol == 't'|| symbol == 'e'|| symbol == 'x'|| symbol == 'g'){
        priority = 7;
    }
    if(symbol == '^'){
        priority = 6;
    }
    else if(symbol == '*' || symbol == '/'){
        priority = 5;
    }
    else if(symbol == '+'||symbol == '-'){
        priority = 4;
    }
    else if(symbol == '>' || symbol == '<'|| symbol == '='|| symbol == '!'){
        priority = 3;
    }
    else if(symbol == 'p'){
        priority = 2;
    }
    else{
        priority = 1;
    }
    return priority;
}
#endif
