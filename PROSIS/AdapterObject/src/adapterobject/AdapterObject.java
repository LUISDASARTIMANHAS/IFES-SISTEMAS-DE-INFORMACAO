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
public class AdapterObject {
    public static void main(String[] args) {
        HiTopGame videogame = new HiTopGame();
        
        Cartucho60Pinos jogo = new Cartucho60Pinos();
        Adaptador60Para72Pinos adaptador = new Adaptador60Para72Pinos(jogo);
        
        videogame.setCartuchoAmericano(adaptador);
        videogame.jogar();
    }
    
}
