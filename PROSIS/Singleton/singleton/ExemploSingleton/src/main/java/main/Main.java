/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package main;

import classes.ConfigManager;

/**
 *
 * @author lucas
 */
public class Main {
    public static void main(String[] args) {
        ConfigManager config = ConfigManager.getInstance();
//        ConfigManeger config = new ConfigManeger();

        System.out.println("Idioma: " + config.get("idioma"));
        System.out.println("Usuário: " + config.get("usuario"));

        config.set("tema", "claro");

        System.out.println("\nTodas as configurações:");
        config.listarTudo();
        
    }
}
