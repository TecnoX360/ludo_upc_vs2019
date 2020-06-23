#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

#define N_casillas 58
#define f 15
#define c 15

void mostrarPantallaPrincipal();
void mostrarCreditos();
void mostrarInstrucciones();
void mostrarPantallaCarga();
void Partida();
void dibujarTablero(int tablero[f][c]);
int Dado();
void mostrarFicha(int px, int py, int caracter, int f_color);
void borrarFicha(int px, int py, int tablero[f][c]);
void moverFicha(int& i, int tablero[f][c]);
void fichaAmarilla(int tablero[f][c]);
void mostrarGanador();


void mostrarPantallaPrincipal()
{
	int opcion;
	do {
		Console::Clear();
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "     __         _    __  _______   ______         _    __  ______   ______ " << endl;
		cout << "    / /        //   / / //    ) ) //   ) )       //   / / //   ) ) //   )_)" << endl;
		cout << "   / /        //   / / //    / / //   / /       //   / / //___/ / //       " << endl;
		cout << "  / /        //   / / //    / / //   / /       //   / / / ____ / //        " << endl;
		cout << " / /______  //   / / //    / / //   / /       //   / / //       //    __   " << endl;
		cout << "/________/ ((___/_/ //____/ / ((___/_/       ((___/_/ //       ((____/_/   " << endl;
		cout << "                                                                           " << endl;
		cout << "     _______   _______     __  ________  __     ______         __          " << endl;
		cout << "    //   /_/  //    ) )   / / /__  ___/ / /    //   ) ) /|    / /          " << endl;
		cout << "   //____    //    / /   / /    / /    / /    //   / / //|   / /           " << endl;
		cout << "  / ____/   //    / /   / /    / /    / /    //   / / // |  / /            " << endl;
		cout << " //______  //    / /   / /    / /    / /    //   / / //  | / /             " << endl;
		cout << "/_______/ //____/_/ __/_/___ /_/  __/ /___ ((___/_/ //   |/_/              " << endl;
		cout << "                                                                           " << endl;
		Console::ForegroundColor = ConsoleColor::White;
		cout << "**** MENU DE OPCIONES ****" << endl;
		cout << "1) Iniciar" << endl;
		cout << "2) Creditos" << endl;
		cout << "3) Instrucciones *progress" << endl;
		cout << "4) Salir" << endl;
		cout << "Ingresa tu opcion: "; cin >> opcion;
		switch (opcion)
		{
		case 1: _sleep(250); Console::Clear(); mostrarPantallaCarga(); break;
		case 2: _sleep(250); Console::Clear(); mostrarCreditos(); break;
		case 3: _sleep(250); Console::Clear(); mostrarInstrucciones(); break;
		}
	} while (opcion <= 0 || opcion > 4);
}

void mostrarInstrucciones()
{
	char tecla[64];
	cout << "¿COMO SE JUEGA?" << endl;
	cout << "version de prueba Hito 2" << endl;
	cout << "*******DISCULPE*******" << endl;
	cout << "***ESTAMOS EN OBRAS***" << endl;
	cout << "**********************" << endl;
	cout << endl;
	cout << "Ingrese cualquier tecla para regresar: "; cin >> tecla;
	_sleep(250);
	mostrarPantallaPrincipal();
}

void mostrarCreditos()
{
	char tecla[64];
	cout << "PROFE: BRAVO GARCIA, WILLIAM EDUARDO EL MAS BRAVO PE CAUSA" << endl;
	cout << "SUS ESCLAVOS:" << endl;
	cout << "- IRIARTE VELARDE, ALESSANDRA LA GIORGI (U202010003)" << endl;
	cout << "- YEN QUISPE, MIJAEL GAAAAAA (U202010305)" << endl;
	cout << endl;
	cout << "Ingrese cualquier tecla para regresar: "; cin >> tecla;
	_sleep(250);
	mostrarPantallaPrincipal();
}

