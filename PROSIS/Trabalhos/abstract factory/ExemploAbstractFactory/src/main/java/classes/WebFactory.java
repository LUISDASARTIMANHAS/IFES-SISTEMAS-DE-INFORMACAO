/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

import interfaces.Notificacao;
import interfaces.PlataformaFactory;
import interfaces.Toast;

/**
 *
 * @author lucas
 */
public class WebFactory implements PlataformaFactory {

    @Override
    public Notificacao criarNotificacao(String mensagem) {
        Notificacao notificacao = new WebNotificacao();
        return notificacao;
    }

    @Override
    public Toast criarToast(String mensagem) {
        Toast toast = new WebToast();
        return toast;
    }
}