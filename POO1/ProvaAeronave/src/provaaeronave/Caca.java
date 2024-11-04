/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provaaeronave;

/**
 *
 * @author 2023122760328
 */
public class Caca extends Aeronave {
    private int avionica;

    public Caca(String fabricante, int anoFabricacao, int anoModelo, int qtdMisseis, int par3, int par4) {
        super(fabricante, anoFabricacao, anoModelo, capacidadeCarga, 4);
    }

    public int getAvionica() {
        return avionica;
    }

    @Override
    public double getCapacidadeAtaque(){
    return (this.capacidadeCarga * avionica)/this.qtdMisseis;
    }
    
}
