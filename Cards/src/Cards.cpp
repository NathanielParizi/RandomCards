//============================================================================
// Name        : Cards.cpp
// Author      : Nathaniel-Joel Parizi
// Version     : Chapter 8 - Object Ortiented Programming in C++ SECOND EDITION
// Copyright   :
// Description : Cards - Array of Objects in C++, Ansi-style
//============================================================================

#include <iostream>

#include <conio.h>		// for for getche() method
#include <cstdlib>
#include <ctime>		// for randomize()

using namespace std;

enum Suit {
	clubs, diamonds, hearts, spades
};

const int jack = 11;   // from 2 to 10 are just integers without names
const int queen = 12;
const int king = 13;
const int ace = 14;

class card {

private:
	// member fields instance variables
	int number;   		// 1-10
	Suit suit;			// ie. hearts

public:
	card() {
	}					//constructor initializes the state of the object itself
	void init(int n, Suit s) {					// initialize card

		suit = s;
		number = n;
	}

	void display();					//show card

};

void card::display() {

	if (number >= 2 && number <= 10)

		cout << number;

	 else

		switch (number) {
		case jack:
			cout << "J";
			break;
		case queen:
			cout << "Q";
			break;
		case king:
			cout << "K";
			break;
		case ace:
			cout << "A";
			break;

		}
		switch (suit) {

		case clubs:
			cout << char(5);
			break;
		case diamonds:
			cout << char(4);
			break;
		case hearts:
			cout << char(3);
			break;
		case spades:
			cout << char(6);
			break;

		}


}

int main() {

	int k;






	card deck[52];
	cout << endl;
	for (int i = 0; i < 52; i++) {
		int num = (i % 13) + 2;
		Suit su = Suit(i / 13);
		deck[i].init(num, su);
	}


	cout << "\nOrdered deck: \n";
	for (int j = 0; j < 52; j++) {



		deck[j].display();
		cout << "  ";
		if (    !(   (j + 1) % 13)) {
			cout << endl;
		}



	}
	cout << "What the hell";

	/* initialize random seed: */
	srand(time(NULL));




	for (int j = 0; j < 52; j++) {


		  /* generate secret number between 1 and 52: */
		k = rand() % 52+1;
		card temp = deck[j];			//for each deck in the card
		deck[j] = deck[k];
		deck[k] = temp;

	}

	cout << '\nShuffled Deck: \n';
	for (int j = 0; j < 52; j++) {
		deck[j].display();
		cout << ", ";
		if (!(j + 1) % 13) {
			cout << endl;

		}
		getche();
	}

	return 0;
}
