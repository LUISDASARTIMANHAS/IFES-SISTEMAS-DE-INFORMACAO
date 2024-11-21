/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provazoologico;

/**
 *
 * @author 2023122760328
 */
public abstract class Mamifero extends Animal {
    private int qtLeiteConsumido;

    public Mamifero(String nome, double peso, int idade, int qtLeiteConsumido ) {
        super(nome, idade, peso);
        this.qtLeiteConsumido = qtLeiteConsumido;
    }

    @Override
    public String toString() {
        return super.toString() + ", Alem de consumir quantidade de leite"
                + "igual a" + this.qtLeiteConsumido;
    }
    
    
    
}
