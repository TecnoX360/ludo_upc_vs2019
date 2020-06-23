#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

void mostrarPantallaPrincipal();
void mostrarCreditos();
void mostrarInstrucciones();
void mostrarPantallaCarga();

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
	//Partida();
}

int main()
{
    mostrarPantallaPrincipal();
    _getch();
    return 0;
}
