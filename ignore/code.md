//============================================================================
// Name        : Blackjack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

class Carta {
public:
	Carta(int naipe, int valor){
		_naipe = naipe;
		_valor = valor;
	}

	int value(){
		if(_valor == 1)
			return 11;
		if(_valor > 10){
			return 10;
		} else {
			return _valor;
		}
	}

	void print(){
		if(_valor == 1)
			cout << "Às";
		else if(_valor == 11)
		    cout << "Valete";
		else if(_valor == 12)
			cout << "Dama";
		else if(_valor == 13)
			cout << "Rei";
		else
			cout << _valor;

		if(_naipe == 0)
			cout << " de ouro";
		else if(_naipe == 1)
		    cout << " de espadas";
		else if(_naipe == 2)
			cout << " de copas";
		else
			cout << " de paus";
	}

private:
	int _naipe;
	int _valor;
};

class Deck {
public:
	Deck(){
		std::srand ( unsigned ( std::time(0) ) );
	}

	void adicionaCarta(Carta * carta){
		_cartas.push_back(carta);
	}

	unsigned int size(){
		return _cartas.size();
	}

	Carta * retiraCarta(){
		Carta * carta = _cartas.back();
		_cartas.pop_back();
		return carta;
	}

	int valor(){
		int aces = 0;
		int valor = 0;

		for(unsigned int i = 0; i < _cartas.size(); i++){
			if(_cartas[i]->value() == 11 )
				aces++;
			valor += _cartas[i]->value();
		}

		if(valor > 21){
			while(aces-- && valor > 21){
				valor -= 10;
			}
		}

		return valor;
	}

	void shuffle(){
		std::random_shuffle ( _cartas.begin(), _cartas.end(), rnd );
	}

	static int rnd(int i) { return std::rand()%i;}

	void print_cartas() {
		for(unsigned int i = 0; i < _cartas.size(); i++){
			_cartas[i]->print();
			cout << endl;
		}
	}

private:
	vector<Carta *> _cartas;

};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Deck baralho;
	Deck mao_jogador;

	for(int naipe = 0; naipe < 4; naipe++){
		for(int valor=1; valor < 14; valor++) {
			baralho.adicionaCarta(new Carta(naipe, valor));
		}
	}

	baralho.shuffle();

	while(mao_jogador.valor() < 21){
		cout << "===============================================" << endl;
		cout << "Mão do jogador " << mao_jogador.valor() << endl;
		cout << "===============================================" << endl;
		mao_jogador.adicionaCarta(baralho.retiraCarta());
		mao_jogador.print_cartas();
	}
	cout << "===============================================" << endl;
	cout << "Mão do jogador " << mao_jogador.valor() << endl;
	cout << "===============================================" << endl;

	return 0;
}
