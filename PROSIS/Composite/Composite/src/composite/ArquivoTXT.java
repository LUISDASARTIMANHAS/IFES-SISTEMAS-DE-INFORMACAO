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
public class ArquivoTXT extends Arquivo{
    
    public ArquivoTXT(String nomeDoArquivo) {
        super(nomeDoArquivo);
    }
    @Override
    public void printNomeDoArquivo() {
        System.out.println(this.nomeDoArquivo + ".TXT");
    }    
}
