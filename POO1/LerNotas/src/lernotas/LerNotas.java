/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lernotas;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class LerNotas {

    public static void main(String[] args) {
        try {
            FileInputStream fil = new FileInputStream("notas.txt");
            Scanner scan = new Scanner(fil);
            
            int num1 = scan.nextInt();
            int num2 = scan.nextInt();
            double num3 = scan.nextDouble();
            System.out.println(num1 + num2);
            System.out.println(num3);
            scan.close();
        } catch (FileNotFoundException error) {
            System.out.println("Erro: Arquivo Não Encontrado. ERR:" + error);
        }
    }
    
}
