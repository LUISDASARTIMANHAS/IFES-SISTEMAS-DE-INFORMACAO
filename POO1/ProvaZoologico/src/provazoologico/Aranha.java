/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provazoologico;

/**
 *
 * @author 2023122760328
 */
public class Aranha extends Inseto {

    public Aranha(double peso, int idade) {
        super(idade, peso);
    }
    
    @Override
    public String comer() {
        return "Cak cak cak cak";
    }
    
}
