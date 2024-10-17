/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package UsandoComparator;

import java.util.Comparator;
import usandocomparable.Pessoa;

public class ComparadorPessoaPorNomeCrescente implements Comparator<Pessoa> {

    @Override
    public int compare(Pessoa o1, Pessoa o2) {
        return o1.getNome().compareTo(o2.getNome());
    }
}
