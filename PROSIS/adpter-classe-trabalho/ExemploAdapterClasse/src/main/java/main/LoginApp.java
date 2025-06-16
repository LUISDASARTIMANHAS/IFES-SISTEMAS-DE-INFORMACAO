/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package main;

import classes.FacebookLoginAdapter;
import classes.GitHubLoginAdapter;
import classes.GoogleLoginAdapter;
import interfaces.LoginProvider;

/**
 *
 * @author lucas
 */
public class LoginApp {
    public static void main(String[] args) {
        testarLogin(new GoogleLoginAdapter(), "user@google.com", "1234");
        testarLogin(new FacebookLoginAdapter(), "user@facebook.com", "senha123");
        testarLogin(new GitHubLoginAdapter(), "user@github.com", "abc123");
    }

    public static void testarLogin(LoginProvider provider, String email, String senha) {
        System.out.println("Tentando login com " + provider.getClass().getSimpleName());
        boolean sucesso = provider.login(email, senha);
        System.out.println("Login " + (sucesso ? "bem-sucedido!" : "falhou!") + "\n");
    }
}
