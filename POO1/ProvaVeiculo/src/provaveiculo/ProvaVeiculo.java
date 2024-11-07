/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package provaveiculo;

public class ProvaVeiculo {

    public static void main(String[] args) {
        // Todo Veiculo possui fabricante, ano_fabricacao,  ano_modelo,  cilindradas, qt_rodas
        // Todo PulseTurbo possui qt_portas, fabricante, ano_fabricacao, ano_modelo, cilindradas)
        // Note que para o PulseTurbo não é necessário informar a cor_carroceria e a cor_teto pois 
        // são fixas em "Vermelho" e "Branco" respectivamente
        Veiculo v1 = new PulseTurbo(5, "Fiat", 2022, 2022, 1600);
        System.out.println("A potência de v1 é " + v1.getPotencia());
   
        //  Toda CG500 possui fabricante, ano_fabricacao, ano_modelo, cilindradas, qt_rodas
        Veiculo v2 = new CG500("Honda", 2018, 2019, 500, 2);
        
        // Motos podem informar ou não a cor (quando não informada a cor é "Incolor"
        Veiculo v3 = new Moto("Preta", "Custom", 2015, 2015, 800, 3);
        Veiculo v4 = new Moto("Custom", 2015, 2015, 800, 2);
        if (v3.getAno_fabricacao() == v3.getAno_modelo() && (v4.getAno_fabricacao() == v4.getAno_modelo())) {
            System.out.println("Os veículos são de inicio de ano");
            if (v3.getAno_fabricacao() == v4.getAno_fabricacao()) {
                System.out.println("Os veículos são do mesmo ano");
            }
        }
        System.out.println("A potência de v2 é " + v2.getPotencia() + " e sua cor é " + ((Moto) v2).getCor());
        System.out.println("A potência de v3 é " + v3.getPotencia() + " e sua cor é " + ((Moto) v3).getCor());
        System.out.println("A potência de v4 é " + v4.getPotencia() + " e sua cor é " + ((Moto) v4).getCor());
        // Linha inválida => Veiculo v5 = new CG500("Azul", "Honda", 2018, 2019, 500, 2);
        // Todo Carro possui qt_portas, cor_carroceria, cor_teto, fabricante, ano_fabricacao, ano_modelo, cilindradas
        // Linha inválida => Veiculo v6 = new Carro(5, "Verde", "Rosa", "Mangueira", 2013, 2013, 0);
    }
}
