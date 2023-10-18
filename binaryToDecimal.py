def string_reversa(string):
    reverso=""
    for i in range(len(string)-1,-1,-1):
        reverso=reverso+string[i]
    return reverso


def bin_dec(string):
    resultado=0
    for i in range(len(string)):
        resultado=resultado*2
        resultado=resultado+int(string[i])
    return resultado

def dec_bin(string):
    resultado=''
    aux=int(string)
    resto=0
    while(aux!=1 and aux!=0):
        resto=aux%2
        aux=aux//2
        resultado=resultado+str(resto)
    resultado=resultado+str(aux)
    resultado=string_reversa(resultado)

    return resultado


resultado=0
escolha=2
numero=-1
while(escolha!=0 and escolha!=1):
    escolha= int(input("Escolha 0 para opção binario para decimal e 1 para decimal para binario\n"))

if(escolha==0):
    while(int(numero)<0):
        numero=input("Digite o numero para ser transformado\n")
    resultado=dec_bin(numero)
else:
    isBinary=0
    while isBinary==0:
        numero=input("Digite o numero para ser transformado\n")
        if(int(numero)<0):
            continue
        isBinary=1
        for i in range(0,len(numero),1):
            if int(numero[i])!=0 and int(numero[i])!=1:
                isBinary=0
                break
    resultado=bin_dec(numero)
print(resultado)