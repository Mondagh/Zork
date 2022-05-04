

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "General.h"
#include "World.h"


using namespace std;  


int main()
{
	char key;
	string player_input;
	vector<string> action;
	action.reserve(10);

	cout <<  "Welcome to MyZore Game!\n" ;

	World world;

	

	while (true)
	{
		if (_kbhit() != 0)
		{
			key = _getch();
			if (key == '\b') // backspace
			{
				if (player_input.length() > 0)
				{
					player_input.pop_back();
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
			}
			else if (key != '\r') // return
			{
				player_input += key;
				cout << key;
			}
			else
		   Tokenize(player_input, action);
		if (action.size() > 0 && action[0]._Equal("quit"))
			break;

		}
		if (world.CheckAction(action) == false)
			cout << "\nSorry, I do not understand your command.\n";
		if (action.size() > 0)
		{
			action.clear();
			player_input = "";
			cout << "\n> ";
		}
	}

	cout << "\nThanks for playing, Bye!\n";
	return 0;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
