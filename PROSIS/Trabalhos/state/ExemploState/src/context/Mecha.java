/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package context;

import state.EstadoMecha;
import state.ModoPatrulha;
/**
 *
 * @author lucas
 */
public class Mecha {
    private EstadoMecha estadoAtual;

    public Mecha() {
        this.estadoAtual = new ModoPatrulha(); // Estado inicial
    }

    public void setEstado(EstadoMecha novoEstado) {
        this.estadoAtual = novoEstado;
    }

    public void detectarInimigo() {
        estadoAtual.detectarInimigo(this);
    }

    public void receberDano() {
        estadoAtual.receberDano(this);
    }

    public void recuperarEnergia() {
        estadoAtual.recuperarEnergia(this);
    }

    public void status() {
        estadoAtual.status();
    }
}
