/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

/**
 *
 * @author lucas
 */
public class GitHubAPI {
    public boolean acessarViaREST(String email, String senha) {
        System.out.println("Enviando login via REST para GitHub");
        return email.equals("user@github.com") && senha.equals("abc123");
    }
}
