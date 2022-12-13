#include "telaprincipal.h"
#include "ui_telaprincipal.h"
#include <iostream>
#include <QPixmap>
#include <QFont>
#include "deck.h"

using namespace std;


TelaPrincipal::TelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);

    playerBank = 1000;
    dealerBank = 1000;
    tableBank = 0;
    playerPoints = 0;
    dealerPoints = 0;

    for(int naipe = 0; naipe <= 3; naipe++)
    {
        for(int valor = 1; valor < 14; valor++)
        {
            baralho.adicionaCarta(new Carta(valor, naipe));
            //cout << "naipe =  " << naipe << " , valor = " << valor << endl;
        }

    }

    baralho.shuffle();

    QPixmap padrao(":/imagens/Default.png");

    ui->label_dealer1->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer2->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer3->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer4->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer5->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));

    ui->label_player1->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player2->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player3->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player4->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player5->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));

    ui->centralwidget->setStyleSheet("background-color:#050;");

    ui->Play_Button->setStyleSheet("background-color:#fff;color:#000");
    ui->Reset_Button->setStyleSheet("background-color:#fff;color:#000");
    ui->Close_Button->setStyleSheet("background-color:#fff;color:#000");
    ui->Buy_Button->setStyleSheet("background-color:#fff;color:#000");
    ui->Hit_Button->setStyleSheet("background-color:#fff;color:#000");
    ui->Bet1000_Button->setStyleSheet("background-color:#fff;color:#000");
    ui->Bet100_Button->setStyleSheet("background-color:#fff;color:#000");
    ui->Bet10_Button->setStyleSheet("background-color:#fff;color:#000");
    ui->Next_Button->setStyleSheet("background-color:#fff;color:#000");

    ui->plainTextEdit_player->setPlainText(QString("Points: ") + QString::number(playerPoints));
    ui->plainTextEdit_dealer->setPlainText(QString("Points: ") + QString::number(dealerPoints));

    ui->plainTextEdit_playerBank->setPlainText(QString("Dinheiro: ") + QString::number(playerBank));
    ui->plainTextEdit_dealerBank->setPlainText(QString("Dinheiro: ") + QString::number(dealerBank));
    ui->plainTextEdit_tablePot->setPlainText(QString("TablePot: ") + QString::number(tableBank));

    ui->Bet10_Button->setEnabled(false);
    ui->Bet100_Button->setEnabled(false);
    ui->Bet1000_Button->setEnabled(false);
    ui->Next_Button->setEnabled(false);

}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}


void TelaPrincipal::ChangeCardsFace()
{
    for(unsigned int i = 0; i < mao_jogador.size() ; i++)
    {
        //QString path = "1C";
        QString path = mao_jogador.GetPath(i);
        QString fullpath = (":/imagens/" + path + ".png");
        QPixmap CardPlayer(fullpath);
        if(i==0){
            ui->label_player1->setPixmap(CardPlayer.scaled(90,170,Qt::KeepAspectRatio));
        }
        if(i==1){
            ui->label_player2->setPixmap(CardPlayer.scaled(90,170,Qt::KeepAspectRatio));
        }
        if(i==2){
            ui->label_player3->setPixmap(CardPlayer.scaled(90,170,Qt::KeepAspectRatio));
        }
        if(i==3){
            ui->label_player4->setPixmap(CardPlayer.scaled(90,170,Qt::KeepAspectRatio));
        }
        if(i==4){
            ui->label_player5->setPixmap(CardPlayer.scaled(90,170,Qt::KeepAspectRatio));
        }
    }
    for(unsigned int i = 0; i < mao_dealer.size() ; i++)
    {
        //QString path = "1P";
        QString path = mao_dealer.GetPath(i);
        QString fullpath = (":/imagens/" + path + ".png");
        QPixmap CardDealer(fullpath);
        if(i==0)
        {
            cout << "Hidden Card";
        }
        if(i==1)
        {
            ui->label_dealer2->setPixmap(CardDealer.scaled(90,170,Qt::KeepAspectRatio));
        }
        if(i==2){
            ui->label_dealer3->setPixmap(CardDealer.scaled(90,170,Qt::KeepAspectRatio));
        }
        if(i==3){
            ui->label_dealer4->setPixmap(CardDealer.scaled(90,170,Qt::KeepAspectRatio));
        }
        if(i==4){
            ui->label_dealer5->setPixmap(CardDealer.scaled(90,170,Qt::KeepAspectRatio));
        }
    }
}



