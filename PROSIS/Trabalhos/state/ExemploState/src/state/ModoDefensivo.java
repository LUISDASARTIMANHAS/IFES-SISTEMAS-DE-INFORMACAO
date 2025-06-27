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
public class ModoDefensivo implements EstadoMecha {

    @Override
    public void detectarInimigo(Mecha mecha) {
        System.out.println("👀 Inimigo ainda presente. Defesas ativas.");
    }

    @Override
    public void receberDano(Mecha mecha) {
        System.out.println("❌ Sobrecarga! Mecha desativado!");
        mecha.setEstado(new ModoDesativado());
    }

    @Override
    public void recuperarEnergia(Mecha mecha) {
        System.out.println("🔋 Energia estabilizada. Retornando à patrulha.");
        mecha.setEstado(new ModoPatrulha());
    }

    @Override
    public void status() {
        System.out.println("[Modo: Defensivo] Escudos elevados. Movimentos limitados.");
    }
    
}
