/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provazoologico;

/**
 *
 * @author 2023122760328
 */
public abstract class Animal {
    private int idade;
    private String nome;
    private double peso;

    public Animal(String nome, int idade, double peso) {
        this.idade = idade;
        this.nome = nome;
        this.peso = peso;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }
    
    
    public abstract String comer();

    @Override
    public String toString() {
        return "O(a)" + this.getClass().getSimpleName()
                + " de nome " + this.getNome()
                + " possui peso igual a " + this.getPeso()
                + " e idade igual a " + this.getIdade();
    }
    
    
    
}