void TelaPrincipal::on_Buy_Button_clicked()
{
    cout << "Botao BUY apertado" << endl;

    ui->Play_Button->setEnabled(false);
    ui->Bet10_Button->setEnabled(true);
    ui->Bet100_Button->setEnabled(true);
    ui->Bet1000_Button->setEnabled(true);


    mao_jogador.adicionaCarta(baralho.retiraCarta());
    if(mao_dealer.Points()<18){
        mao_dealer.adicionaCarta(baralho.retiraCarta());
    }

    ChangeCardsFace();

    if(mao_jogador.Points() > 20 || mao_dealer.Points() > 20){
        on_Hit_Button_clicked();
    }
    if(mao_jogador.size() > 4 || mao_dealer.size() > 4)
    {
        on_Hit_Button_clicked();
    }
    playerPoints = mao_jogador.Points();
    dealerPoints = mao_dealer.Points();

    ui->plainTextEdit_player->setPlainText(QString("Points: ") + QString::number(playerPoints));



//==============
//    cout << "====================================" << endl;
//    cout << "mao_jogador: " << mao_jogador.Points() << endl;
//    mao_jogador.print_cartas();
//    cout << "====================================" << endl;
//    cout << "mao_dealer: " << mao_dealer.Points() << endl;
//    mao_dealer.print_cartas();
//==============
}

void TelaPrincipal::on_Hit_Button_clicked()
{
    cout << "Botao HIT apertado" << endl;

    ui->Buy_Button->setEnabled(false);
    ui->Bet10_Button->setEnabled(false);
    ui->Bet100_Button->setEnabled(false);
    ui->Bet1000_Button->setEnabled(false);
    ui->Hit_Button->setEnabled(false);
    ui->Next_Button->setEnabled(true);



    if(mao_jogador.Points() == mao_dealer.Points())
    {
        cout << "EMPATE" << endl;
        ui->plainTextEdit_Result->setPlainText((QString("EMPATE!!")));
        playerBank = playerBank + (tableBank/2);
        dealerBank = dealerBank + (tableBank/2);
    }
    else if(mao_jogador.Points() > mao_dealer.Points())
    {
        if(mao_jogador.Points() < 22)
        {
            cout << "VITORIA" << endl;
            ui->plainTextEdit_Result->setPlainText((QString("VITORIA!!")));
            playerBank = playerBank + tableBank;
        }
        else if(mao_jogador.Points() > 21 && mao_dealer.Points() > 21)
        {
            cout << "EMPATE" << endl;
            ui->plainTextEdit_Result->setPlainText((QString("EMPATE!!")));
            playerBank = playerBank + (tableBank/2);
            dealerBank = dealerBank + (tableBank/2);
        }
        else
        {
            cout << "DERROTA" << endl;
            ui->plainTextEdit_Result->setPlainText((QString("DERROTA!!")));
            dealerBank = dealerBank + tableBank;
        }


    }
    else if(mao_dealer.Points() > mao_jogador.Points())
    {
        if(mao_dealer.Points() < 22)
        {
            cout << "DERROTA" << endl;
            ui->plainTextEdit_Result->setPlainText((QString("DERROTA!!")));
            dealerBank = dealerBank + tableBank;
        }
        else if(mao_jogador.Points() > 21 && mao_dealer.Points() > 21)
        {
            cout << "EMPATE" << endl;
            ui->plainTextEdit_Result->setPlainText((QString("EMPATE!!")));
            playerBank = playerBank + (tableBank/2);
            dealerBank = dealerBank + (tableBank/2);
        }
        else
        {
            cout << "VITORIA" << endl;
            ui->plainTextEdit_Result->setPlainText((QString("VITORIA!!")));
            playerBank = playerBank + tableBank;
        }
    }

    ui->plainTextEdit_playerBank->setPlainText(QString("Dinheiro: ") + QString::number(playerBank));
    ui->plainTextEdit_dealerBank->setPlainText(QString("Dinheiro: ") + QString::number(dealerBank));
    ui->plainTextEdit_tablePot->setPlainText(QString("TablePot: ") + QString::number(tableBank));
    ui->plainTextEdit_dealer->setPlainText(QString("Points: ") + QString::number(dealerPoints));

    if(playerBank == 0 || dealerBank == 0)
        ui->Next_Button->setEnabled(false);
    else
        ui->Next_Button->setEnabled(true);

    tableBank = 0;

}

