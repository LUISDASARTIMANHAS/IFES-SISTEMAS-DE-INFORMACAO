/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package associacao;

/**
 *
 * @author 2023122760328
 */
public class Prato {

    private String nome;
    private String inventor;
    private Cliente cliente;

    public Prato(String Nome, String Inventor) {
        this.nome = Nome;
        this.inventor = Inventor;
    }

    public void setCliente(Cliente cliente) {
//        se ja tiver prato 
        if (this.cliente != null) {
            this.cliente.setPrato(null);
        }
        this.cliente = cliente;
    }

    public String getNome() {
        return nome;
    }

    public String getInventor() {
        return inventor;
    }

    public Cliente getCliente() {
        return cliente;
    }
}
