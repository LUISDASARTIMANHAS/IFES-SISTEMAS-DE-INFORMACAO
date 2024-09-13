/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package metodosstrings;

public class MetodosStrings {

    public class IndexOf {

        public static void main() {
            String texto = "Linguagem de Programacao";
            char caracter = 'a';

            int indice = texto.indexOf(caracter);
            System.out.println(indice);
            indice++;
            indice = texto.indexOf(caracter, indice);
            System.out.println(indice);
            indice = texto.indexOf("acao", indice);
            System.out.println(indice);
        }
    }

    public class Replace {

        public static void main(String[] args) {
            // retirando espaços em branco dentro de dentro da string
            String frase1 = "Mariana gosta de nana banana".replace(" ", "");
            frase1 = frase1.replace("na", "NA");
            System.out.println(frase1);
        }
    }

    public class Trim {

        public static void main() {
            String nome = " Estados Unidos ";
            System.out.println(nome);
            System.out.println(nome.trim());
            nome = nome.trim();
            System.out.println(nome);
            System.out.println(nome.trim());
        }
    }

    public class SubString {

        public static void main() {
            String frase = "O rato roeu";
            System.out.println(frase.substring(2, 6));
            System.out.println(frase.substring(6));
        }
    }

    public class UpperLowerCase {

        public static void main() {
            String nome = "Luis Augusto";
            System.out.println(nome);
            System.out.println(nome.toUpperCase());
            System.out.println(nome);
            System.out.println(nome.toLowerCase());
        }
    }

    public class CharAt {

        public static void main() {
            int num = 2;
            char n = "AACDD".charAt(num);
            System.out.println("O caracter na posicao "
                    + num + " eh " + n);
        }
    }

    public class Length {

        public static void main() {
            String frase = "Vou estudar esse modulo";
            int tamanho = frase.length();
            System.out.println("O tamanho da string: \"" + frase + "\" eh " + tamanho);
        }
    }

    public static void main(String[] args) {
        Length.main();
        CharAt.main();
        UpperLowerCase.main();
        SubString.main();
        Trim.main();
        IndexOf.main();
    }

}
