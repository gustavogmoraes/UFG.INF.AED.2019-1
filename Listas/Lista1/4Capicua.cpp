#include <iostream>

using namespace std;

int InvertaNumero(int numero){
	int milhar, centena, dezena, unidade;
	milhar = numero/1000;
    centena = numero/100 - milhar * 10;
    dezena = numero/10 - milhar *100 - centena * 10;
    unidade = numero - milhar *1000 - centena * 100 - dezena * 10;
    
    return (unidade * 1000 + dezena * 100 + centena * 10 + milhar);
}

string VerifiqueSeNumeroEhCapicua(int numero){
	int numeroInvertido = numero;
	
	numeroInvertido = InvertaNumero(numero);
	
	if(numeroInvertido == numero){
		return "sim ";
	}
	else{
		return "nao ";
	}
}

int main(){
	int numeroRepeticoesPrograma, numero, i;
	
	cin >> numeroRepeticoesPrograma;
	string vetorResposta[numeroRepeticoesPrograma];
	
	for(i = numeroRepeticoesPrograma; i > 0; i--){
		cin >> numero;
		vetorResposta[i - 1] = VerifiqueSeNumeroEhCapicua(numero);
	}
	
	for(i = numeroRepeticoesPrograma; i > 0; i--){
		cout << vetorResposta[i - 1];
	}
	
	return 0;
}