void mostrarPantallaCarga()
{
	cout << "eeee eeeee eeeee eeeee    eeee eeeee    e   e eeeee eeeee    eeeee eeeee eeeee eeeee eeeee e     e     eeeee" << endl;
	cout << "8    8       8   8  88    8    8        8   8 8   8 8   8    8   8 8   8 8   8   8   8   8 8     8     8   8" << endl;
	cout << "8eee 8eeee   8e  8   8    8eee 8eeee    8e  8 8e  8 8eee8    8eee8 8eee8 8e  8   8e  8eee8 8e    8e    8eee8" << endl;
	cout << "88      88   88  8   8    88      88    88  8 88  8 88  8    88    88  8 88  8   88  88  8 88    88    88  8" << endl;
	cout << "88ee 8ee88   88  8eee8    88ee 8ee88    88ee8 88  8 88  8    88    88  8 88  8   88  88  8 88eee 88eee 88  8" << endl;
	cout << "                                                                                                            " << endl;
	cout << "                                                                                                            " << endl;
	cout << "eeeee eeee    eeee eeeee eeeee  eeeee eeeee                                                                 " << endl;
	cout << "8   8 8       8  8 8   8 8   8  8   8 8   8                                                                 " << endl;
	cout << "8e  8 8eee    8e   8eee8 8eee8e 8e    8eee8                                                                 " << endl;
	cout << "88  8 88      88   88  8 88   8 88  8 88  8                                                                 " << endl;
	cout << "88ee8 88ee    88e8 88  8 88   8 88ee8 88  8                                                                 " << endl;
	_sleep(1250);
	Console::Clear();
	Partida();
}

void Partida()
{
	int tablero[f][c] =
	{
		{1,1,1,1,1,1,0,0,0,2,2,2,2,2,2},
		{1,0,1,1,0,1,0,2,2,2,0,2,2,0,2},
		{1,1,1,1,1,1,0,2,0,2,2,2,2,2,2},
		{1,1,1,1,1,1,0,2,0,2,2,2,2,2,2},
		{1,0,1,1,0,1,0,2,0,2,0,2,2,0,2},
		{1,1,1,1,1,1,0,2,0,2,2,2,2,2,2},
		{0,1,0,0,0,0,3,2,3,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,3,4,4,4,4,4,4,0},
		{0,0,0,0,0,0,3,5,3,0,0,0,0,4,0},
		{5,5,5,5,5,5,0,5,0,4,4,4,4,4,4},
		{5,0,5,5,0,5,0,5,0,4,0,4,4,0,4},
		{5,5,5,5,5,5,0,5,0,4,4,4,4,4,4},
		{5,5,5,5,5,5,0,5,0,4,4,4,4,4,4},
		{5,0,5,5,0,5,5,5,0,4,0,4,4,0,4},
		{5,5,5,5,5,5,0,0,0,4,4,4,4,4,4}
	};
	dibujarTablero(tablero);
	fichaAmarilla(tablero);
}

void dibujarTablero(int tablero[f][c])
{
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++)
		{
			switch (tablero[i][j])
			{
			case 0: Console::ForegroundColor = ConsoleColor::Black; break;
			case 1: Console::ForegroundColor = ConsoleColor::Green; break;
			case 2: Console::ForegroundColor = ConsoleColor::Red; break;
			case 3: Console::ForegroundColor = ConsoleColor::Gray; break;
			case 4: Console::ForegroundColor = ConsoleColor::Blue; break;
			case 5: Console::ForegroundColor = ConsoleColor::Yellow; break;
			}
			cout << (char)219;
			Console::ForegroundColor = ConsoleColor::White;
		}
		cout << endl;
	}
	cout << endl;
}

struct Posicion { int x; int y; };

int Dado()
{
	Random x;
	int dado;
	dado = x.Next(1, 7);
	return dado;
}

void mostrarFicha(int px, int py, int caracter, int f_color)
{
	Console::SetCursorPosition(px, py);
	Console::ForegroundColor = ConsoleColor(f_color);
	Console::CursorVisible = false;
	cout << (char)caracter;
}

void borrarFicha(int px, int py, int tablero[f][c])
{
	Console::SetCursorPosition(px, py);
	cout << " ";
}

void moverFicha(int& i, int tablero[f][c])
{
	int tecla = getch();
	if (tecla == 224)
	{
		tecla = getch();
		switch (tecla)
		{
		case 80:
			i++;
			break;
		case 72:
			i += Dado();
			break;
		case 75:
			i += Dado();
			break;
		case 77:
			i += Dado();
		}
	}
}

