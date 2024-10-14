/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Excecoes;

public class Excecoes04 {

    public static void main(String[] args) {
        int x = 10, y = 0, z = 0;
        try {
            // gera uma exceção aritmética de
            // divisão por zero
            z = x / y;
            z = 0;
        } catch (Exception erro) {
            // mostra a mensagem de erro
            System.out.println(erro.getMessage());
            // mostra a exceção e a linha onde
            // ocorreu o erro
            erro.printStackTrace();
        }
    }
}
