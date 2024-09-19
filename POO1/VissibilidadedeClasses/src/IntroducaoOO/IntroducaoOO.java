/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package IntroducaoOO;

public class IntroducaoOO {


    public static void main(String[] args) {
        // TODO code application logic here
        Cliente c1 = new Cliente("JOAO",10,80.52);
        System.out.println(c1.getNome());
        System.out.println(c1.getIdade());
        System.out.println(c1.getPeso());
        Cliente c2 = new Cliente("Ana",10,80.52);
        Cliente c3 = new Cliente("Pedro",10,80.52);
        System.out.println("A quantidade de clientes e: " + Cliente.getQdtCli());
    }

}
