/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package exemplosdemath;

import java.text.DecimalFormat;
import java.util.Locale;

public class ExemplosdeMath {

    public static void Locale01() {
        DecimalFormat df = new DecimalFormat();
        Locale local = Locale.getDefault();

        System.out.println("Configurações do Sistema Operacional: ");
        System.out.println("Sigla: "
                + local.getCountry());
        System.out.println("Pais: " + local.getDisplayCountry());

        System.out.println("Lingua: " + local.getDisplayLanguage());
        System.out.println("Teclado: " + local.getDisplayName());
        System.out.println();
        double valor = 1370.25;
        if (local.getCountry().equals("BR")) {
            df.applyPattern("R$ #,##0.00");
        }
        System.out.println("Valor: "
                + df.format(valor));
    }

    public static void DecimalFormat01() {
        DecimalFormat df = new DecimalFormat();
        df.applyPattern("0.00");
        System.out.println("O valor de PI eh:"
                + df.format(Math.PI));

        double estoque = 198564.45;
        df.applyPattern("#,##0,000.00");

        System.out.println("O valor do estoque eh:" + df.format(estoque));
        df.applyPattern(
                "Jonas possui R$ #,##0,meio000.00 teste");
        System.out.println("O valor do estoque eh:" + df.format(estoque));

    }

    public static void Random() {
        int num = (int) (Math.random() * 100);
        System.out.println("Randomico entre 0 e 99: " + num);
    }

    public static void Pow() {
        double a = 30, b = 2;
        System.out.println("O quadrado de 30 é: " + Math.pow(a, b));
    }

    public static void Sqrt() {
        double a = 900;
        System.out.println("A raíz quadrada de 900 é: " + Math.sqrt(a));
    }

    public static void Max() {
        int a = 20, b = 30;
        double c = -5.9, d = -4.5;

        System.out.println(Math.max(a, b));
        System.out.println(Math.max(c, d));
    }

    public static void Min() {
        int a = 20, b = 30;
        double c = -5.9, d = -4.5;
        System.out.println(Math.min(a, b));
        System.out.println(Math.min(c, d));
    }

    public static void Floor() {
        double a = 6.2, b = 6.6, c = -6.8;
        System.out.println(Math.floor(a)); // resposta 6.0
        System.out.println(Math.floor(b)); // resposta 6.0
        System.out.println(Math.floor(c)); // resposta -7.0
    }

    public static void Ceil() {
        double a = 6.2, b = 6.6, c = -6.8;
        System.out.println(Math.ceil(a)); // resposta 7.0
        System.out.println(Math.ceil(b)); // resposta 7.0
        System.out.println(Math.ceil(c)); // resposta -6.0
    }

    public static void main(String[] args) {
//        Ceil();
//        Floor();
//        Min();
//        Max();
//        Sqrt();
//        Pow();
//        Random();
//    DecimalFormat01();
        Locale01();
    }

}
