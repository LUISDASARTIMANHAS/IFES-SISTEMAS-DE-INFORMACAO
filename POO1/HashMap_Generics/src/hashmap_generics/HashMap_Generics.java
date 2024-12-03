/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hashmap_generics;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author Giovany
 */
public class HashMap_Generics {
    public static void main(String[] args) {
        int capacidade_inicial = 20;     // O padrão é 16
        float fator_carga = (float) 0.9; // O padrão é 0.75
        Map<String, Pessoa> hash = new HashMap<String,Pessoa>(capacidade_inicial, fator_carga);
        Scanner leitor = new Scanner(System.in);
        // Lendo as Pessoas e colocando na HashMap (a chave será o cpf)
        for(int i=0; i<3; i++){
            System.out.println("Entre com o CPF");
            String cpf = leitor.next();
            System.out.println("Entre com o nome");
            String nome = leitor.next();
            Pessoa p = new Pessoa(cpf, nome);
            hash.put(cpf, p);
        }

        System.out.println("Digite o cpf da pessoa a ser buscada");
        String cpf = leitor.next();
        Pessoa pessoa;
        // Se xiste uma pessoa com esse cpf
        if (hash.containsKey(cpf)){
            // Obtem a pessoa com o cpf informado
            pessoa = hash.get(cpf);
            System.out.println(pessoa);
        }
        
        Set<String> chaves = hash.keySet();
        for(String chave: chaves){
            Pessoa p = hash.get(chave);
            System.out.println(p);
        }
    }
}
