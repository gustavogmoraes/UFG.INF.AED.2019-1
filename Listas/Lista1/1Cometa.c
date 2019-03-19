#include <stdio.h>
#include <stdlib.h>

const int ANOINICIAL = 1986;
const int CICLO = 76;

int ObtenhaProximoAnoPassagemCometa(int anoBase, int anoParaSoma, char operacao){
	int anoParaSomaAnterior = anoParaSoma;
	switch (operacao)
	{
	   case '+':
		 anoParaSoma += CICLO;
		 
		 if(anoParaSoma > anoBase)
		 	return anoParaSoma;
		 else
		 	ObtenhaProximoAnoPassagemCometa(anoBase, anoParaSoma, '+');
	   break;

	   case '-':
		 anoParaSoma -= CICLO;

		 if(anoParaSoma < anoBase) 
		 	return anoParaSomaAnterior;
		 else 
		 	ObtenhaProximoAnoPassagemCometa(anoBase, anoParaSoma, '-');
	   break;
	}

	return 0;
}

int main() {
	int entrada, anoBase;
	printf("Teste\n");
	scanf("%i", &entrada);

	anoBase = entrada;
	
	if(anoBase >= ANOINICIAL) {
		printf("%i", ObtenhaProximoAnoPassagemCometa(anoBase, ANOINICIAL, '+'));
	} 
	else {
		printf("%i", ObtenhaProximoAnoPassagemCometa(anoBase, ANOINICIAL, '-'));
	}

	getchar();
	return 0;
}
