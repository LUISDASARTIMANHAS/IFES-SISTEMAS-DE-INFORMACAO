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
public abstract class Arquivo {
    protected String nomeDoArquivo;    
    public Arquivo(String nomeDoArquivo) {
        this.nomeDoArquivo = nomeDoArquivo;
    }
    public String getNomeDoArquivo() {
        return nomeDoArquivo;
    }
    public  void printNomeDoArquivo() {
	System.out.println(this.nomeDoArquivo);
    }
    
    public void adicionar(Arquivo novoArquivo) throws Exception{
        throw new Exception("Não pode inserir arquivos em: "
                + this.nomeDoArquivo + " - Não é uma pasta");
    }
    public void remover(String nomeDoArquivo) throws Exception {
        throw new Exception("Não pode remover arquivos em: "
                + this.nomeDoArquivo + " -Não é uma pasta");
    }
    public Arquivo obterArquivo(String nomeDoArquivo) throws Exception {
        throw new Exception("Não pode pesquisar arquivos em: "
                + this.nomeDoArquivo + " - Não é uma pasta");
    }
}

