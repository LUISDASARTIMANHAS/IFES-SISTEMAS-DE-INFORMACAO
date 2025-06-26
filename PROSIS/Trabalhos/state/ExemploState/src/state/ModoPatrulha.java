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
public class ModoPatrulha implements EstadoMecha {

    @Override
    public void detectarInimigo(Mecha mecha) {
        System.out.println("⚠️ Inimigo detectado! Entrando em modo de combate.");
        mecha.setEstado(new ModoCombate());
    }

    @Override
    public void receberDano(Mecha mecha) {
        System.out.println("🛡️ Dano leve recebido. Entrando em modo defensivo.");
        mecha.setEstado(new ModoDefensivo());
    }
    
    @Override
    public void recuperarEnergia(Mecha mecha) {
        System.out.println("🔋 Energia já está cheia. Continuando patrulha.");
    }

    @Override
    public void status() {
        System.out.println("[Modo: Patrulha] Monitorando área...");
    }
    
}
