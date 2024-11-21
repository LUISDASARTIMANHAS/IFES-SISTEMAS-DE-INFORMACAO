/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provazoologico;

/**
 *
 * @author 2023122760328
 */
public class Tigre extends Mamifero{

    public Tigre(String nome, double peso, int idade, int qtLeiteConsumido) {
        super(nome, peso, idade, qtLeiteConsumido);
    }
    
    @Override
    public String comer() {
        return "Roarr";
    }
    
    public Tigre acasalar(Tigre conjuge){
        return new Tigre(this.getNome() + conjuge.getNome(), 10.0,0,10);
    }
    
}
