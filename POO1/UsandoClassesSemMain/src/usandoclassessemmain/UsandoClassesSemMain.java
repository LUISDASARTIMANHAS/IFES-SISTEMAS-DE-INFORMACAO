/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package usandoclassessemmain;

import newpackage.Calc2;


public class UsandoClassesSemMain {
    public static void imprimir(String s) {
        System.out.println(s);
    }

    public static void main(String[] args) {
        imprimir("Olá Mundo");
        imprimir(
                String.valueOf(Calc2.somar(2,8))
        );
        imprimir(
                String.valueOf(Calc.somar(2,8))
        );
    }
    
}
