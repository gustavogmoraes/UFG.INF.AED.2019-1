#include <iostream>

using namespace std;

int Calcule(int numeroA, int numeroB, char operador){
	switch (operador){
		case '+':
			return numeroA + numeroB;
		break;
		
		case 'x':
			return numeroA * numeroB;
		break;
	}

	return 0;
}

int main(){
	int maiorNumeroRepresentavel, numeroA, numeroB, resultado;
	char operador;
	
	cin >> maiorNumeroRepresentavel;
	cin >> numeroA >> operador >> numeroB;
	
	resultado = Calcule(numeroA, numeroB, operador);
	
	if(resultado > maiorNumeroRepresentavel){
		cout << "overflow\n";
	}
	else{
		cout << "ok\n";
	}
	
	return 0;
}
