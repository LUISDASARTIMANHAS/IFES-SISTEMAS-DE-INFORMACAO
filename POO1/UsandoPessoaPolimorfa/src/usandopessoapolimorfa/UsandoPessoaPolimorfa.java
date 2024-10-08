/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package usandopessoapolimorfa;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class UsandoPessoaPolimorfa {

    public static void main(String[] args) {
        Pessoa pessoa = null;
        BufferedReader dado;
        String s;
        try {
            System.out.println(
                    "Digite que objeto deseja criar:");
            System.out.println("1 - Pessoa");
            System.out.println("2 - Pessoa Física ");
            System.out.println("3 - Pessoa Juridica");
            System.out.println("4 - Funcionário");

            dado = new BufferedReader(new InputStreamReader(System.in));
            s = dado.readLine();
            switch (Integer.parseInt(s)) {
                case 1:
                    pessoa = new Pessoa("Lucas",30);
                    break;
                case 2:
                    pessoa = new PessoaFisica("qqq",30);
                    break;
                case 3:
                    pessoa = new PessoaJuridica("123","asd",30);
                    break;
                case 4:
                    pessoa = new Funcionario("qqq","555",30);
                    break;
                default:
                    System.out.println("tipo desconhecido");
            }

            pessoa.imprimirNomeClasse();
        } catch (IOException erro) {
            System.out.println("Erro na entrada de dados");
        } catch (NumberFormatException erro) {
            System.out.println("Digite apenas números inteiros");
        }
    }
}
