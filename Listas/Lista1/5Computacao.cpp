#include <iostream>
#include <string>
#include <sstream>
#include <string>
 
using namespace std;
 
static string StringReplace(string entrada, const string &encontrar, const string &replace)
{
    size_t pos = 0;
    while ((pos = entrada.find(encontrar, pos)) != std::string::npos)
    {
        entrada.replace(pos, encontrar.length(), replace);
        pos += replace.length();
    }
    
    return entrada;
}
 
template<typename T>
static string ToString(const T &subject)
{
    std::ostringstream ss;
    ss << subject;
    return ss.str();
}
 
string ConvertaBase10ParaQualquerBase(int num, int baseNum)
{
    string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    if (baseNum < 2 || symbols.length() + 10 < baseNum)
    {
        return "Erro";
    }
 
    string result = "";
    do
    {
        int partResult = static_cast<int>(num % baseNum);
        if (partResult >= 10)
        {
            result.insert(0, ToString(symbols[partResult - 10]));
        }
        else
        {
            result.insert(0, ToString(partResult));
        }
 
        num /= baseNum;
 
    } while (num != 0);
 
    return result;
}
 
static string SubstituaBase4PorLetras(string entrada)
{
    entrada = StringReplace(entrada, "0", "A");
    entrada = StringReplace(entrada, "1", "C"); 
    entrada = StringReplace(entrada, "2", "G");
    entrada = StringReplace(entrada, "3", "T");
 
    return entrada;
}
 
int main()
{
    int quantidadeDeNumeros, i;
    cin >> quantidadeDeNumeros;
 
    int numeros[quantidadeDeNumeros];
    for (i = 0; i < quantidadeDeNumeros; i++)
    {
        cin >> numeros[i];
    }
 
    for (i = 0; i < quantidadeDeNumeros; i++)
    {
        string numero;
        numero = ConvertaBase10ParaQualquerBase(numeros[i], 4);
 
        std::cout << SubstituaBase4PorLetras(numero) << "\n";
    }
}