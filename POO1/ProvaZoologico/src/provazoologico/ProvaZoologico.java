/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package provazoologico;
public class ProvaZoologico {

    public static void main(String[] args) {
        // A Aranha inseto1 foi criada com nome "1", peso 2.5 e idade 5
        Aranha inseto1 = new Aranha(2.5, 5);
        // DEVE SER impresso: O(a) Aranha de nome 1 possui peso igual a 2.5 e idade igual a 5
        System.out.println(inseto1);
        
        Besouro inseto2 = new Besouro(4.3, 10);
        // DEVE SER impresso: O(a) Besouro de nome 2 possui peso igual a 4.3 e idade igual a 10
        System.out.println(inseto2);
        
        Besouro inseto3 = new Besouro(5.6, 7);
        System.out.println(inseto3);
        
        System.out.println("O inseto " + inseto1.getNome() + " quando come faz " + inseto1.comer());
        System.out.println("O inseto " + inseto2.getNome() + " quando come faz " + inseto2.comer());
        System.out.println("O inseto " + inseto3.getNome() + " quando come faz " + inseto3.comer());
        
        Tigre tigre1 = new Tigre("Tigr�o", 150.5, 20, 0);
        Tigre tigre2 = new Tigre("Tigresa", 90.8, 18, 0);
        Tigre tigre3 = tigre1.acasalar(tigre2);
        System.out.println(tigre1);
        System.out.println(tigre2);
        System.out.println(tigre3);
        
                
        System.out.println("O " +  tigre1.getClass().getSimpleName() + " " + tigre1.getNome() 
                + " quando come faz " + tigre1.comer());
        System.out.println("O " +  tigre1.getClass().getSimpleName() + " " + tigre2.getNome() 
                + " quando come faz " + tigre2.comer());
        System.out.println("O " +  tigre1.getClass().getSimpleName() + " " + tigre3.getNome() 
                + " quando come faz " + tigre3.comer());
    }
}