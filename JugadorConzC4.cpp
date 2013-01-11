//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JugadorConzC4.h"

//---------------------------------------------------------------------------
JugadorConzC4::JugadorConzC4(int n,FunHeuristicaC4 HeuristicaDef/*implementar y declarar HeuristicaDef*/)
{
        nivel = n;
        heuristica = HeuristicaDef;
};
//---------------------------------------------------------------------------
JugadorConzC4::~JugadorConzC4()
{

};
//---------------------------------------------------------------------------
Casilla JugadorConzC4::juega(const Juego2JTab EJ)
{
        //if(EJ.final()) throw else
        //1.arbol de juego;
        //2.mejor jugada;
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
 