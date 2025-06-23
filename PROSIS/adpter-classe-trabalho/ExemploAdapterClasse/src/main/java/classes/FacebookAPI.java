/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

/**
 *
 * @author lucas
 */
public class FacebookAPI {
    public boolean autenticarUsuario(String usuario, String senha) {
        System.out.println("Autenticando no Facebook: " + usuario);
        return usuario.equals("user@facebook.com") && senha.equals("senha123");
    }
}
