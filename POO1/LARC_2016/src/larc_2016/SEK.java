/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package larc_2016;

/**
 *
 * @author 2023122760328
 */
public abstract class SEK extends Equipe {

    private int qtRobos;

    public SEK(int qtRobos, int qtMembros, int qtMaxMembros) {
        super(qtMembros, qtMaxMembros);
        this.qtRobos = qtRobos;
    }

    public int getQtRobos() {
        return qtRobos;
    }

    @Override
    public String jogar(Equipe outra) {
        if (this.qtRobos == 3) {
            this.setDesempenho(this.getDesempenho() + 3);
        }
        return Equipe.definirVencedor(this, outra);

    }

}
