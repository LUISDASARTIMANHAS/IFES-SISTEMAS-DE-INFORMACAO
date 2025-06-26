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
public class MolhoTomate extends IngredienteDecorator {
    public MolhoTomate(Massa massa) {
        super(massa);
    }

    @Override
    public String getDescricao() {
        return massa.getDescricao() + " com molho de tomate";
    }

    @Override
    public double getPreco() {
        return massa.getPreco() + 1.5;
    }
}
