#include <iostream>
#include "Pila.h"

using namespace std;


class Notaciones{
    private:
        string expresion;
        Pila<char> operadores;
        Pila<char> salida;
        Pila<char> entrada;
    public:
        Notaciones() = default;
        //GRUPO2
        void ingresarExpresion(string _expresion);
        //GRUPO9
		string convertirPostfija();
        //GRUPO5
		string convertirPrefija();
		//GRUPO2
        int verificarJerarquia(char operador);
        //GRUPO2
		bool comprobarSigno(char temporal);
        //GRUPO2
		bool compararFunciones(int j);
        //GRUPO2
		bool compararFun(int i);
		//GRUPO2
        string compararSigno(char temporal);

};
