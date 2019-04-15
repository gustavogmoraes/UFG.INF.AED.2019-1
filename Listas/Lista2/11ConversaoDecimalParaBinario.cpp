#include <iostream>
#include <sstream>

using namespace std;

 int ConvertaDecimalParaBinario(int numeroDecimal) 
{ 
    if (numeroDecimal == 0)  
        return 0;  
    else
        return (numeroDecimal % 2 + 10 * ConvertaDecimalParaBinario(numeroDecimal / 2)); 
} 

int main()
{
    int quantidadeDeTestes, numeroDecimal;
    
    cin >> quantidadeDeTestes;

    int i = 0;
    while (i < quantidadeDeTestes)
    {
		i++;
        cin >> numeroDecimal;

        cout << ConvertaDecimalParaBinario(numeroDecimal) << "\n";
    }

    return 0;
}
