/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lerguerreiros;

public class Leitor {
    
}

class Guerreiro{
    private String nome;
    private int idade;
    private double peso;
    private int enegria = 100;

    public Guerreiro(String nome, int idade, double peso, int enegria) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
        this.enegria = enegria;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public int getEnegria() {
        return enegria;
    }

    public void setEnegria(int enegria) {
        this.enegria = enegria;
    }
}