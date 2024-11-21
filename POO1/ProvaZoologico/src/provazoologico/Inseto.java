/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provazoologico;

/**
 *
 * @author 2023122760328
 */
public abstract class Inseto extends Animal {

    private static int sequencial = 1;

    public Inseto(int idade, double peso) {
        super(String.valueOf(Inseto.sequencial), idade, peso);
        Inseto.sequencial++;
    }

}
