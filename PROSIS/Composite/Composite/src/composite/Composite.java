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
public class Composite {
    public static void main(String[] args) {
        try {
            Arquivo arq1 = new ArquivoDOC("texto1");
            Arquivo arq2 = new ArquivoTXT("texto2");

            arq1.printNomeDoArquivo();
            arq2.printNomeDoArquivo();

            Arquivo pasta1 = new Pasta("Pasta1");
            Arquivo pasta2 = new Pasta("Pasta2");
            pasta2.adicionar(arq1);
            pasta2.adicionar(arq2);
            pasta2.printNomeDoArquivo();

            pasta1.adicionar(pasta2);
            pasta1.printNomeDoArquivo();
            
            arq1.adicionar(arq2);

        } catch (Exception erro) {
            System.out.println("ERRO: " + erro.getMessage());
        }
    }
}

