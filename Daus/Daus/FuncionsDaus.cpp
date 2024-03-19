#include "HeaderDaus.h"


/// <summary>
/// This function works as the main connector, to make the player able to decide if he wants to play or not
/// </summary>
/// <param name="opcio"></param> this function will be used to decide if to continue or not
/// <param name="cartera"></param> this is used as a value for the coins that we can use
void menu(int opcio, int* cartera) {
	
	//variables used to generate random numbers
	int dau1;
	int dau2;
	int total;
	int aposta;
	int numero;

	//With this part we create a void that lasts until the value opcio is 2
	do {

		//We create this do while to avoid the player use unintended options
		do {
			cout << "Introdueix 1 per fer la teva aposta, 2 per sortir" << endl;
			cin >> opcio;
		} while (opcio != 1 && opcio != 2);

		//This conditions are used 
		if (opcio == 1 && *cartera > 0) {

			dau1 = 0;
			dau2 = 0;
			total = 0;
			aposta = 0;


			gambling(aposta, cartera, &numero);
			tirada(&dau1, &dau2);
			total = dau1 + dau2;
			resultat(&total, &aposta, *cartera, &numero);
			

		}

		//This part is displayed when the player tries to play but he has 0 coins
		else if (opcio == 1 && *cartera <= 0) {

			cout << "Fora d'aqui! No et queden calers!" << endl;
			return;

		}
	} while (opcio != 2);
}

/// <summary>
/// Function used to simulate 2 dices giving a number 
/// </summary>
/// <param name="dau1"></param> first dice
/// <param name="dau2"></param> second dice
void tirada(int* dau1, int* dau2) {

	*dau1 = rand() % 6 + 1;
	*dau2 = rand() % 6 + 1;

	//This used to display the adress of the info
	
	cout << "El primer dau ha tret: " << *dau1 << endl;
	cout << "El segon dau ha tret: " << *dau2 << endl;
}


/// <summary>
/// Function used to make the bet and get it from the pocket salary
/// </summary>
/// <param name="aposta"></param> bet done by the player
/// <param name="cartera"></param> amount of salary that the player has
/// <param name="numero"></param> bet from the player
void gambling(int& aposta, int *cartera, int *numero) {

	//Void to avoid the player to introduce an unvalid number
	do {
		cout << "Introdueix la quantitat a apostar" << endl;
		cout << "Salari: " << *cartera << endl;
		cin >> aposta;
	} while (aposta <= 0);
	
	//Value substracted from the salary value
	*cartera -= aposta;
	cout << "Introdueix el numero que creus que sortira: " << endl;
	cin >> *numero;
}


/// <summary>
/// Function used to give the player the amount of coins based on the result of the bet
/// </summary>
/// <param name="total"></param>
/// <param name="aposta"></param>
/// <param name="cartera"></param>
/// <param name="numero"></param>
void resultat(int* total, int* aposta, int& cartera, int* numero) {

	//If the number equals, the bet is multiplied by 10
	if (*total == *numero) {

		cout << "Has guanyat! Aqui tens 10 vegades el que havies apostat!" << endl;

		cartera += (*aposta * 10);
	}

	//In case the bet is 1 position around, it gives the double amount of the bet
	else if (*total == (*numero - 1) || *total == (*numero + 1)) {

		cout << "Esta prou be! Per un numero! Guanyes el doble del que has apostat!" << endl;

		cartera += (*aposta * 2);
	}

	//In other hand, if the result is around 2, it gives the user the same amount
	else if (*total == (*numero - 2) || *total == (*numero + 2)) {

		cout << "Un pel lluny... Pero aqui som benevolents, aixi que et tornem el que has apostat..." << endl;

		cartera += *aposta;
	}

	//Finally, if the number 3 numbers larger or shorter, the user loses his bet
	else {
		cout << "Bueno, si ja et passes de 3, aqui si que has perdut!" << endl;
	}

}