void TelaPrincipal::on_Bet10_Button_clicked()
{
    cout << "Botao BET10 apertado" << endl;

    if(playerBank > 9 && dealerBank > 9)
    {
        tableBank = 20 + tableBank;
        playerBank = playerBank - 10;
        dealerBank = dealerBank - 10;
    }
    else
    {
        cout << "SEM DINHEIRO";
        ui->plainTextEdit_Result->setPlainText((QString("VOCE NAO TEM DINHEIRO PARA ISTO")));
        ui->Bet10_Button->setEnabled(false);
        ui->Bet100_Button->setEnabled(false);
        ui->Bet1000_Button->setEnabled(false);
    }

    ui->plainTextEdit_playerBank->setPlainText(QString("Dinheiro: ") + QString::number(playerBank));
    ui->plainTextEdit_dealerBank->setPlainText(QString("Dinheiro: ") + QString::number(dealerBank));
    ui->plainTextEdit_tablePot->setPlainText(QString("TablePot: ") + QString::number(tableBank));
}


void TelaPrincipal::on_Bet100_Button_clicked()
{
    cout << "Botao BET100 apertado" << endl;

    if(playerBank > 99 && dealerBank > 99)
    {
        tableBank = 200 + tableBank;
        playerBank = playerBank - 100;
        dealerBank = dealerBank - 100;
    }
    else
    {
        cout << "SEM DINHEIRO";
        ui->plainTextEdit_Result->setPlainText((QString("VOCE NAO TEM DINHEIRO PARA ISTO")));
        ui->Bet100_Button->setEnabled(false);
        ui->Bet1000_Button->setEnabled(false);
    }
    ui->plainTextEdit_playerBank->setPlainText(QString("Dinheiro: ") + QString::number(playerBank));
    ui->plainTextEdit_dealerBank->setPlainText(QString("Dinheiro: ") + QString::number(dealerBank));
    ui->plainTextEdit_tablePot->setPlainText(QString("TablePot: ") + QString::number(tableBank));
}


void TelaPrincipal::on_Bet1000_Button_clicked()
{
    cout << "Botao BET1000 apertado" << endl;

    if(playerBank > 999 && dealerBank > 999)
    {
        tableBank = 2000 + tableBank;
        playerBank = playerBank - 1000;
        dealerBank = dealerBank - 1000;
    }
    else
    {
        cout << "SEM DINHEIRO";
        ui->plainTextEdit_Result->setPlainText((QString("VOCE NAO TEM DINHEIRO PARA ISTO")));
        ui->Bet1000_Button->setEnabled(false);
    }


    ui->plainTextEdit_playerBank->setPlainText(QString("Dinheiro: ") + QString::number(playerBank));
    ui->plainTextEdit_dealerBank->setPlainText(QString("Dinheiro: ") + QString::number(dealerBank));
    ui->plainTextEdit_tablePot->setPlainText(QString("TablePot: ") + QString::number(tableBank));

}


