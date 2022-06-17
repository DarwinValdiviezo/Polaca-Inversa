//Universidad de las Fuerzas Armadas ESPE
//Estructura de Datos
//Nodo.h
//Autor: Diego Portilla
//Fecha: 16/6/2022
//Descripcion: Este archivo contiene la definicion de la clase Nodo
//
#if !defined(__ArbolesBinarios_Nodo_h)
#define __ArbolesBinarios_Nodo_h


#include <string>

typedef std::string T;
class Nodo
{
	
public:
   T getDato(void) const;
   void setDato(T newDato);
   Nodo* getIzq(void) const;
   void setIzq(Nodo* newIzq);
   Nodo* getDer(void) const;
   void setDer(Nodo* newDer);
   Nodo(T);
   ~Nodo();
     
private:
   	T dato;
	   Nodo* izq;
   	Nodo* der;

};

#endif
