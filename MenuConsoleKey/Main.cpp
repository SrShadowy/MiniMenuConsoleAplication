#include <iostream>
#include <Windows.h>
int main() {

	struct menu {
		int numero;
		bool x;
	};

	bool mostra[10] = { true,false,false,false,false,false,false,false,false,false };
	int index[] = { 0,1,2,3,4,5,6,7,8,9 };
	int valor = 0;
	std::string x[2] = {"","<<"};
	menu lista[10];
	lista[0].numero = index[0];
	lista[1].numero = index[1];
	lista[2].numero = index[2];
	lista[3].numero = index[3];
	lista[4].numero = index[4];
	lista[5].numero = index[5];
	lista[6].numero = index[6];
	lista[7].numero = index[7];
	lista[8].numero = index[8];
	lista[9].numero = index[9];
	lista[0].x = mostra[0];
	lista[1].x = mostra[1];
	lista[2].x = mostra[2];
	lista[3].x = mostra[3];
	lista[4].x = mostra[4];
	lista[5].x = mostra[5];
	lista[6].x = mostra[6];
	lista[7].x = mostra[7];
	lista[8].x = mostra[8];
	while (true)
	{

		if (GetAsyncKeyState(VK_RIGHT)) {
			if (valor == 5){
				lista[valor].x = !lista[valor].x;
				valor = -1;
			}
			valor++;
			lista[valor-1].x = !lista[valor-1].x;
			lista[valor].x = !lista[valor].x;
		}
		else if (GetAsyncKeyState(VK_LEFT)) {
				if (valor == 0){
					lista[valor].x = !lista[valor].x;
					valor = 6;
				}
				valor--;
				lista[valor + 1].x = !lista[valor + 1].x;
				lista[valor].x = !lista[valor].x;
		}else if (GetAsyncKeyState(VK_DOWN)) {
			if (valor == 5) {
				lista[valor].x = !lista[valor].x;
				valor = -3;
			}
			valor+=3;
			lista[valor - 3].x = !lista[valor - 3].x;
			lista[valor].x = !lista[valor].x;
		}
		else if (GetAsyncKeyState(VK_UP)) {
			if (valor == 0) {
				lista[valor].x = !lista[valor].x;
				valor = 5;
			}
			valor-=3;
			lista[valor + 3].x = !lista[valor + 3].x;
			lista[valor].x = !lista[valor].x;
		}
		else if (GetAsyncKeyState(VK_RETURN))
			break;

		std::cout << ">>index[" << index[valor] << "]<<\n";


		
		std::cout << lista[0].numero << " Cheat process " << x[lista[0].x] << "\t";
		std::cout << lista[1].numero << " Injector " << x[lista[1].x] << "\t";
		std::cout << lista[2].numero << " ReadAndWrite " << x[lista[2].x] << "\n";
		std::cout << lista[3].numero << " Unknow " << x[lista[3].x] << "\t\t";
		std::cout << lista[4].numero << " IDK " << x[lista[4].x] << "\t\t";
		std::cout << lista[5].numero << " Exit " << x[lista[5].x] << "\n";

		Sleep(50);
		system("cls");

	}
	std::cout << lista[0].numero << " Cheat process " << x[lista[0].x] << "\t";
	std::cout << lista[1].numero << " Injector " << x[lista[1].x] << "\t";
	std::cout << lista[2].numero << " ReadAndWrite " << x[lista[2].x] << "\n";
	std::cout << lista[3].numero << " Unknow " << x[lista[3].x] << "\t\t";
	std::cout << lista[4].numero << " IDK " << x[lista[4].x] << "\t\t";
	std::cout << lista[5].numero << " Exit " << x[lista[5].x] << "\n";
	switch(valor){

	case 0:
		std::cout << "\n\n\n\nOh Hello a Cheat Process! welcome and bye\n";
		break;
	case 1:
		std::cout << "\n\n\n\nInjector huumm God choice\n";
		break;
	case 2:
		std::cout << "\n\n\n\nWhat you to do? Write or Read?\n";
		break;
	case 3:
		std::cout << "\n\n\n\n??????\n";
		break;
	case 4:
		std::cout << "\n\n\n\nI`m sorry but, I unkow too...\n";
		break;
	case 5:
		std::cout << "\n\n\n\nOkey Good Day, and thanks for used me\n";
		break;
	default:
		break;
	}

	return 0;
}