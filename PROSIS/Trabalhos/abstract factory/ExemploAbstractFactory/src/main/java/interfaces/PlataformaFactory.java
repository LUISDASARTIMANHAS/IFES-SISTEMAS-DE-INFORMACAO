/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package interfaces;

/**
 *
 * @author lucas
 */
public interface PlataformaFactory {
    Notificacao criarNotificacao(String mensagem);
    Toast criarToast(String mensagem);
}
