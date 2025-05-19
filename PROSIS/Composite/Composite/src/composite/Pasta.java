/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package composite;

import java.util.ArrayList;

/**
 *
 * @author Giovany
 */
public class Pasta extends Arquivo {
    protected ArrayList<Arquivo> arquivos;
    public Pasta(String nomeDoArquivo) {
        super(nomeDoArquivo);
        this.arquivos = new ArrayList<>();
    }
    @Override
    public void printNomeDoArquivo() {
        System.out.println(this.nomeDoArquivo);
        arquivos.forEach((arquivo) -> {
            arquivo.printNomeDoArquivo();
        });
    }
    @Override
    public void adicionar(Arquivo novoArquivo) {
        this.arquivos.add(novoArquivo);
    }
    @Override
    public void remover(String nomeDoArquivo) throws Exception {
        for (Arquivo arquivo : arquivos) {
            if (arquivo.getNomeDoArquivo().equals(nomeDoArquivo)) {
                this.arquivos.remove(arquivo);
                return;
            }
        }
        throw new Exception("Não existe este arquivo");
    }
    @Override
    public Arquivo obterArquivo(String nomeDoArquivo) throws Exception {
        for (Arquivo arquivo : arquivos) {
            if (arquivo.getNomeDoArquivo().equals(nomeDoArquivo)) {
                return arquivo;
            }
        }
        throw new Exception("Não existe este arquivo");
    }
}
