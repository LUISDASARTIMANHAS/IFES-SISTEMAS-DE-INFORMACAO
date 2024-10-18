/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package usandocomparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class UsandoComparable {

    public static void main(String[] args) {
        ArrayList<Pessoa> pessoas = new ArrayList(10);
        Pessoa p;
        pessoas.add(new Pessoa("Pedro", 10));
        pessoas.add(new Pessoa("Medro", 5));
        pessoas.add(new Pessoa("Ane", 20));
        pessoas.add(new Pessoa("Zana", 30));
        pessoas.add(new Pessoa("Tina", 15));
        Collections.sort(pessoas);
        Iterator<Pessoa> it = pessoas.iterator();
        
        while (it.hasNext()) {
            p = it.next();
            System.out.println(p);
        }
    }

}
