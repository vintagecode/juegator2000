//---------------------------------------------------------------------------

#ifndef JugadorConzC4H
#define JugadorConzC4H

#include "Jugador.h"
#include "JuegoC4.h"
//---------------------------------------------------------------------------
typedef int (*FunHeuristicaC4)(const JuegoC4& EC);

class JugadorConzC4 : protected Jugador
{
        protected:
                FunHeuristicaC4 heuristica;
        public:

                static int HeuristicaDef(const Juego2JTab *EJ);
                JugadorConzC4(int n, FunHeuristicaC4 HeuristicaDef/*implementar y declarar HeuristicaDef*/);
                ~JugadorConzC4();

                //métodos
                virtual Casilla juega(const Juego2JTab EJ);
};
#endif
