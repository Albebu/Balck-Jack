#include <iostream>
#include <random>

using namespace std;


void llenarMatriz(int cartas[4][13])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cartas[i][j] = 1;
		}
	}
}

int repartirCarta(int cartas[4][13], string nombreCartas[13], string nombrePalos[4], int &contador, int jugador)
{
	int random1, random2;

	do
	{
		random1 = rand() % 4;
		random2 = rand() % 13;

		//Comprobación de si esta la carta
		if (cartas[random1][random2] != 0 && jugador == 0)
		{
			cout << nombreCartas[random2] << " de " << nombrePalos[random1] << endl;

		}

		else if (cartas[random1][random2] != 0 && jugador == 1)
		{
			cout << "Al cuprier le ha tocado un " << nombreCartas[random2] << " de " << nombrePalos[random1] << endl;
		}

		//Si es un as elegir el valor del as
		if (random2 == 0 && cartas[random1][0] != 0)
		{
			int aux;

			if (jugador == 1)
			{
				if ((contador += 11) > 21)
				{
					contador += 1;
				}
				else
				{
					contador += 11;
				}
			}
			else if (jugador == 0)
			{
				do
				{
					cout << "Quieres que valga 1. 1 o 2. 11 ?" << endl;
					cin >> aux;

					if (aux == 1)
					{
						contador += 1;
					}

					else if (aux == 2)
					{
						contador += 11;
					}

				} while (aux != 1 && aux != 2);
			}

		}

	} while (cartas[random1][random2] == 0);

	//Poner que ya a salido
	cartas[random1][random2] = 0;

	//Sumar el valor
	if (random2 > 10)
	{
		contador += 10;
	}
	else if (random2 != 0)
	{
		contador += random2;
	}
	
	return contador;
}

void comprobarGanador(int contadorJugador, int contadorMaquina)
{
	if (contadorMaquina > 21)
	{
		cout << "Has ganado";
	}
	else if (contadorJugador > contadorMaquina)
	{
		cout << "Has ganado";
	}
	else if (contadorJugador == contadorMaquina)
	{
		cout << "Has perdido";
	}

	else if (contadorMaquina > contadorJugador)
	{
		cout << "Has perdido ";
	}
}

int main()
{
	srand(time(NULL));

    //Matriz con las cartas
    int cartas[4][13];
	string nombreCartas[13] = { "As", "1", "2", "3", "4", "5", "6", "7", "8", "9", "J", "Q", "K" };
	string nombrePalos[4] = { "Picas", "Corazones", "Treboles", "Diamantes" };
	
	llenarMatriz(cartas);

	int contadorTurno = 0, contadorJugador = 0, contadorMaquina = 0;

	while (contadorTurno < 2)
	{
		
		contadorJugador = repartirCarta(cartas, nombreCartas, nombrePalos, contadorJugador, 0);
		cin.get();
		cout << "Tienes " << contadorJugador << " puntos" << endl;
		contadorTurno++;

	}

	contadorMaquina = repartirCarta(cartas, nombreCartas, nombrePalos, contadorMaquina, 1);

	bool continuar = true;
	int aux;

	do
	{
		cout << "Quieres otra carta 1. Si 2. No" << endl;
		cin >> aux;

		if (aux == 1)
		{
			continuar = true;
		}

		else if (aux == 2)
		{
			continuar = false;
		}

	} while (aux != 1 && aux != 2);
	

	while (continuar)
	{
		contadorJugador = repartirCarta(cartas, nombreCartas, nombrePalos, contadorJugador, 0);
		cin.get();
		cout << "Tienes " << contadorJugador << " puntos" << endl;

		if (contadorJugador > 21)
		{
			cout << "Has perdido";
			return 0;
		}

		int aux2 = 0;

		do
		{
			cout << "Quieres otra carta 1. Si 2. No" << endl;
			cin >> aux2;

			if (aux2 == 1)
			{
				continuar = true;
			}

			else if (aux2 == 2)
			{
				continuar = false;
			}

		} while (aux2 != 1 && aux2 != 2);
	}

	while (contadorMaquina < contadorJugador || contadorMaquina < 21)
	{
		contadorMaquina = repartirCarta(cartas, nombreCartas, nombrePalos, contadorMaquina, 1);
	}

	comprobarGanador(contadorJugador, contadorMaquina);

	return 0;

}

