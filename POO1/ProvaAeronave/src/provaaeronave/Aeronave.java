/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provaaeronave;

/**
 *
 * @author 2023122760328
 */
public abstract class Aeronave {
    private String fabricante;
    private int anoFabricacao;
    private int anoModelo;
    protected double capacidadeCarga;
    protected int qtdMisseis;

    public Aeronave(String fabricante, int anoFabricacao, int anoModelo, double capacidade, int qtdMisseis) {
        this.fabricante = fabricante;
        this.anoFabricacao = anoFabricacao;
        this.anoModelo = anoModelo;
        this.capacidadeCarga = capacidadeCarga;
        this.qtdMisseis = qtdMisseis;
    }

    public String getFabricante() {
        return fabricante;
    }

    public int getAnoFabricacao() {
        return anoFabricacao;
    }

    public int getAnoModelo() {
        return anoModelo;
    }

    public double getCapacidadeCarga() {
        return capacidadeCarga;
    }

    public int getQuantidadeMisseis() {
        return qtdMisseis;
    }
    
    public abstract AeronaveidadeAtaque();

    String getCapacidadeAtaque() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
}
