/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package exemplosdearraylist;

import java.util.ArrayList;

public class ExemplosdeArrayList {

    public class UsaArrayList {

        public static void main(String[] args) {
            ArrayList als1 = new ArrayList();
            ArrayList als2 = new ArrayList(80);
            als1.add("1");
            als1.add("2");
            als1.add(1, "3");
            System.out.println(als1.get(1));
            System.out.println(als1.remove(0));
            System.out.println(als1.get(1));
            System.out.println(als1.set(0, "4"));
            als2.add("5");
            als2.addAll(als1);
            while (!als1.isEmpty()) {
                System.out.println(als1.remove(0));
            }
            ArrayList als3 = new ArrayList(als2);
        }
    }
}
