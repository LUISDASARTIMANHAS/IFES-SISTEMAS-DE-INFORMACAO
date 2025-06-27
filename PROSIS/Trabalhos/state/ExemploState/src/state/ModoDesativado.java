/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package state;

import context.Mecha;

/**
 *
 * @author lucas
 */
public class ModoDesativado implements EstadoMecha {

    @Override
    public void detectarInimigo(Mecha mecha) {
        System.out.println("❌ Sistema offline. Sem resposta.");
    }

    @Override
    public void receberDano(Mecha mecha) {
        System.out.println("💀 Mecha já está desativado.");
    }

    @Override
    public void recuperarEnergia(Mecha mecha) {
        System.out.println("⚡ Sistema reiniciado! Voltando à patrulha.");
        mecha.setEstado(new ModoPatrulha());
    }

    @Override
    public void status() {
        System.out.println("[Modo: Desativado] Sistemas inativos...");
    }
    
}
