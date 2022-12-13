#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include "deck.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TelaPrincipal; }
QT_END_NAMESPACE

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    TelaPrincipal(QWidget *parent = nullptr);
    ~TelaPrincipal();

    void ChangeCardsFace();

private slots:
    void on_Buy_Button_clicked();

    void on_Close_Button_clicked();

    void on_Hit_Button_clicked();

    void on_Bet10_Button_clicked();

    void on_Bet100_Button_clicked();

    void on_Bet1000_Button_clicked();

    void on_Play_Button_clicked();

    void on_Reset_Button_clicked();

    void on_Next_Button_clicked();

private:
    Ui::TelaPrincipal *ui;

    Deck baralho;
    Deck mao_jogador;
    Deck mao_dealer;

    int playerBank;
    int dealerBank;
    int tableBank;
    int playerPoints;
    int dealerPoints;
};
#endif // TELAPRINCIPAL_H
