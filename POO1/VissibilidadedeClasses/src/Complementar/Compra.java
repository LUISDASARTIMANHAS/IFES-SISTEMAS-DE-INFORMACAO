/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Complementar;


public class Compra {
    DetalheCompra detalhe;
    
    public void imprimirDetalhe(){
        System.out.println(detalhe.getValor());
    }

    public Compra(DetalheCompra detalhe) {
        this.detalhe = detalhe;
    }
}
class DetalheCompra{
    private String valor = "10";

    public String getValor() {
        return valor;
    }

    public void setValor(String valor) {
        this.valor = valor;
    }
    
}
