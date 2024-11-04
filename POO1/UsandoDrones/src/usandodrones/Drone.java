/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package usandodrones;

/**
 *
 * @author 2023122760328
 */
public abstract class Drone {
    private final int numSerie;
    private final int anoFabricacao;

    public Drone(int numSerie, int anoFabricacao) {
        this.numSerie = numSerie;
        this.anoFabricacao = anoFabricacao;
    }

    public int getNumSerie() {
        return numSerie;
    }

    public int getAnoFabricacao() {
        return anoFabricacao;
    }

    public abstract double getValor();
    
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        final Drone other = (Drone) obj;
        return this.numSerie == other.numSerie;
    }

    @Override
    public String toString() {
        return numSerie + " (numero de série) " + anoFabricacao + " (ano de fabricação)";
    }
    
}
