#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <math.h>
#include <vector>
#include <algorithm>
 
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
 
int ArredondeParaInteiroCom2Casas(float valor)
{
    int tmp = valor * 10;
    float truncated = tmp / 10.0;
 
    return round(truncated);
}
 
static vector<std::string> SplitString(const std::string &source, char delimiter)
{
    vector<std::string> output;
    istringstream ss(source);
    string nextItem;
 
    while (std::getline(ss, nextItem, delimiter))
    {
        output.push_back(nextItem);
    }
 
    return output;
}
 
float StringToDouble(std::string& message)
{
  stringstream ss(message);
  float value;
 
  ss >> value;
  if (!ss)
    throw invalid_argument(message);
 
  return value;
}
 
int main(){
    int repeticoes = 0;
    cin >> repeticoes;
    cin.ignore();
    while(repeticoes > 0){
        char identificador;
        float parametro1 = 0, parametro2 = 0, parametro3 = 0;
 
        string entrada, aux;
        getline(cin, entrada);
 
        vector<string> splitted = SplitString(entrada, ' ');
 
        aux = splitted[0];
        identificador = aux[0];
        parametro1 = StringToDouble(splitted[1]);
 
        if (splitted.size() >= 3)
        {
            parametro2 = StringToDouble(splitted[2]);
        }
 
        if (splitted.size() >= 4)
        {
            parametro3 = StringToDouble(splitted[3]);
        }
 
        float area = ObtenhaAreaDaFigura(identificador, parametro1, parametro2, parametro3);
        
        std::cout << ArredondeParaInteiroCom2Casas(area) << "\n";
 
        repeticoes--;
    }
 
    return 0;
}