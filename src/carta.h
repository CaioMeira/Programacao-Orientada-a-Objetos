#ifndef CARTA_H
#define CARTA_H

#include <QString>

class Carta
{

public:

    Carta(int VALOR, int NAIPE);


    int GetValor();
    int GetNaipe();
    int GetFaceValue();

    void Print();

    QString CurrentPath();


private:
    int _valor;
    int _naipe;
    QString _naipeCode;



};

#endif // CARTA_H
