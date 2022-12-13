#ifndef DECK_H
#define DECK_H

#include <vector>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

#include "carta.h"


using namespace std;

class Deck
{

public:

    Deck();

    ~Deck(); //Destrutor

    void adicionaCarta(Carta * carta);

    unsigned int size();

    Carta * retiraCarta();

    int Points();

    void shuffle();

    static int rnd(int i);

    void print_cartas();

    QString GetPath(unsigned int Index);

private:

    std::vector<Carta *> _cartas;


};

#endif // DECK_H
