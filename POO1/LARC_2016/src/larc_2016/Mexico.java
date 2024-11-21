/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package larc_2016;

/**
 *
 * @author 2023122760328
 */
public class Mexico extends SEK{
    
    public Mexico(int qtRobos, int qtMembros, int qtMaxMembros) {
        super(qtRobos, qtMembros, qtMaxMembros);
        this.setDesempenho(5);
        
        
    }

    @Override
    public String jogar(Equipe outra) {
        this.setDesempenho(this.getDesempenho()-1);
        return Equipe.definirVencedor(this, outra);
    }
    
}
