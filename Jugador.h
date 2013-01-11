//---------------------------------------------------------------------------

#ifndef JugadorH
#define JugadorH

#include "Juego2JTab.h"
//---------------------------------------------------------------------------
class EJugador{
};

class Jugador//no estoy seguro de si hereda o no :S
{
        protected:
                int nivel;
                //FunHeuristicaC4 heuristica/*Valora un tablero cuanto mas
                //alto es el nivel que devuelve mejor heuristica*/
                //typedef int(*FunHeuristicaC4)(const JuegoC4 J);
        public:
                //constructora
                Jugador();

                //destructora
               virtual ~Jugador(){};

               //métodos
               virtual Casilla juega(const Juego2JTab& EJ)const{}; /*throw(EJugador)*/

};
#endif

