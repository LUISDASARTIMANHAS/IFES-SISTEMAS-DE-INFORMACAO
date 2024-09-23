/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exemplosdearraylist;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

public class LinkedListcomIterator {

    public static void main(String[] args) {
        ArrayList als1 = new ArrayList();
        LinkedList ls1 = new LinkedList();
        ls1.add(1);
        LinkedList ls2 = new LinkedList(ls1);
        ls1.addFirst(2);
        ls1.addLast(3);

        System.out.println(ls1.get(1));
        Iterator it = ls1.iterator();
//         it.remove();
        while (it.hasNext()) {
            System.out.println(it.next());
            it.remove();
        }

    }

}
