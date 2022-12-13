#include "deck.h"


Deck::Deck()
{
    std::srand(unsigned(std::time(0)));
}

Deck::~Deck()
{
    for(Carta* carta : _cartas)
    {
        delete carta;
    }
    _cartas.clear();
}

void Deck::adicionaCarta(Carta *carta)
{
    _cartas.push_back(carta);
}

unsigned int Deck::size()
{
    return _cartas.size();
}

Carta *Deck::retiraCarta()
{
    Carta * carta = _cartas.back();
    _cartas.pop_back();
    return carta;
}

int Deck::Points()
{
    int aces = 0;
    int points = 0;

    for(unsigned int i = 0; i < _cartas.size(); i++)
    {
        if(_cartas[i]->GetValor() == 11)
            aces++;
        points += _cartas[i]->GetFaceValue();
    }

    if(points > 21)
    {
        while(aces-- && points > 21)
        {
            points -= 10;
        }
    }

    return points;

}

void Deck::shuffle()
{
    random_shuffle(_cartas.begin(),_cartas.end(), rnd);
}

int Deck::rnd(int i)
{
    return rand()%i;
}

void Deck::print_cartas()
{
    for(unsigned int i = 0; i < _cartas.size(); i++)
    {
        _cartas[i]->Print();
        cout << endl;
    }

}

QString Deck::GetPath(unsigned int Index)
{
   QString thePath = _cartas[Index]->CurrentPath();
   //QString thePath = "1O";
   return thePath;
}




