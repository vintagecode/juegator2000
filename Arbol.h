#ifndef UArbolH
#define UArbolH
#include "UtLista.h"
#include "Excepciones.h"


template <class T> class Arbol
{
	protected:
		T dato;
		tLista<Arbol<T>*>* hijos;
                virtual ~Arbol()
                {
                        Arbol<dato2JTab>* x = new Arbol<dato2JTab>(dato2JTab(dato));
                        borraDato(x);
                        //for(int i = 0;i < hijos.dameNumElem();i++)
                        delete hijos;
                }

	//metodos
	public:
		Arbol(const T& d)
		{
			dato = d;
		};
		int numHijos() const throw()
		{
			return hijos->size();
		};    
		virtual bool esHoja() const throw()
		{
			return (hijos->size()==0);
		};
		const T& getDato() const throw()
		{
			return dato;
		};
		Arbol* getHijo(int i) const throw(ErrRango)
		{
			return hijos->at(i);
		};
		void addHijo(Arbol* a) throw(bad_alloc)
		{
			hijos->insert(hijos->size(),a);
		};
		iniciaDato(Arbol<T>* & a)
		{ 
			a = new Arbol<T>();
		};
		void borraDato(Arbol<T>* & a)
		{
			delete a;//Arbol<T>();
		};
		void asignaDato(Arbol<T>* & a1, const Arbol<T>* & a2)
		{
			a1 = a2;
		};
		bool guardaDato(ofstream &sal,const Arbol<T>* & a)
		{
			//ñaa
			return true;
		};
		bool cargaDato(ifstream &ent, Arbol<T>* & a)
		{
			//ñaa
			return true;
		};
};
#endif
