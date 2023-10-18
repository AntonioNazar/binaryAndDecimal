#include <stdio.h>
#include <stdlib.h>

int len(char string[]){
    int count=0;
    char i='a';
    while(i!='\0'){
        i = string[count];
        count++;
    }
    return count-1;
}

int string_number(char string[]){
    int resultado = 0;
    for (int i = 0; i < len(string);i++){   
        resultado = resultado *10 + ((int)string[i]-48);
    }
    return resultado;
}

char* concatenate(char string1[],char string2[]){
    int tamanho1 = len(string1);
    int tamanho2 = len(string2);
    char* stringTotal = (char*)malloc(tamanho1 + tamanho2 + 1);
    if(stringTotal==NULL){
        exit(0);
    }
    for (int i = 0; i < tamanho1; i++)
    {
        stringTotal[i] = string1[i];
    }
    for (int i = tamanho1; i < tamanho1 + tamanho2;i++){
        stringTotal[i] = string2[i - tamanho1];
    }
    stringTotal[tamanho1 + tamanho2] = '\0';
    return stringTotal;
}

int bin_dec(char string[]){
    int resultado=0;
    for (int i = 0; i < len(string);i++){
        resultado *= 2;
        resultado+= (int)string[i]-48; // 0 em ASCII é 48, portanto precisamos subtrair este número
    }
    return resultado;
}

char* dec_bin(char string[]){
    int numero = string_number(string);
    int resto = 0;
    char* bin = (char*)malloc(50);
    bin[0]='\0';
    char aux[2];
    aux[1] = '\0';
    if(bin==NULL){
        exit(0);
    }
    while(numero!=0 && numero!=1){
        resto = numero % 2;
        numero = numero / 2;
        aux[0] = (char)(resto + 48); //48 representa o 0 em ASCII
        char *temp = concatenate(aux, bin);
        free(bin);
        bin = temp;
    }
    aux[0] = (char)(numero+48);
    char *temp = concatenate(aux, bin);
    free(bin);
    bin = temp;
    return bin;
}

int main(){
    char numero[50];
    int escolha=2;
    while(escolha!=0 && escolha!=1){
        printf("Escolha 0 para opcao binario para decimal e 1 para decimal para binario\n");
        scanf("%d", &escolha);
    }
    if(escolha==0){
        int resultado;
        int isBinary = 0;
            while(isBinary==0){
                printf("Digite o numero para ser transformado\n");
                scanf("%s", numero);
                isBinary = 1;
                for (int i = 0; i < len(numero);i++){
                    if((int)(numero[i]-48)!=1 && (int)(numero[i]-48)!=0){
                        isBinary = 0;
                        continue;
                    }
                }
            }
        resultado = bin_dec(numero);
        printf("%d", resultado);
    }
    else{
        char* resultado;
        int isPositive = 0;
        while(isPositive==0){
            printf("Digite o numero para ser transformado\n");
            scanf("%s", numero);
            if(string_number(numero)>=0){
                isPositive = 1;
            }
        }
        resultado = dec_bin(numero);
        printf("%s",resultado);
        free(resultado);
    }
    return 0;
}