/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provaaeronave;

/**
 *
 * @author 2023122760328
 */
public abstract class Helicoptero extends Aeronave{
    private int qtHelices;
    private double potenciaMotor;

    public Helicoptero(int qtHelices, double potenciaMotor, String fabricante, int anoFabricacao, int anoModelo, double capacidade, int qtdMisseis) {
        super(fabricante, anoFabricacao, anoModelo, capacidade, qtdMisseis);
        this.qtHelices = qtHelices;
        this.potenciaMotor = potenciaMotor;
    }
    
    
    public int getQtHelices() {
        return qtHelices;
    }

    public double getPotenciaMotor() {
        return potenciaMotor;
    }

    String getQuantidadeHelices() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
    
    
}
