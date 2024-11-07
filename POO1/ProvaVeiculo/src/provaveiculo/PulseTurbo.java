package provaveiculo;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author 2023122760328
 */
public class PulseTurbo extends Carro {

    public PulseTurbo(int qtPortas, String fabricante, int anoFabricacao, int modelo, int cilindradas) {
        super(
                qtPortas,
                "Vermelho",
                "Branco",
                fabricante,
                anoFabricacao,
                modelo,
                cilindradas
        );
    }

    @Override
    public int getPotencia() {
        return super.getPotencia() + 500;
    }

}
