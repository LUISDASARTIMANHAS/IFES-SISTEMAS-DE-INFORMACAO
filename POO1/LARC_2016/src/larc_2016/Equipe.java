/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package larc_2016;

/**
 *
 * @author 2023122760328
 */
public abstract class Equipe {

    private int qtMaxMembros;
    private int qtMembros;
    private int desempenho;
    private int qtPartidasDisputadas;

    public Equipe(int qtMembros, int qtMaxMembros) {
        this.qtMaxMembros = qtMaxMembros;
        this.qtMembros = qtMembros;
        this.desempenho = 1;
        this.qtPartidasDisputadas = 0;
    }

    public int getDesempenho() {
        return desempenho;
    }

    public void setDesempenho(int desempenho) {
        this.desempenho = desempenho;
    }
    
    public String jogar(Equipe outra) {
        qtPartidasDisputadas++;
        outra.qtPartidasDisputadas++;
        return "";
    }

    protected static String definirVencedor(Equipe equipe1, Equipe equipe2) {
        double valorEQuipe1 = Math.random();
        double valorEquipe2 = Math.random();
        if ((valorEQuipe1 * equipe1.getDesempenho()) > valorEquipe2 * equipe2.getDesempenho()) {
            return equipe1.getClass().getSimpleName() + " VENCEU " + equipe2.getClass().getSimpleName();
        } else {
            return equipe1.getClass().getSimpleName() + " PERDEU para " + equipe2.getClass().getSimpleName();
        }

    }
}
