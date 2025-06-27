/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package main;

import classes.CalculadoraDeFrete;
import classes.FreteEconomico;
import classes.FreteExpresso;
import classes.FreteInternacional;

/**
 *
 * @author lucas
 */
public class Main {
    public static void main(String[] args) {
        double peso = 3.5;
        int distancia = 200; 

        CalculadoraDeFrete frete = new CalculadoraDeFrete(new FreteEconomico());
        System.out.println("Frete Econômico: R$ " + frete.calcularFrete(peso, distancia));

        frete.setEstrategia(new FreteExpresso());
        System.out.println("Frete Expresso: R$ " + frete.calcularFrete(peso, distancia));

        frete.setEstrategia(new FreteInternacional());
        System.out.println("Frete Internacional: R$ " + frete.calcularFrete(peso, distancia));
    }
}
