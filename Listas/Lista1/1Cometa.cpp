#include <iostream>

using namespace std;

const int ANOINICIAL = 1986;
const int CICLO = 76;

int ObtenhaProximoAnoPassagemCometa(int anoBase, int anoParaSoma, char operacao){
	int anoParaSomaAnterior = anoParaSoma;
	switch (operacao)
	{
	   case '+':
		 anoParaSoma += CICLO;
		 
		 if(anoParaSoma > anoBase) {
		 return anoParaSoma;
		 } 
		 else{
			 ObtenhaProximoAnoPassagemCometa(anoBase, anoParaSoma, '+');
		 }
	   break;

	   case '-':
		 anoParaSoma -= CICLO;
		 
		 if(anoParaSoma <= anoBase) {
		 return anoParaSomaAnterior;
		 } 
		 else{
			 ObtenhaProximoAnoPassagemCometa(anoBase, anoParaSoma, '-');
		 }
	   break;
	}
}

int main() {
	int entrada, anoBase, resultado;
	cin >> entrada;
	
	anoBase = entrada;
	if(anoBase >= ANOINICIAL) {
		resultado = ObtenhaProximoAnoPassagemCometa(anoBase, ANOINICIAL, '+');
	} 
	else {
		resultado = ObtenhaProximoAnoPassagemCometa(anoBase, ANOINICIAL, '-');
	}

	cout << resultado;
	return 0;
}
