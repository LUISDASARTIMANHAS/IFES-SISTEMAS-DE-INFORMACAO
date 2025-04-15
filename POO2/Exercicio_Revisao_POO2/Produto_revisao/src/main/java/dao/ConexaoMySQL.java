/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author 1547816
 */
public class ConexaoMySQL {
    private static Connection conexao;
    
    public static Connection obterConexao() throws ClassNotFoundException, SQLException {
        
        // String url = "jdbc:mysql://id_servidor:porta/nome_banco";
        
        
        // MYSQL       
        String url = "jdbc:mysql://127.0.0.1:3306/estoque";
        String user = "root";
        String password = "";
        
        Class.forName("com.mysql.cj.jdbc.Driver");
            
        
        /* 
        // POSTGRESQL
        String url = "jdbc:postgresql://26.223.217.196:5432/Hotel";
        String user = "postgres";
        String password = "postgres";
        
        Class.forName("org.postgresql.Driver");
        */
                
        conexao = DriverManager.getConnection(url, user, password);
        return conexao;
        
        
    }
            
}
