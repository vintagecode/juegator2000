//---------------------------------------------------------------------------

#ifndef Juego2JTabH
#define Juego2JTabH

#include <fstream>
#include "UtMatriz.h"
//---------------------------------------------------------------------------
using namespace std;

enum Turno{Jn, Ja, Jb, Jc};
typedef Turno Ficha;

typedef tMatriz<Ficha> Tablero;

struct Casilla
{
        int nFila;
        int nColumna;
        Casilla(int c = 0,int f = 0){nFila = f;nColumna = c;};
};//hay por ahi un Casilla(int c= 0;int f = 0)

class EJuego{

};

class Juego2JTab
{
        protected:
                bool hayGanador;
                Turno turno;
                Tablero* tablero;
                bool humanos;

        public:
                //constructoras
                Juego2JTab();
                Juego2JTab(Juego2JTab &J);

                //destructora
                virtual ~Juego2JTab();
                
                //accesoras
                Turno& dameTurno()
                {
                        return turno;
                };
                dameDimensionTablero(){};

                //m�todos
                int numCol(){return tablero->dameColumnas();};
                int numFil(){return tablero->dameFilas();};
                virtual void reinicia(Turno turno){};
                virtual void aplicaJugada(unsigned int c, unsigned int f)/* throw(EJuego)=0*/{};
                void aplicaJugada(Casilla cf) /*throw(EJuego)*/;
                virtual bool sePuede(unsigned int c, unsigned int f) const /*throw()=0*/{};
                bool sePuede(Casilla cf) const /*throw()*/;
                virtual bool fin() const /*throw()=0*/{};
                virtual Juego2JTab* clona(){};
                virtual Turno dameGanador() const /*throw()*/{};
                bool final() const{return hayGanador;}/* throw()*/;
                void ponGanador() {hayGanador = true;};
                Turno valorCasilla(Casilla cf) const;
                virtual Turno valorCasilla(unsigned int c, unsigned int f) const{};
                void cambiaTurno();
                void cambiaHumanos()
                {
                        if(humanos == true)humanos = false;
                        if(humanos == false)humanos = true;
                };
                bool hayHumanos() {return humanos;};
                virtual void pasar(){};
                virtual bool salvar(ofstream &sal) const;
                virtual bool cargar(ifstream &ent);
                virtual bool sePuedeAlguna(Casilla &cf){};
};
#endif
