/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

import interfaces.LoginProvider;

/**
 *
 * @author lucas
 */
public class FacebookLoginAdapter extends FacebookAPI implements LoginProvider{

    @Override
    public boolean login(String email, String senha) {
        return this.autenticarUsuario(email, senha);
    }
    
}
