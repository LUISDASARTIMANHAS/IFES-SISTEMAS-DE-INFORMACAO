/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provasuplemento;

/**
 *
 * @author 2023122760328
 */
public abstract class Whey extends Suplemento{
    //• Whey é um Suplemento e todo Whey possui quantidade de proteína e quantidade de carboidrato.
    //Um Whey forte possui (quantidade de proteína / quantidade de carboidrato) > 5;
    protected int qtProteina;
    protected double qtCarboidrato;

    public Whey(int qtProteina, double qtCarboidrato, String codigo, String nomeProduto, String fabricante) {
        super(codigo, nomeProduto, fabricante);
        this.qtProteina = qtProteina;
        this.qtCarboidrato = qtCarboidrato;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Whey other = (Whey) obj;
        if (this.qtProteina != other.qtProteina) {
            return false;
        }
        return Double.doubleToLongBits(this.qtCarboidrato) == Double.doubleToLongBits(other.qtCarboidrato);
    }
    
    
    
}
