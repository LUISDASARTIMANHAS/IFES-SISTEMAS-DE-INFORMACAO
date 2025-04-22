
package dao;

import domain.Categoria;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author jean_
 */
public class CategoriaDAO {
          
    public void inserir(Categoria cat) throws SQLException, ClassNotFoundException{
        // Insere todos os dados da categoria no banco de dados       
	// Observe que o parâmetro é um objeto do tipo Categoria, 
        // portanto você deverá ler de um Frame os dados, criar um objeto 
        // do tipo Categoria e passar como parâmetro para essa função
        //
        // O ID da categoria é auto numeração
	//
	// INSERT INTO nome_tabela (CAMPOS separados por virgula)  VALUES 
        //    ( VALORES separados por vírgula )
        
        String sql = "INSERT INTO Categoria (descricao) VALUES (?)";
        
        PreparedStatement stmt = ConexaoMySQL.obterConexao().prepareStatement(sql, PreparedStatement.RETURN_GENERATED_KEYS);
        
        int col = 1;
        stmt.setString(col++, cat.getDescricao());
        
        stmt.execute();
                       
        // PEGAR O NÚMERO GERADO
        ResultSet rs = stmt.getGeneratedKeys();
        if ( rs.next() ) {
            int id = rs.getInt(1);            
            cat.setId(id);
        }
        
    }

    
    public List<Categoria> listar() throws SQLException, ClassNotFoundException{

	// Pesquisa no banco e retorna, através de um List,
        // todas as categorias
        // 	
        // No seu Frame, chame essa função e preencha o combobox com o
        //	resultado do List
        // SELECT * FROM nome_tabela 
        // return lista;
        
        java.util.List<Categoria> lista = new ArrayList();
        
        Statement stmt = ConexaoMySQL.obterConexao().createStatement();
        
        String sql = "SELECT * FROM Categoria";
        
        ResultSet rs = stmt.executeQuery(sql);
        
        // Criar uma LISTA DE OBJETOS
        while ( rs.next() ) {
            Categoria obj = new Categoria(  rs.getInt("idCategoria")  , rs.getString("nome")  );
            lista.add(obj);                        
        }
        
        return lista;
    }
    


    
}
