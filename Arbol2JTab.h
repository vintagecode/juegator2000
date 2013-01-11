//---------------------------------------------------------------------------

#ifndef Arbol2JTabH
#define Arbol2JTabH

#include "Arbol.h"
#include "Juego2JTab.h"
//---------------------------------------------------------------------------
struct dato2JTab
{
        Juego2JTab* juego;
        Casilla jugada;
        dato2JTab(Juego2JTab* jg = NULL, Casilla cf = Casilla())
        {
                juego = jg;
                jugada =cf;
        }
};

typedef Arbol<dato2JTab> ArbolJ;

typedef int (*FunHeuristica2JTab)(const Juego2JTab& EC);

class EJugador{
};

class Arbol2JTab
{
        protected:
                Juego2JTab* juego;
                Casilla jugada;
                ArbolJ* arbol;
                int nivel;
                FunHeuristica2JTab FH;
                int buscaMiniMax(ArbolJ* arbol) const; //throw(EJ);
                void generaArbol(ArbolJ* arbol, int nivel) const; //throw(E)
                void liberaArbol(ArbolJ* arbol);
        public:
                //métodos
                Arbol2JTab(const Juego2JTab& EJ, int nivel, FunHeuristica2JTab HeuristicaDef);
                ~Arbol2JTab();
                int buscaMiniMax();
                Casilla buscaMejorJugada();//throw(EJugador);
};
#endif
