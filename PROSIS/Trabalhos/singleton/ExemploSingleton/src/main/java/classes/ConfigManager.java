/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

/**
 *
 * @author lucas
 */
public class ConfigManager {

    private static ConfigManager instancia;

    private Properties propriedades;

    private ConfigManager() {
        propriedades = new Properties();
        carregarArquivo("config.properties");
    }

    public static ConfigManager getInstance() {
        if (instancia == null) {
            instancia = new ConfigManager();
        }
        return instancia;
    }

    private void carregarArquivo(String caminhoArquivo) {
        try (FileInputStream input = new FileInputStream(caminhoArquivo)) {
            propriedades.load(input);
        } catch (IOException e) {
            System.err.println("Erro ao carregar arquivo de configuração: " + e.getMessage());
        }
    }

    public String get(String chave) {
        return propriedades.getProperty(chave);
    }

    public void set(String chave, String valor) {
        propriedades.setProperty(chave, valor);
    }

    public void listarTudo() {
        propriedades.forEach((k, v) -> System.out.println(k + ": " + v));
    }
}
