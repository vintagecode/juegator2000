//---------------------------------------------------------------------------

#ifndef Juego3RayaH
#define Juego3RayaH
#include "Juego2JTab.h"
//---------------------------------------------------------------------------
class Juego3Raya : public Juego2JTab
{
        protected:
                int libres; //indica cu�ntas casillas quedan libres

        public:
                //constructoras
                Juego3Raya();
                Juego3Raya(Turno &t, bool b);
                Juego3Raya(Juego3Raya &J);

                //destructoras
                ~Juego3Raya();

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
