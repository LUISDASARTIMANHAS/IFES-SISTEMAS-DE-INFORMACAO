/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package UsandoComparator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import usandocomparable.Pessoa;

public class UsandoComparator {
    public static void main(String[] args) {
        ArrayList<Pessoa> pessoas = new ArrayList(10);
        Pessoa p;
        pessoas.add(new Pessoa("Pedro", 10));
        pessoas.add(new Pessoa("Medro", 5));
        pessoas.add(new Pessoa("Ane", 20));
        pessoas.add(new Pessoa("Zana", 30));
        pessoas.add(new Pessoa("Tina", 15));
        Collections.sort(pessoas, new ComparadorPessoaPorNomeDecrescente());
        Iterator<Pessoa> it = pessoas.iterator();
        
        while (it.hasNext()) {
            p = it.next();
            System.out.println(p);
        }
    }
}
