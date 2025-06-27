/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

import java.util.List;

/**
 *
 * @author lucas
 */
public abstract class Funcionario {
    protected String nome;
    protected String cargo;

    public Funcionario(String nome, String cargo) {
        this.nome = nome;
        this.cargo = cargo;
    }

    public abstract void exibirInformacoes();
    
    // Métodos de gerenciamento (presentes mesmo nas folhas)
    public void adicionar(Funcionario f) {
        throw new UnsupportedOperationException("Este funcionário não pode adicionar subordinados.");
    }

    public void remover(Funcionario f) {
        throw new UnsupportedOperationException("Este funcionário não pode remover subordinados.");
    }

    public List<Funcionario> getSubordinados() {
        throw new UnsupportedOperationException("Este funcionário não possui subordinados.");
    }
}
