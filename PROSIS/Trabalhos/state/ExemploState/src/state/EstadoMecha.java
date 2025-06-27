/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package state;

import context.Mecha;

/**
 *
 * @author lucas
 */
public interface EstadoMecha {
    void detectarInimigo(Mecha mecha);
    void receberDano(Mecha mecha);
    void recuperarEnergia(Mecha mecha);
    void status();
}
