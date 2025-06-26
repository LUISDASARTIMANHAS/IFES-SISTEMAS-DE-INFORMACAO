/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

import interfaces.CalculaFrete;



/**
 *
 * @author lucas
 */
public class CalculadoraDeFrete {
    private CalculaFrete estrategia;

    public CalculadoraDeFrete(CalculaFrete estrategia) {
        this.estrategia = estrategia;
    }

    public void setEstrategia(CalculaFrete estrategia) {
        this.estrategia = estrategia;
    }

    public double calcularFrete(double peso, int distancia) {
        return estrategia.calcular(peso, distancia);
    }
}
