//---------------------------------------------------------------------------

#ifndef JugadorConz3RayaH
#define JugadorConz3RayaH
#include "Jugador.h"
#include "Juego3Raya.h"
//---------------------------------------------------------------------------
typedef int (*FunHeuristica3Raya)(const Juego3Raya& EC);

class JugadorConz3Raya : protected Jugador
{
        protected:

        public:
                JugadorConz3Raya(/*int n=2,FunHeuristica3Raya f = HeuristicaDef/*implementar y declarar HeuristicaDef*/);
                ~JugadorConz3Raya();

                //métodos
                juega(const Juego2JTab EJ) /*cast throw*/;
};
#endif
 