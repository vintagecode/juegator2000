//---------------------------------------------------------------------------

#ifndef JuegoC4H
#define JuegoC4H
#include "Juego2JTab.h"
//---------------------------------------------------------------------------
class JuegoC4 : public Juego2JTab
{
        protected:
                int libres; //indica cu�ntas casillas quedan libres

        public:
                //constructoras
                JuegoC4();
                JuegoC4(Turno &t, bool b);
                JuegoC4(JuegoC4 &J);

                //destructoras
                ~JuegoC4();

                //inventado
                virtual void reinicia(Turno turno);
                virtual void aplicaJugada(unsigned int c, unsigned int f)/* throw(EJuego)=0*/;
                virtual bool sePuede(unsigned int c, unsigned int f) const /*throw()=0*/;
                virtual bool fin() const /*throw()=0*/;
                virtual Juego2JTab* clona();
                virtual Turno dameGanador() const /*throw()*/;
                virtual Turno valorCasilla(unsigned int c, unsigned int f)const;
                virtual bool salvar(ofstream &sal) const;
                virtual bool cargar(ifstream &ent);
};
#endif
