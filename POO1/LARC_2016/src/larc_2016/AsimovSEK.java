/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package larc_2016;

/**
 *
 * @author 2023122760328
 */
public class AsimovSEK extends SEK{
    
    public AsimovSEK(int qtRobos, int qtMembros, int qtMaxMembros) {
        super(qtRobos, qtMembros, qtMaxMembros);
    }

    @Override
    public String jogar(Equipe outra) {
        return Equipe.definirVencedor(this, outra);
    }
    
    
}
