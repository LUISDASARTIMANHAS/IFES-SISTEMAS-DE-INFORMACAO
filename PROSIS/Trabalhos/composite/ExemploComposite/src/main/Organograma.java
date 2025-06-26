/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package main;

import classes.Empregado;
import classes.Funcionario;
import classes.Gerente;

/**
 *
 * @author lucas
 */
public class Organograma {
    public static void main(String[] args) {
        Funcionario gerenteGeral = new Gerente("Carlos", "Gerente Geral");
        Funcionario gerenteTI = new Gerente("Fernanda", "Gerente de Investimentos");

        Funcionario dev1 = new Empregado("João", "Analista de Crédito");
        Funcionario dev2 = new Empregado("Maria", "Atendente Comercial");

        gerenteTI.adicionar(dev1);
        gerenteTI.adicionar(dev2);

        gerenteGeral.adicionar(gerenteTI);

        gerenteGeral.exibirInformacoes();
    }
}
