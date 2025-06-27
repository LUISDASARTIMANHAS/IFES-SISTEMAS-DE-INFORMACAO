/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package decorator;

import classes.Massa;

/**
 *
 * @author lucas
 */
public abstract class IngredienteDecorator extends Massa {
    protected Massa massa; 

    public IngredienteDecorator(Massa massa) {
        this.massa = massa;
    }
}
