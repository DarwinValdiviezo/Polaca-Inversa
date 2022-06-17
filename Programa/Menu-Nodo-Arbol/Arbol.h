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
#include <string>
#if !defined(__ArbolesBinarios_Arbol_h)
#define __ArbolesBinarios_Arbol_h

typedef std::string T;

#include "Nodo.h"
#include "Nodo.cpp"

class Arbol
{
public:
	Arbol();
   	void insertar(T);
   	void insertar(Nodo * , T);
   	bool vacio();
   	Nodo* getRaiz(void);
   	void setRaiz(Nodo* newRaiz);
   	void inorder(Nodo* nodo);
	void eliminar(Nodo * nodo, T );
	
private:
   Nodo * raiz;


};

#endif
