/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package passagemparametros;

public class PassagemParametros {

    public static void main(String[] args) {
        System.out.println("O tamanho do array é:" + args.length);

        System.out.println(args[2] + ". " + args[0] + " " + args[1]);

        double nota1, nota2, trabalho1, trabalho2, media;
        nota1 = Double.parseDouble(args[0]);
        nota2 = Double.parseDouble(args[1]);
        trabalho1 = Double.parseDouble(args[2]);
        trabalho2 = Double.parseDouble(args[3]);
        media = (nota1 + nota2 + trabalho1 + trabalho2) / 4;
        System.out.println("Média = " + media);
    }

}
