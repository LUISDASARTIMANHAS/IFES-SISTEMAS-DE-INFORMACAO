package provaveiculo;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author 2023122760328
 */
public class Moto extends Veiculo {

    private String cor;

//    Veiculo v3 = new Moto("Preta", "Custom", 2015, 2015, 800, 3);
    public Moto(String cor, String fabricante, int anoFabricacao, int modelo, int cilindradas, int qtRodas) {
        super(fabricante, anoFabricacao, modelo, cilindradas, qtRodas);
        this.cor = cor;
    }

//    Veiculo v4 = new Moto("Custom", 2015, 2015, 800, 2);
    public Moto(String fabricante, int anoFabricacao, int modelo, int cilindradas, int qtRodas) {
        super(fabricante, anoFabricacao, modelo, cilindradas, qtRodas);
        this.cor = "Incolor";
    }

    public String getCor() {
        return cor;
    }

    @Override
    public int getPotencia() {
        return this.getCilindradas() / this.getQtRodas();
    }

}
