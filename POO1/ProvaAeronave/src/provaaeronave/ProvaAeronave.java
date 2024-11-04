/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package provaaeronave;

/**
 *
 * @author 2023122760328
 */
public class ProvaAeronave {

    public static void main(String[] args) {
        // Toda Aeronave possui fabricante, ano de fabricação, ano do modelo, capacidade de carga e quantidade de misseis (nessa ordem)
        // Todo Gripen possui fabricante, ano de fabricação, ano do modelo, capacidade de carga e avionica (nessa ordem)
        // Note que para um Gripen não é necessário informar a quantidade de misseis pois são sempre 6
        Aeronave a1 = new Gripen("Saab", 2023, 2024, 2000, 8);
        System.out.println("A capacidadde de ataque de a1 é " + a1.getCapacidadeAtaque());

        // Apaches possuem fabricante, ano de fabricação, ano do modelo, capacidade de carga e quantidade de misseis
        // Note que para Apaches não é necessário informar a quantidade de helices e a potencia do motor pois esses valores são
        // fixos em 5 e 3000 respectivamente
        Aeronave a2 = new Apache("Apache Corp", 2022, 2021, 4000, 8);
        System.out.println("A capacidadde de ataque de a2 é " + a2.getCapacidadeAtaque());

        // Caças possuem fabricante, ano de fabricação, ano do modelo, capacidade de carga, quantidade de misseis e avionica
        Aeronave a3 = new Caca("MIG", 2000, 1999, 1900, 4, 6);
        System.out.println("A capacidadde de ataque de a3 é " + a3.getCapacidadeAtaque());

        // Nesse caso a quantidade de misseis é 4 e a avionica é 3
        Aeronave a4 = new Caca("MIG", 2000, 1999, 1900, 4, 6);
        System.out.println("A capacidadde de ataque de a4 é " + a4.getCapacidadeAtaque());

        System.out.println("O ano de fabricação de a1 é " + a1.getAnoFabricacao());
        System.out.println("O ano de modelo de a1 é " + a1.getAnoModelo());
        System.out.println("A quantidade de misseis de a1 é " + a1.getQuantidadeMisseis());
        System.out.println("A capacidade de carga de a1 é " + a1.getCapacidadeCarga());
        Gripen grip = (Gripen) a1;
        System.out.println("A avionica de a1 é " + grip.getAvionica());

        Helicoptero heli = (Helicoptero) a2;
        System.out.println("A potência do motor de a2 é " + heli.getPotenciaMotor());
        System.out.println("A quantidade de helices de a2 é " + heli.getQuantidadeHelices());
    }
}
