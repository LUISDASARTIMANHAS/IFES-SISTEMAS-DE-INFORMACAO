/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package usandocomparable;

public class Pessoa implements Comparable {

    private final String nome;
    private final int idade;

    public Pessoa(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    @Override
    public String toString() {
        return "Pessoa{ " + "nome = " + nome + " idade = " + idade + " }";
    }

    @Override
    public int compareTo(Object o) {
        Pessoa outro = (Pessoa) o;
        // O objeto corrente tem maior idade
        if (this.idade > outro.idade) {
            return 1;
        } // as idades são iguais
        else if (this.idade == outro.idade) {
            return 0;
        } // O objeto forneceido como parâmetro tem maior idade
        else {
            return -1;
        }
    }
}
