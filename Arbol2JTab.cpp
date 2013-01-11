//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Arbol2JTab.h"
//---------------------------------------------------------------------------
Arbol2JTab::Arbol2JTab(const Juego2JTab& EJ, int nivel, FunHeuristica2JTab HeuristicaDef)
{
        FH = HeuristicaDef;
        arbol = new ArbolJ(dato2JTab(EJ.clona()));
        generaArbol(arbol, nivel);
};
//---------------------------------------------------------------------------
Arbol2JTab::~Arbol2JTab()
{

}
//---------------------------------------------------------------------------
int Arbol2JTab::buscaMiniMax()
{

}
//---------------------------------------------------------------------------
Casilla Arbol2JTab::buscaMejorJugada()//throw(EJugador)
{
        //if(arbol->esHoja()) throw EJugador();
        //else
        //{
                int mejorC = -1;
                int mejorV = INT_MIN;
                int c, v;
                int n = arbol->numHijos();
                for(c = 0; c < n; c++)
                {
                        v = buscaMiniMax(arbol->getHijo(c));
                        if(v > mejorV)
                        {
                                mejorV = v;
                                mejorC = c;
                        }
                }
                return arbol->getHijo(mejorC)->getDato().jugada;
        //}
}
//---------------------------------------------------------------------------
int Arbol2JTab::buscaMiniMax(ArbolJ* arbol) const //throw(EJ)
{

}
//---------------------------------------------------------------------------
void Arbol2JTab::generaArbol(ArbolJ* arbol, int nivel) const //throw(E)
{
        if((nivel > 0) && !(arbol->getDato().juego->final()))
        {
                for(int c = 0; c < arbol->getDato().juego->numCol(); c++)
                {
                        for(int f = 0; f < arbol->getDato().juego->numFil(); f++)
                        {
                                if(arbol->getDato().juego->sePuede(c, f))
                                {
                                        Juego2JTab* sigEstado = arbol->getDato().juego->clona();
                                        sigEstado->aplicaJugada(c, f);
                                        Arbol<dato2JTab>* x = new Arbol<dato2JTab>(dato2JTab(sigEstado, Casilla(c, f)));
                                        arbol->addHijo(x/*dato2JTab(sigEstado, Casilla(c, f))*/);
                                        generaArbol(arbol->getHijo(arbol->numHijos()), nivel-1);
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------
void Arbol2JTab::liberaArbol(ArbolJ* arbol)
{

}
//---------------------------------------------------------------------------
#pragma package(smart_init)
 