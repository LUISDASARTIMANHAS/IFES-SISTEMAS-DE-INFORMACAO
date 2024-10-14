/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Excecoes;

/**
 *
 * @author 2023122760328
 */
public class Excecoes01 {

    public static void main(String[] args) {
        try {
            int a = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);
            System.out.println("Divisao = " + (a / b));
        } catch (ArithmeticException erro) {
            System.out.println("Erro de divisão por zero");
        } catch (ArrayIndexOutOfBoundsException erro) {
            System.out.println("Numero de argumentos invalido");
        } catch (NumberFormatException erro) {
            System.out.println("Digite apenas numeros inteiros");
        } finally {
            System.out.println("Final da execução !");
        }
    }
}
