/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

/**
 *
 * @author lucas
 */
public class GoogleAPI {
    public boolean autenticarComToken(String token) {
        System.out.println("Autenticando com token Google: " + token);
        return token.equals("token_google_valido");
    }

    public String gerarToken(String email, String senha) {
        return (email.equals("user@google.com") && senha.equals("1234")) ? "token_google_valido" : "token_invalido";
    }
}
