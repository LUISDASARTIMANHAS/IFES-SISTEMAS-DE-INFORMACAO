/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package usandodrones;

/**
 *
 * @author 2023122760328
 */
public class Mavic extends DroneVoador{
    private double resolucaoVisual;

    public Mavic(double resolucaoVisual, int autonomiaVoo, int numSerie, int anoFabricacao) {
        super(autonomiaVoo, numSerie, anoFabricacao);
        this.resolucaoVisual = resolucaoVisual;
    }

    public double getResolucaoVisual() {
        return resolucaoVisual;
    }

    public void setResolucaoVisual(double resolucaoVisual) {
        this.resolucaoVisual = resolucaoVisual;
    }

    @Override
    public double getValor() {
        return super.getValor() + this.resolucaoVisual/10; 
    }
    
    
}
