/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package larc_2016;

/**
 *
 * @author 2023122760328
 */
public abstract class Soccer2D extends Equipe{
    private String caminhoLogo;
    
    public Soccer2D(String caminhoLogo, int qtMaxMembros, int qtMembros) {
        super(qtMaxMembros, qtMembros);
        this.caminhoLogo = caminhoLogo;
    }
    
}
