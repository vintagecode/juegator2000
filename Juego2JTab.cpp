//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Juego2JTab.h"
//--------------------------------------------------------------------------
Juego2JTab::Juego2JTab()
{
        hayGanador = false;
        turno = Ja;
        tablero = NULL;
        humanos = false;
};
//---------------------------------------------------------------------------
Juego2JTab::Juego2JTab(Juego2JTab &J)
{
        hayGanador = J.hayGanador;
        turno = J.turno;
        tablero = J.tablero;
        humanos = J.humanos;
};
//---------------------------------------------------------------------------
Juego2JTab::~Juego2JTab()
{
        delete tablero;
        tablero = NULL;
}
//---------------------------------------------------------------------------
void Juego2JTab::aplicaJugada(Casilla cf)
{
        if(sePuede(cf))
        {
                aplicaJugada(cf.nColumna, cf.nFila);
        };
};
//---------------------------------------------------------------------------
bool Juego2JTab::sePuede(Casilla cf) const
{
        if(!sePuede(cf.nColumna, cf.nFila))
        {
                if(turno != Jc)ShowMessage("No puedes muchacho");
                return false;
        }
        return true;
};
//---------------------------------------------------------------------------
Turno Juego2JTab::valorCasilla(Casilla cf) const
{
        return valorCasilla(cf.nColumna, cf.nFila);
};
//---------------------------------------------------------------------------
void Juego2JTab::cambiaTurno()
{
        if((turno == Ja) && hayHumanos())
        {
                turno = Jb;
        }
        else
                if((turno == Jb) && hayHumanos())
                {
                        turno = Ja;
                }
                else
                        if ((turno == Ja) && !hayHumanos())
                        {
                                turno = Jc;
                        }
                        else turno = Ja;
}
//---------------------------------------------------------------------------
bool Juego2JTab::salvar(ofstream &sal) const
{
        sal.write((char*)& hayGanador,sizeof(bool));
        sal.write((char*)& humanos,sizeof(bool));
        //tablero->salvar(sal);
        /*int n;
        if(turno == Ja)
        {
                n = 0;
                sal.write((char*)& n,sizeof(int));
        }
        else if(turno == Jb)
        {
                n = 1;
                sal.write((char*)& n,sizeof(int));
        }
        else if(turno == Jc)
        {
                n = 2;
                sal.write((char*)& n,sizeof(int));
        }*/
        return sal.good();
}
//---------------------------------------------------------------------------
bool Juego2JTab::cargar(ifstream &ent)
{
        ent.read((char*)& hayGanador,sizeof(bool));
        ent.read((char*)& humanos,sizeof(bool));
        //tablero->cargar(ent);
        /*int n;
        ent.read((char*)& n, sizeof(int));
        if (n == 0)
        {
                turno = Ja;
        }
        else if (n == 1)
        {
                turno = Jb;
        }
        else if (n == 2)
        {
                turno = Jc;
        }*/
        return ent.good();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
