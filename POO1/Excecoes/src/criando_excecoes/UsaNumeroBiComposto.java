/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package criando_excecoes;

public class UsaNumeroBiComposto {

    public static void main(String[] args) {
        NumeroBicomposto num1;
        try {
            num1 = new NumeroBicomposto(10, 16);
        } catch (ParException ex) {
            System.out.println(ex.getMessage());
        } catch (ImparException ex) {
            System.out.println(ex.getMessage());
        }
    }
}
