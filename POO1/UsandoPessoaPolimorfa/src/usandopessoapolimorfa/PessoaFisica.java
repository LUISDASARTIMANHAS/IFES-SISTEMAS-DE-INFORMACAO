/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package usandopessoapolimorfa;

public class PessoaFisica extends Pessoa {

    private String rg;

    public PessoaFisica(String rg,int idade) {
        super("Anonimo", idade);
        this.rg = rg;
    }

    public String getRg() {
        return rg;
    }

    public void setRg(String rg) {
        this.rg = rg;
    }

    @Override
    public String toString() {
        return super.toString() + "rg=" + rg;
    }

    @Override
    public void imprimirNomeClasse() {
        System.out.println("Classe Pessoa Fisica");
    }
}