void fichaAmarilla(int tablero[f][c])
{
	int i = 0;
	Posicion* Arr = new Posicion[N_casillas];
	Arr[0] = { 4,13 };
	//1						
	Arr[1] = { 6,13 };		
	Arr[2] = { 6,12 };
	Arr[3] = { 6,11 };
	Arr[4] = { 6,10 };
	Arr[5] = { 6,9 };
	//2
	Arr[6] = { 5,8 };
	Arr[7] = { 4,8 };
	Arr[8] = { 3,8 };
	Arr[9] = { 2,8 };
	Arr[10] = { 1,8 };
	Arr[11] = { 0,8 };
	Arr[12] = { 0,7 };
	//3
	Arr[13] = { 0,6 };
	Arr[14] = { 1,6 };
	Arr[15] = { 2,6 };
	Arr[16] = { 3,6 };
	Arr[17] = { 4,6 };
	Arr[18] = { 5,6 };
	//5
	Arr[19] = { 6,5 };
	Arr[20] = { 6,4 };
	Arr[21] = { 6,3 };
	Arr[22] = { 6,2 };
	Arr[23] = { 6,1 };
	Arr[24] = { 6,0 };
	Arr[25] = { 7,0 };
	Arr[26] = { 8,0 };
	//6
	Arr[27] = { 8,1 };
	Arr[28] = { 8,2 };
	Arr[29] = { 8,3 };
	Arr[30] = { 8,4 };
	Arr[31] = { 8,5 };
	//7
	Arr[32] = { 9,6 };
	Arr[33] = { 10,6 };
	Arr[34] = { 11,6 };
	Arr[35] = { 12,6 };
	Arr[36] = { 13,6 };
	Arr[37] = { 14,6 };
	//8
	Arr[38] = { 14,7 };
	Arr[39] = { 14,8 };
	Arr[40] = { 13,8 };
	Arr[41] = { 12,8 };
	Arr[42] = { 11,8 };
	Arr[43] = { 10,8 };
	Arr[44] = { 9,8 };
	//9
	Arr[45] = { 8,9 };
	Arr[46] = { 8,10 };
	Arr[47] = { 8,11 };
	Arr[48] = { 8,12 };
	Arr[49] = { 8,13 };
	Arr[50] = { 8,14 };
	//columna
	Arr[51] = { 7,14 };
	Arr[52] = { 7,13 };
	Arr[53] = { 7,12 };
	Arr[54] = { 7,11 };
	Arr[55] = { 7,10 };
	Arr[56] = { 7,9 };
	Arr[57] = { 7,8 };
	while (1)
	{
		if (i != 57)
		{
			mostrarFicha(Arr[i].x, Arr[i].y, 64, 14);
			if (kbhit())
			{
				_sleep(20);
				borrarFicha(Arr[i].x, Arr[i].y, tablero);
				moverFicha(i, tablero);
			}
		}
		else
		{
			Console::BackgroundColor = ConsoleColor::Black;
			mostrarFicha(Arr[i].x, Arr[i].y, 64, 14);
			_sleep(1000);
			mostrarGanador();
		}
	}
};

void mostrarGanador()
{
	int opc;
	do {
		Console::CursorVisible = true;
		Console::Clear();
		cout << "======================================================================" << endl;
		cout << "=  ====  ====    ====  ====  =======  ====  ====  ==    ==  =======  =" << endl;
		cout << "=   ==   ===  ==  ===  ====  =======  ====  ====  ===  ===   ======  =" << endl;
		cout << "==  ==  ===  ====  ==  ====  =======  ====  ====  ===  ===    =====  =" << endl;
		cout << "==  ==  ===  ====  ==  ====  =======  ====  ====  ===  ===  ==  ===  =" << endl;
		cout << "===    ====  ====  ==  ====  =======   ==    ==  ====  ===  ===  ==  =" << endl;
		cout << "====  =====  ====  ==  ====  ========  ==    ==  ====  ===  ====  =  =" << endl;
		cout << "====  =====  ====  ==  ====  ========  ==    ==  ====  ===  =====    =" << endl;
		cout << "====  ======  ==  ===   ==   =========    ==    =====  ===  ======   =" << endl;
		cout << "====  =======    =====      ===========  ====  =====    ==  =======  =" << endl;
		cout << "======================================================================" << endl;
		cout << "profe, lo queremos mucho <3" << endl;
		cout << "Ingrese 1 para volver al menú" << endl;
		cin >> opc;
		if (opc == 1)
		{
			_sleep(250); Console::Clear(); mostrarPantallaPrincipal();
		}
	} while (opc != 1);
	getch();
}

int main()
{
    mostrarPantallaPrincipal();
    _getch();
    return 0;
}
