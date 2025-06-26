/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package application;

import context.Mecha;

/**
 *
 * @author lucas
 */
public class Main {
    public static void main(String[] args) {
        Mecha mecha = new Mecha();

        mecha.status();              // Patrulha
        mecha.detectarInimigo();     // → Combate
        mecha.status();              // Combate
        mecha.receberDano();         // → Defensivo
        mecha.status();              // Defensivo
        mecha.receberDano();         // → Desativado
        mecha.status();              // Desativado
        mecha.recuperarEnergia();    // → Patrulha
        mecha.status();              // Patrulha
    }
}
