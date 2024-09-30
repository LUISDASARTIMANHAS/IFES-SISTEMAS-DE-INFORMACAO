/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package usandopessoapolimorfa;

public class PessoaJuridica extends Pessoa {

    private String cnpj;

    public PessoaJuridica(String cnpj, String nome, int idade) {
        super(nome, idade);
        this.cnpj = cnpj;
    }

    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }
    
    @Override
    public void imprimirNomeClasse() {
        System.out.println("Classe Pessoa Juridica");
    }
}
