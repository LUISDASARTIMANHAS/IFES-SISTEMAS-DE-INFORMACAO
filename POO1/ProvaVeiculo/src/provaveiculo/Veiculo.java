package provaveiculo;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author 2023122760328
 */
public abstract class Veiculo {

    private String fabricante;
    private int anoFabricacao;
    private int modelo;
    private int cilindradas;
    protected int qtRodas;

    public Veiculo(String fabricante, int anoFabricacao, int modelo, int cilindradas, int qtRodas) {
        this.fabricante = fabricante;
        this.anoFabricacao = anoFabricacao;
        this.modelo = modelo;
        this.cilindradas = cilindradas;
        this.qtRodas = qtRodas;
    }

    public abstract int getPotencia();

    public String getFabricante() {
        return fabricante;
    }

    public int getAno_fabricacao() {
        return anoFabricacao;
    }

    public int getAno_modelo() {
        return modelo;
    }

    public int getCilindradas() {
        return cilindradas;
    }

    public int getQtRodas() {
        return qtRodas;
    }

}
