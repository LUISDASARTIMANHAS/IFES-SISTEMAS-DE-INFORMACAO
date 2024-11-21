/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package larc_2016;

/**
 *
 * @author 2023122760328
 */
public class Asimov2D extends Soccer2D{

    public Asimov2D(String caminhoLogo, int qtMaxMembros, int qtMembros) {
        super(caminhoLogo, qtMaxMembros, qtMembros);
    }

    @Override
    public String jogar(Equipe outra) {
        this.setDesempenho(this.getDesempenho()+1);
        return Equipe.definirVencedor(this, outra);
    }
    
    
}
