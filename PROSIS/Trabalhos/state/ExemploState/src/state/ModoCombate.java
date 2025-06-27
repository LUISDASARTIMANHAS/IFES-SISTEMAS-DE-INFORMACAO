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
public class ModoCombate implements EstadoMecha{

    @Override
    public void detectarInimigo(Mecha mecha) {
        System.out.println("🎯 Alvo já está em combate!");
    }

    @Override
    public void receberDano(Mecha mecha) {
        System.out.println("💥 Dano pesado! Ativando modo defensivo!");
        mecha.setEstado(new ModoDefensivo());
    }

    @Override
    public void recuperarEnergia(Mecha mecha) {
        System.out.println("⚠️ Não é seguro recarregar em combate!");
    }

    @Override
    public void status() {
        System.out.println("[Modo: Combate] Atacando o inimigo!");
    }
    
}
