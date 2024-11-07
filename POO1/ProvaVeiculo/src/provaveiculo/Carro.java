package provaveiculo;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author 2023122760328
 */
public abstract class Carro extends Veiculo {

    private int qtPortas;
    private String corCarroceria;
    private String corTeto;

    public Carro(int qtPortas,String corCarroceria, String corTeto, String fabricante, int anoFabricacao, int modelo, int cilindradas) {
        super(fabricante, anoFabricacao, modelo, cilindradas, 4);

        this.qtPortas = qtPortas;
        this.corCarroceria = corCarroceria;
        this.corTeto = corTeto;
    }

    @Override
    public int getPotencia() {
        return this.getCilindradas() * qtPortas / 4;
    }
}
