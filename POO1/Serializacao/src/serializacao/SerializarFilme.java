/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package serializacao;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Giovany
 */
public class SerializarFilme {
    private static void gravarFilme(Filme filme) {
        FileOutputStream arquivo;
        try {
            arquivo = new FileOutputStream("filme.txt");

            //Classe responsavel por inserir o filme
            ObjectOutputStream objGravar = new ObjectOutputStream(arquivo);

            //Grava o objeto filme no arquivo
            objGravar.writeObject(filme);
            objGravar.flush();
            objGravar.close();
            arquivo.flush();
            arquivo.close();

        } catch (FileNotFoundException ex) {
            Logger.getLogger(SerializarFilme.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(SerializarFilme.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static boolean estaArquivoVazio() throws FileNotFoundException, IOException {
        //Carrega o arquivo
        String local_arquivo = "filme.txt";
        FileInputStream arquivoLeitura = new FileInputStream(local_arquivo);
        boolean estaVazio = (arquivoLeitura.read() == -1);
        arquivoLeitura.close();
        return estaVazio;
    }

    private static Filme obterFilme() {
        Filme filme = null;
        try {
            if (!estaArquivoVazio()) {
                String local_arquivo = "filme.txt";
                FileInputStream arquivoLeitura = new FileInputStream(local_arquivo);
                ObjectInputStream objLeitura = new ObjectInputStream(arquivoLeitura);
                filme = (Filme)objLeitura.readObject();
                objLeitura.close();
                arquivoLeitura.close();
                
            }
        }  catch (FileNotFoundException ex) {
            Logger.getLogger(SerializarFilme.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(SerializarFilme.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(SerializarFilme.class.getName()).log(Level.SEVERE, null, ex);
        }
        return filme;
    }

    public static void main(String[] args) {
        Filme filme = new Filme();
        filme.setCodigo("10");
        filme.setNome("Pedro");
        filme.setGenero("Comedia");
        filme.setDatacompra("04/04/2012");
        filme.setProdutora("Warner");
        gravarFilme(filme);

        Filme filme2 = obterFilme();
        System.out.println("O código é " + filme2.getCodigo());
        System.out.println("O nome é " + filme2.getNome());
        System.out.println("O genero é " + filme2.getGenero());
        System.out.println("A data de compra é " + filme2.getDatacompra());
        System.out.println("A produtora é " + filme2.getProdutora());
    }
}
