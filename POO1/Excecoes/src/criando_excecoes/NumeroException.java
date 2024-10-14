/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package criando_excecoes;

public class NumeroException extends Exception {
    int num;

    public NumeroException(int num) {
        this.num = num;
    }

}
