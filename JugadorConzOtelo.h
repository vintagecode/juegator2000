//---------------------------------------------------------------------------

#ifndef JugadorConzOteloH
#define JugadorConzOteloH

#include "Jugador.h"
#include "JuegoOtelo.h"
//---------------------------------------------------------------------------
typedef int (*FunHeuristicaOtelo)(const JuegoOtelo& EC);

class JugadorConzOtelo : protected Jugador
{
        protected:

        public:
                JugadorConzOtelo(/*int n=2,FunHeuristicaOtelo f = HeuristicaDef/*implementar y declarar HeuristicaDef*/);
                ~JugadorConzOtelo();

                //métodos
                juega(const Juego2JTab EJ);
};
#endif
