//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InterfazGrafC4.h"

//---------------------------------------------------------------------------
InterfazGrafC4::InterfazGrafC4(TCanvas *L) : InterfazGraf2JTab()
{
        lienzo = L;
        tBMP fichaA("fichaA.bmp");
        tBMP fichaB("fichaB.bmp");
        tBMP fichaC("fichaC.bmp");
        tBMP fichaN("fichaN.bmp");
        int X = 0;
        int Y = 0;
        if(L != NULL)
        {
                for(int i = 0;i < 6;i++)
                {
                        X = 0;
                        for(int j = 0; j < 7; j++)
                        {
                                lienzo->Draw(X,Y,fichaN.BMP());
                                X += ladoCasilla;
                        }
                        Y += ladoCasilla;
                }
                lienzo->Font->Color = clRed;
                lienzo->Font->Height = 20;
                //lienzo->Font->Style = Styles(true, false, false, false);
                lienzo->TextOutA(140,320,"Conecta 4");

        }

};
//---------------------------------------------------------------------------
unsigned int InterfazGrafC4::dameColumna(unsigned int X) /*throw(EInterfaz)=0*/
{
        return (X/ladoCasilla);
};
//---------------------------------------------------------------------------
unsigned int InterfazGrafC4::dameFila(unsigned int Y) /*throw(EInterfaz)=0*/
{
        return (Y/ladoCasilla);
};
//---------------------------------------------------------------------------
void InterfazGrafC4::muestraEstado(const Juego2JTab &EJ)const
{
        tBMP fichaA("fichaA.bmp");
        tBMP fichaB("fichaB.bmp"); 
        tBMP fichaC("fichaC.bmp");
        tBMP fichaN("fichaN.bmp");
        Turno aux;
        int  X, Y = 0;
        for(int i = 0;i < 6;i++)
        {
                X = 0;
                for(int j = 0; j < 7; j++)
                {
                        Casilla cf(j, i);
                        aux = EJ.valorCasilla(cf);
                        if (aux == Jn) lienzo->Draw(X,Y,fichaN.BMP());
                        if (aux == Ja) lienzo->Draw(X,Y,fichaA.BMP());
                        if (aux == Jb) lienzo->Draw(X,Y,fichaB.BMP());
                        if (aux == Jc) lienzo->Draw(X,Y,fichaC.BMP());
                        X += ladoCasilla;
                }
                Y += ladoCasilla;
        }
        lienzo->Font->Color = clRed;
        lienzo->Font->Height = 20;
        AnsiString turno;
        if(EJ.dameTurno() == Ja)
        {
                turno = "Mike";
        }
        else    if (EJ.dameTurno() == Jb)
                {
                        turno = "John";
                }
                else turno = "HAL  ";
        lienzo->TextOutA(20,320,"Turno: " + turno);
        lienzo->TextOutA(140,320,"Conecta 4");
};
//---------------------------------------------------------------------------
unsigned int InterfazGrafC4::dameAnchoGraf()const
{

};
//---------------------------------------------------------------------------
unsigned int InterfazGrafC4::dameAltoGraf()const
{

};
//---------------------------------------------------------------------------
#pragma package(smart_init)

