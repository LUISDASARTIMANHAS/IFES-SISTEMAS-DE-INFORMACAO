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
public class Queijo extends IngredienteDecorator{
    public Queijo(Massa massa) {
        super(massa);
    }

    @Override
    public String getDescricao() {
        return massa.getDescricao() + " com queijo";
    }

    @Override
    public double getPreco() {
        return massa.getPreco() + 2.0;
    }
}
