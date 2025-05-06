/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package adapterobject;

/**
 *
 * @author Giovany
 */
public class HiTopGame {
    private Cartucho72Pinos cartuchoAmericano;

    public Cartucho72Pinos getCartuchoAmericano() {
        return cartuchoAmericano;
    }

    public void setCartuchoAmericano(Cartucho72Pinos cartuchoAmericano) {
        this.cartuchoAmericano = cartuchoAmericano;
    }
    
    public void jogar(){
        this.cartuchoAmericano.jogarNintendo();
    }
}
