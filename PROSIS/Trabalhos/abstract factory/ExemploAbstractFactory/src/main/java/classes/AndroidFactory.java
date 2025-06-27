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
public class AndroidFactory implements PlataformaFactory {

    @Override
    public Notificacao criarNotificacao(String mensagem) {
        Notificacao notificacao = new AndroidNotificacao();
        return notificacao;
    }

    @Override
    public Toast criarToast(String mensagem) {
        Toast toast = new AndroidToast();
        return toast;
    }
}
