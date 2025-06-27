/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package main;

import classes.Macarronada;
import classes.Massa;
import decorator.MolhoTomate;
import decorator.Queijo;

/**
 *
 * @author lucas
 */
public class Cliente {
    public static void main(String[] args) {
        Massa massa = new Macarronada();
        massa = new Queijo(massa);
        massa = new MolhoTomate(massa);

        System.out.println(massa.getDescricao()); 
        System.out.println("Preço: R$ " + massa.getPreco()); 
    }
}

