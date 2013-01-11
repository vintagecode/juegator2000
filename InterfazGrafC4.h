//---------------------------------------------------------------------------

#ifndef InterfazGrafC4H
#define InterfazGrafC4H

#include "InterfazGraf2JTab.h"
#include "JuegoC4.h"
#include "Juego2JTab.h"
//---------------------------------------------------------------------------
class InterfazGrafC4 : public InterfazGraf2JTab
{
        private:
                static tBMP fichaA;
                static tBMP fichaB;
                static tBMP fichaN;
                static Graphics::TBitmap *fichas[3];
                static const int ladoCasilla = 50;
                static const int altoTablero = 300; //7 de base y 6 de altura
                static const int anchoGraf = 350;
                static const int altoGraf = 348;
        public:
                InterfazGrafC4(TCanvas *L);
                virtual void muestraEstado(const Juego2JTab &EJ)const;
                virtual unsigned int dameColumna(unsigned int X) /*throw(EInterfaz)=0*/;
                virtual unsigned int dameFila(unsigned int Y) /*throw(EInterfaz)=0*/;
                virtual unsigned int dameAnchoGraf()const;
                virtual unsigned int dameAltoGraf()const;
};
#endif
