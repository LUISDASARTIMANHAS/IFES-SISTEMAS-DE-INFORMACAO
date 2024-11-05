/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package usandodrones;

/**
 *
 * @author 2023122760328
 */
public class UsandoDrones {

    public static void main(String[] args) {
        // Parâmetros (nessa ordem): autonomia de voo, numero de série, ano de fabricação
        DroneVoador v1 = new DroneVoador(13, 20001, 2023);
        // Parâmetros (nessa ordem): numero de série, ano de fabricação
        Drone v2 = new Tello(20001, 2023);
        // Dois Drones são equivalentes se seu número de série é equivalente
        // Isso ocorre independente do tipo do Drone
        if (v1.equals(v2)) {
            System.out.println("São iguais: \n v1 = " + v1
                    + " \n v2 = " + v2);
            System.out.println("Valor de v1 = " + v1.getValor());
            System.out.println("Valor de v2 = " + v1.getValor());
            System.out.println("Autonomia de voo de v1 = " + v1.getAutonomiaVoo());
            System.out.println("Autonomia de voo de v2 = " + ((Tello) v2).getAutonomiaVoo());
        }

        // Parâmetros (nessa ordem): resolução visual, numero de série, ano de fabricação
        Mavic m1 = new ProFly(500.3, 20008, 2022);
        // Parâmetros (nessa ordem): resolução visual, numero de série, ano de fabricação
        Mavic m2 = new ClassicDJI(300.7, 20033, 2022);
        if (!m1.equals(m2)) {
            System.out.println("Valor de m1 = " + m1.getValor());
            System.out.println("Valor de m2 = " + m2.getValor());
        }

        System.out.println("Resolução Visual de m1 = " + m1.getResolucaoVisual());
        System.out.println("Resolução Visual de m2 = " + m2.getResolucaoVisual());
        m1.setResolucaoVisual(700.23);
        m2.setResolucaoVisual(800.67);
        System.out.println("Resolução Visual de m1 = " + m1.getResolucaoVisual());
        System.out.println("Resolução Visual de m2 = " + m2.getResolucaoVisual());

        System.out.println("Valor de m1 = " + m1.getValor());
        System.out.println("Valor de m2 = " + m2.getValor());

        System.out.println("Autonomia de voo de m1 = " + m1.getAutonomiaVoo());
        System.out.println("Autonomia de voo de m2 = " + m2.getAutonomiaVoo());
    }
}
