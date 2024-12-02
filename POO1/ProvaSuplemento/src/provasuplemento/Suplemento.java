package provasuplemento;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author 2023122760328
 */
public abstract class Suplemento {
    //    Todo Suplemento possui um efeito (obterEfeito) mas a classe Suplemento não sabe como fazer;
    //isso, bem como a classe Whey;
    private String codigo;
    private String nomeProduto;
    private String fabricante;
    private static int qt = 0;

    public Suplemento(String codigo, String nomeProduto, String fabricante) {
        this.codigo = codigo;
        this.nomeProduto = nomeProduto;
        this.fabricante = fabricante;
        Suplemento.qt++;
    }

    public String getCodigo() {
        return codigo;
    }

    public String getNomeProduto() {
        return nomeProduto;
    }

    public String getFabricante() {
        return fabricante;
    }

    public static int getQt() {
        return qt;
    }
    
    public abstract String obterEfeito();
    
    @Override
    public String toString() {
        return "O Suplemento de codigo = " + codigo 
                + " Possui como fabricante = " + fabricante 
                + " e nome = " + nomeProduto;
    }
   
}
