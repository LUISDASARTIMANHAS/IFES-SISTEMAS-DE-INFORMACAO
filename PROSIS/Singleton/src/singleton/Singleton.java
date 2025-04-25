/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package singleton;
public class Singleton {

    public static void outroMetodo(Acumuladora a){
        a = Acumuladora.getInstancia();
        a.incremetarValor(50);
        a.incremetarValor(10); 
    }
    public static void main(String[] args) {
        Acumuladora a = Acumuladora.getInstancia();
        a.incremetarValor(10);
        a.incremetarValor(20);
        System.out.println("O valor é " + a.getValor());
        
        // Suponha aqui diversos outros códigos de outras classes ...
        
        Singleton.outroMetodo(a);
        System.out.println("O valor é " + a.getValor());
    }
}
