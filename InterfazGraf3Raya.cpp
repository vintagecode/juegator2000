//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InterfazGraf3Raya.h"

//---------------------------------------------------------------------------
InterfazGraf3Raya::InterfazGraf3Raya(TCanvas *L) : InterfazGraf2JTab()
{
        lienzo = L;
        tBMP ficha3A("ficha3A.bmp");
        tBMP ficha3B("ficha3B.bmp");
        tBMP ficha3N("ficha3N.bmp");
        int X = 0;
        int Y = 0;
        if(L != NULL)
        {
                for(int i = 0;i < 3;i++)
                {
                        X = 0;
                        for(int j = 0; j < 3; j++)
                        {
                                lienzo->Draw(X,Y,ficha3N.BMP());
                                X += ladoCasilla;
                        }
                        Y += ladoCasilla;
                }
                lienzo->Font->Color = clRed;
                lienzo->Font->Height = 20;
                //lienzo->Font->Style = Styles(true, false, false, false);
                lienzo->TextOutA(180,470,"3 en Raya");

        }

};
//---------------------------------------------------------------------------
unsigned int InterfazGraf3Raya::dameColumna(unsigned int X) /*throw(EInterfaz)=0*/
{
        return (X/ladoCasilla);
};
//---------------------------------------------------------------------------
unsigned int InterfazGraf3Raya::dameFila(unsigned int Y) /*throw(EInterfaz)=0*/
{
        return (Y/ladoCasilla);
};
//---------------------------------------------------------------------------
void InterfazGraf3Raya::muestraEstado(const Juego2JTab &EJ)const
{
        tBMP ficha3A("ficha3A.bmp");
        tBMP ficha3B("ficha3B.bmp");
        tBMP ficha3N("ficha3N.bmp");
        Turno aux;
        int  X, Y = 0;
        for(int i = 0;i < 3;i++)
        {
                X = 0;
                for(int j = 0; j < 3; j++)
                {
                        Casilla cf(j, i);
                        aux = EJ.valorCasilla(cf);
                        if (aux == Jn) lienzo->Draw(X,Y,ficha3N.BMP());
                        if (aux == Ja) lienzo->Draw(X,Y,ficha3A.BMP());
                        if (aux == Jb) lienzo->Draw(X,Y,ficha3B.BMP());
                        if (aux == Jc) lienzo->Draw(X,Y,ficha3B.BMP());
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
        lienzo->TextOutA(20,470,"Turno: " + turno); 
        lienzo->TextOutA(180,470,"3 en Raya");
};
#pragma package(smart_init)
