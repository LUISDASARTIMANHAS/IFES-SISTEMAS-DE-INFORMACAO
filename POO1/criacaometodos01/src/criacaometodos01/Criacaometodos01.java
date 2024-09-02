/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package criacaometodos01;

public class Criacaometodos01 {
    public static void tela(String texto) {
        System.out.println("O texto informado é: ");
        System.out.println(texto);
    }
    
    public static void limpartela() {
        for (int i = 0; i < 25; i++) {
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        String frase  = "o gato roeu a roupa do rei de roma";
        Criacaometodos01.limpartela();
        tela(frase);
    }
    
}
