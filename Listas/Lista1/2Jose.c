#include <stdio.h>

int InvertaNumero(int numero){
	int centena, dezena, unidade;
	centena = numero/100;
	dezena = numero/10 - centena * 10;
	unidade = numero - centena * 100 - dezena * 10;
	
	return (unidade * 100 + dezena * 10 + centena);
}

int ObtenhaMaiorNumeroPorComparacao(int numeroA, int numeroB){
	if(numeroA > numeroB){
		return numeroA;
	}
	else{
		return numeroB;
	}
}

int main(){
	int entrada;
	int numeroA, numeroB, maiorNumero;
	
	scanf("%i %i", &numeroA, &numeroB);
	
	numeroA = InvertaNumero(numeroA);
	numeroB = InvertaNumero(numeroB);
	
	printf("%i", ObtenhaMaiorNumeroPorComparacao(numeroA, numeroB));
	
	return 0;
}