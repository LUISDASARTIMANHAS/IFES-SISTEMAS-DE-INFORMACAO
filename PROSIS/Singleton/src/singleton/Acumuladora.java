/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package singleton;

/**
 *
 * @author Giovany
 */
public class Acumuladora {
    private int valor;
    
    private static Acumuladora instancia;
    public static Acumuladora getInstancia() {
        if (instancia == null)
            instancia = new Acumuladora();
        return instancia;
    }
    private Acumuladora() {
        valor = 0;
    }
    public void incremetarValor(int acrescimo){
        valor += acrescimo;
    }
    public int getValor(){
        return valor;
    }
}


/*
    

    public Acumuladora() {
    }
    

*/