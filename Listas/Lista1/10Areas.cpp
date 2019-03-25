#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

#include <stdlib.h>

using namespace std;

const float pi = 3.14159265;

float ObtenhaAreaDaFigura(char identificador, float parametro1, float parametro2, float parametro3){
	float raio, raioMaior, raioMenor, ladoA, ladoB, ladoC, semiPerimetro, baseMaior, baseMenor, altura;
	switch(identificador){
		case 'C':
			
			raio = parametro1;
			
			return (pi * (raio *raio));
		break;
		
		case 'E':
			raioMaior = parametro1, raioMenor = parametro2;
			
			return (raioMaior * raioMenor * pi);
		break;
		
		case 'T':
			ladoA = parametro1;
			ladoB = parametro2;
			ladoC = parametro3;
			
			semiPerimetro = (ladoA + ladoB + ladoC) / 2;
			
			return sqrt(semiPerimetro * (semiPerimetro - ladoA) * (semiPerimetro - ladoB) * (semiPerimetro - ladoC));
		break;
		
		case 'Z':
			baseMaior = parametro1;
			baseMenor = parametro2;
			altura = parametro3;
			
			return (((baseMaior + baseMenor) * altura) / 2);
		break;
	}

    return 0;
}

int split (char *str, char c, char ***arr)
{
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }

    *arr = (char**) malloc(sizeof(char*) * count);
    if (*arr == NULL)
        exit(1);

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*arr)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*arr)[i] == NULL)
        exit(1);

    i = 0;
    p = str;
    t = ((*arr)[i]);
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }

    return count;
}

int ArredondeParaInteiroCom2Casas(float valor)
{
    int tmp = valor * 10;
    float truncated = tmp / 10.0;

    return round(truncated);
}

vector<string> SplitString(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

int main(){
	int repeticoes = 0;
    cin >> repeticoes;
    while(repeticoes > 0){
		string entrada;
        char identificador;
        float parametro1, parametro2, parametro3;

        getline(cin, entrada, '\n');

        vector<string> vetor;
        vetor = SplitString(entrada, " ");

        string caracter = vetor[0];
        string p1 = vetor[1];
        string p2 = vetor[2];
        string p3 = vetor[3];
        
        identificador = caracter[0];
		parametro1 = atof(&p1[0]);
		parametro2 = atof(&p2[0]);
		parametro3 = atof(&p3[0]);

        float area = ObtenhaAreaDaFigura(identificador, parametro1, parametro2, parametro3);
		
        printf("%i\n", ArredondeParaInteiroCom2Casas(area));

        repeticoes--;
	}

    return 0;
}
