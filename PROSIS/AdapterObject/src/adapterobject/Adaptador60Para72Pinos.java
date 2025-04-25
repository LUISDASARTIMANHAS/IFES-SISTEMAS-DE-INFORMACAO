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
public class Adaptador60Para72Pinos extends Cartucho72Pinos {
    private Cartucho60Pinos cartuchoJapones;

    public Adaptador60Para72Pinos(Cartucho60Pinos cartuchoJapones) {
        this.cartuchoJapones = cartuchoJapones;
    }

    @Override
    public void jogarNintendo() {
        cartuchoJapones.jogarFamicon();
    }
}
