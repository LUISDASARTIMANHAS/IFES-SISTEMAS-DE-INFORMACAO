/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package usandopessoapolimorfa;

public class Funcionario extends PessoaFisica {

    private String cartao;

    public Funcionario(String cartao, String rg, int idade) {
        super(rg, idade);
        this.cartao = cartao;
    }

    public String getCartao() {
        return cartao;
    }

    public void setCartao(String cartao) {
        this.cartao = cartao;
    }
    
    @Override
    public void imprimirNomeClasse() {
        System.out.println("Classe Funcionario");
    }
}
