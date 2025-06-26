/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

/**
 *
 * @author lucas
 */
public class Empregado extends Funcionario { 
    
    public Empregado(String nome, String cargo) {
        super(nome, cargo);
    }

    @Override
    public void exibirInformacoes() {
        System.out.println("Empregado: " + nome + " - " + cargo);
    }
}
