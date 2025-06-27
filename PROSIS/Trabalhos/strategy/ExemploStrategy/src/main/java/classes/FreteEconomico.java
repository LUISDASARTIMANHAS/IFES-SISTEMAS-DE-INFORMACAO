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
public class FreteEconomico implements CalculaFrete{

    @Override
    public double calcular(double peso, int distancia) {
        return 5 + 0.5 * peso + 0.1 * distancia;
    }
    
}
