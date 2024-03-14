#include <stdio.h>

union numeros {
    int binario;
    int mantisa;
    int hexadecimal;
}numeros;

int main(){
	
{
	int n, bin[999];
    int i = 0;
    int var = 0;
    printf("Ingresa un numero decimal: ");
    scanf("%i",&n);
    var = n;
    while (n != 0)
    {
          bin[i] = n % 2;
          n = n / 2;
          i++;
    }
    i--;
    printf("\nBinario: ");   
    while (i>=0)
    {
          printf("%i",bin[i]);
          i--;
    }
	int mant[999];
    i = 0;
    n = var;
    while (n != 0)
    {
          mant[i] = n % 23;
          n = n / 23;
          i++;
    }
    i--;
    printf("\nmantisa: ");   
    while (i>=0)
    {
          printf("%i",mant[i]);
          i--;
    }
    int exa[999];
    i = 0;
    n = var;
    while (n != 0)
    {
          exa[i] = n % 4;
          n = n / 4;
          i++;
    }
    
    i--;
    
    printf("\nHexadecimal: ");   

    while (i>=0)
    {
          printf("%i",exa[i]);
          i--;
    }
}
    return 0;
}
