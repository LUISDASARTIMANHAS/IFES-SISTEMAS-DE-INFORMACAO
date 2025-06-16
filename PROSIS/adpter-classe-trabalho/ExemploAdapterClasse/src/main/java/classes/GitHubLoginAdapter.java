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
public class GitHubLoginAdapter extends GitHubAPI implements LoginProvider{

    @Override
    public boolean login(String email, String senha) {
        return this.acessarViaREST(email, senha);
    }
}
