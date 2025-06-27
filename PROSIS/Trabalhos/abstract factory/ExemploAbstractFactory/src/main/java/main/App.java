/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package main;

import classes.AndroidFactory;
import classes.WebFactory;
import classes.iOSFactory;
import interfaces.Notificacao;
import interfaces.PlataformaFactory;
import interfaces.Toast;

/**
 *
 * @author lucas
 */
public class App {
    public static void main(String[] args) {
        String plataformaSelecionada = "ios"; // Pode ser "android", "ios", "web"

        PlataformaFactory fabrica = criarFabrica(plataformaSelecionada);

        if (fabrica == null) {
            System.out.println("Plataforma inválida.");
            return;
        }

        // Criando objetos e exibindo mensagens
        Notificacao notificacao = fabrica.criarNotificacao("Bem-vindo ao sistema!");
        Toast toast = fabrica.criarToast("Login efetuado com sucesso!");

        // (Opcional) Reutilizar objetos, se necessário:
        notificacao.exibir("Bem-vindo ao sistema!");
        toast.mostrar("Login efetuado com sucesso!");
    }

    private static PlataformaFactory criarFabrica(String plataforma) {
        switch (plataforma.toLowerCase()) {
            case "android": return new AndroidFactory();
            case "ios":     return new iOSFactory();
            case "web":     return new WebFactory();
            default:        return null;
        }
    }
}
