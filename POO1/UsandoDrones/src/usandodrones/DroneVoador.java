/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package usandodrones;

/**
 *
 * @author 2023122760328
 */
public class DroneVoador extends Drone{
    private final int autonomiaVoo;

    public DroneVoador(int autonomiaVoo, int numSerie, int anoFabricacao) {
        super(numSerie, anoFabricacao);
        this.autonomiaVoo = autonomiaVoo;
    }

    public int getAutonomiaVoo() {
        return autonomiaVoo;
    }

    @Override
    public double getValor() {
        double valor = (this.autonomiaVoo * this.getNumSerie());
        return valor/this.getAnoFabricacao();
    }
    
    
}
