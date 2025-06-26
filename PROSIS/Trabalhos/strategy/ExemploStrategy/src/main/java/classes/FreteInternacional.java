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
public class FreteInternacional implements CalculaFrete {

    @Override
    public double calcular(double peso, int distancia) {
        return 25 + 2.0 * peso + 0.8 * distancia;
    }
    
}
