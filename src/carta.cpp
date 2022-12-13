#include "carta.h"
#include <iostream>
#include <QPixmap>

using namespace std;


Carta::Carta(int VALOR, int NAIPE)
{
    _valor = VALOR;
    _naipe = NAIPE;
    if(NAIPE == 0)
    {
        _naipeCode = "O";
    }
    if(NAIPE == 1)
    {
        _naipeCode = "E";
    }
    if(NAIPE == 2)
    {
        _naipeCode = "C";
    }
    else
        _naipeCode = "P";


}

int Carta::GetValor()
{
    return _valor;
}

int Carta::GetNaipe()
{
    return _naipe;
}

int Carta::GetFaceValue()
{
    if(_valor == 1)
        return 11;
    if(_valor > 10){
        return 10;
    } else {
        return _valor;

    }
}

void Carta::Print()
{

//===== Valor =====

    if(_valor == 1)
    {
        cout << "As";
    }

    else if(_valor == 11)
    {
        cout << "Valete";
    }

    else if(_valor == 12)
    {
        cout << "Dama";
    }

    else if(_valor == 13)
    {
        cout << "Rei";
    }
    else
    {
        cout << _valor;
    }

//===== Naipe =====

    if(_naipe == 0)
    {
        cout << " de ouros";
    }

    else if(_naipe == 1)
    {
        cout << " de espadas";
    }

    else if(_naipe == 2)
    {
        cout << " de copas";
    }

    else
    {
        cout << " de paus";
    }

}

QString Carta::CurrentPath()
{

    return QString::number(_valor) + _naipeCode;
}
