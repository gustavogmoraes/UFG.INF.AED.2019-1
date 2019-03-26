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

bool AnoEhBissexto(int ano)
{
	return (ano - ANOINICIAL) % 4 == 0 ? true : false;
}

int TratePassagemEmAnoBissexto(int ano)
{
	int diferenca = ano - ANOINICIAL;
	if(diferenca < 0) diferenca = diferenca * -1;

	int anosBissextos = diferenca / 4;
	int quantidadePraTirar = anosBissextos / 365;

	return ano - quantidadePraTirar;
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

	resultado = TratePassagemEmAnoBissexto(resultado);

	cout << resultado;
	return 0;
}
