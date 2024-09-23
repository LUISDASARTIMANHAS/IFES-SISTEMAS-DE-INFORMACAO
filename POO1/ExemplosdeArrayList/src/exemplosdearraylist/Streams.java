/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exemplosdearraylist;

import java.util.LinkedList;

public class Streams {

    public static void main(String[] args) {
        LinkedList<String> ls1 = new LinkedList<>();
        ls1.add("Pedro");
        ls1.add("Ana");
        ls1.add("Jaci");
        ls1.add("Paulo");
        ls1.add("Analto");

        ls1.stream().forEach(nome -> System.out.println(nome));

        LinkedList<String> ls2 = new LinkedList<>();
        ls1.stream().filter((nome) -> (nome.charAt(0) != 'P'))
                .forEachOrdered((nome) -> {
                    ls2.add(nome);
                });
        System.out.println(ls2);
    }

}
