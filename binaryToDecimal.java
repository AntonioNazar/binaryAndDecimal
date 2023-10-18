import java.util.Scanner;

public class binaryToDecimal {
    
    static int string_decimal(String string) {
        int resultado = 0;
        for (int i = 0; i < string.length(); i++) {
            resultado = resultado * 10 + (int) (string.charAt(i) - 48);
        }
        return resultado;
    }


    static int bin_dec(String string) {
        int resultado = 0;
        for (int i = 0; i < string.length(); i++) {
            resultado *= 2;
            resultado += (int) string.charAt(i)-48;
        }
        return resultado;
    }
 
     static String dec_bin(String string) {
         int numero = string_decimal(string);
         int resto = 0;
         String resultado_invertido = "";
         String resultado = "";
         while (numero != 0 && numero != 1) {
             resto = numero % 2;
             numero = numero / 2;
             resultado_invertido = resultado_invertido + (char) (resto + 48);
         }
         resultado_invertido = resultado_invertido + numero;
         for (int i = resultado_invertido.length()-1; i>= 0; i--) {
             resultado = resultado + resultado_invertido.charAt(i);
         }

         return resultado;
    }
  
    public static void main(String[] args) {
        boolean escolha = false;
        String numero="";
        Scanner scanner = new Scanner(System.in);
        System.out.println("Escolha true para opcao decimal para binario e false para binario para decimal");
        escolha = scanner.nextBoolean();
        scanner.nextLine();
        if (escolha == true) {
            boolean isNegative = true;
            while (isNegative == true) {
                System.out.println("Digite o numero para ser transformado");
                numero = scanner.nextLine();
                if(string_decimal(numero)>=0){
                    isNegative = false;
                }
            }

            String resultado = dec_bin(numero);
            System.out.println(resultado);
            
        } else {
            boolean isBinary = false;
            while (isBinary == false) {
                System.out.println("Digite o numero para ser transformado");
                numero = scanner.nextLine();
                isBinary = true;
                for (int i = 0; i < numero.length(); i++) {
                    if ((int) (numero.charAt(i) - 48) != 0 && (int) (numero.charAt(i) - 48) != 1) {
                        isBinary = false;
                        break;
                    }
                }
            }
            int resultado = bin_dec(numero);
            System.out.println(resultado);
        }
        scanner.close();
    }
}