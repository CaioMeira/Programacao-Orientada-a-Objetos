#include "telaprincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{

//    Deck baralho;

//        for(int naipe = 0; naipe <= 3; naipe++)
//        {
//            for(int valor = 1; valor < 14; valor++)
//            {
//                baralho.adicionaCarta(new Carta(valor, naipe));
//                //cout << "naipe =  " << naipe << " , valor = " << valor << endl;
//            }

//        }

//        baralho.shuffle();

    QApplication a(argc, argv);
    TelaPrincipal w;
    w.show();
    return a.exec();
}