void TelaPrincipal::on_Play_Button_clicked()
{
    cout << "Botao PLAY apertado" << endl;
}


void TelaPrincipal::on_Reset_Button_clicked()
{
    ui->Buy_Button->setEnabled(true);
    ui->Bet10_Button->setEnabled(false);
    ui->Bet100_Button->setEnabled(false);
    ui->Bet1000_Button->setEnabled(false);
    ui->Hit_Button->setEnabled(true);
    ui->Next_Button->setEnabled(false);
    ui->Play_Button->setEnabled(true);

    playerBank = 1000;
    dealerBank = 1000;
    tableBank = 0;
    playerPoints = 0;
    dealerPoints = 0;


    QPixmap padrao(":/imagens/Default.png");
    //QString v = "1";
    //QString n = "C";
    //QString url = ":/imagens/" + v + n + ".png";
    //QPixmap teste(url);

    ui->label_dealer1->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer2->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer3->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer4->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer5->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));

    ui->label_player1->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player2->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player3->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player4->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player5->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));



    ui->plainTextEdit_player->setPlainText(QString("Points: ") + QString::number(playerPoints));
    ui->plainTextEdit_dealer->setPlainText(QString("Points: ") + QString::number(dealerPoints));
    ui->plainTextEdit_playerBank->setPlainText(QString("Dinheiro: ") + QString::number(playerBank));
    ui->plainTextEdit_dealerBank->setPlainText(QString("Dinheiro: ") + QString::number(dealerBank));
    ui->plainTextEdit_tablePot->setPlainText(QString("TablePot: ") + QString::number(tableBank));
    ui->plainTextEdit_Result->setPlainText((QString("BOM JOGO!!")));


    cout << "Botao Reset apertado" << endl;

    for(unsigned int i = 0; i <= mao_jogador.size(); i++)
        baralho.adicionaCarta(mao_jogador.retiraCarta());

    for(unsigned int i = 0; i <= mao_dealer.size(); i++)
        baralho.adicionaCarta(mao_dealer.retiraCarta());

    baralho.shuffle();

}

void TelaPrincipal::on_Close_Button_clicked()
{
    cout << "Botao CLOSE GAME apertado" << endl;
    close();
}

void TelaPrincipal::on_Next_Button_clicked()
{
    cout << "Botao NEXT apertado" << endl;

    playerPoints = 0;
    dealerPoints = 0;
    tableBank = 0;

    ui->Buy_Button->setEnabled(true);
    ui->Bet10_Button->setEnabled(false);
    ui->Bet100_Button->setEnabled(false);
    ui->Bet1000_Button->setEnabled(false);
    ui->Hit_Button->setEnabled(true);
    ui->Next_Button->setEnabled(false);

    QPixmap padrao(":/imagens/Default.png");

    ui->label_dealer1->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer2->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer3->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer4->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_dealer5->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));

    ui->label_player1->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player2->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player3->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player4->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));
    ui->label_player5->setPixmap(padrao.scaled(90,170,Qt::KeepAspectRatio));

    ui->plainTextEdit_player->setPlainText(QString("Points: ") + QString::number(playerPoints));
    ui->plainTextEdit_dealer->setPlainText(QString("Points: ") + QString::number(dealerPoints));
    ui->plainTextEdit_tablePot->setPlainText(QString("TablePot: ") + QString::number(tableBank));
    ui->plainTextEdit_Result->setPlainText((QString("BOM JOGO!!")));


    for(unsigned int i = 0; i <= mao_jogador.size(); i++)
        baralho.adicionaCarta(mao_jogador.retiraCarta());

    for(unsigned int i = 0; i <= mao_dealer.size(); i++)
        baralho.adicionaCarta(mao_dealer.retiraCarta());

    baralho.shuffle();

}

