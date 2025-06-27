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
public class FreteExpresso implements CalculaFrete {

    @Override
    public double calcular(double peso, int distancia) {
        return 10 + 1.0 * peso + 0.3 * distancia;
    }
    
    
}

