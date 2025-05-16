/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package composite;

/**
 *
 * @author Giovany
 */
public class ArquivoDOC extends Arquivo{
    public ArquivoDOC(String nomeDoArquivo) {
        super(nomeDoArquivo);
    }
    @Override
    public void printNomeDoArquivo() {
        System.out.println(this.nomeDoArquivo + ".DOC");
    }
}
