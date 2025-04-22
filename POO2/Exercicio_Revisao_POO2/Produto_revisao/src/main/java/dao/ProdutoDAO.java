package dao;

import domain.Categoria;
import domain.Produto;
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
public class ProdutoDAO {

    public void inserir(Produto prod) throws SQLException, ClassNotFoundException {
        // Insere todos os dados do produto no banco de dados       
        // Observe que o parâmetro é um objeto do tipo Produto (prod), 
        // portanto você deverá ler de um Frame os dados, criar um objeto 
        // do tipo Produto e passar como parâmetro para essa função
        //
        // O ID do produto é auto numeração
        //
        // INSERT INTO nome_tabela (CAMPOS separados por virgula)  VALUES 
        //    ( VALORES separados por vírgula )

        String sql = "INSERT INTO Categoria (nome,quantidade,preco,categoria) VALUES (?)";

        PreparedStatement stmt = ConexaoMySQL.obterConexao().prepareStatement(sql, PreparedStatement.RETURN_GENERATED_KEYS);

        int col = 1;
        stmt.setString(col++, prod.getNome());
        stmt.setInt(col++, prod.getQuantidade());
        stmt.setFloat(col++, prod.getPreco());
        stmt.setInt(col++, prod.getCategoria().getId());

        stmt.execute();

        // PEGAR O NÚMERO GERADO
        ResultSet rs = stmt.getGeneratedKeys();
        if (rs.next()) {
            int id = rs.getInt(1);
            prod.setId(id);
        }
    }

    public void alterar(Produto prod) {

        // Altera no banco os dados do produto
        // O código do produto deve ser um produto já inserido
        // Os demais campos são os novos dados
        // UPDATE nome_tabela SET campos = novos_valores
        //	WHERE campo_codigo = cod
    }

    public Produto pesquisar(int id) throws SQLException, ClassNotFoundException {

        // Pesquisa no banco pelo ID passado como parâmetro 
        //  e retorna um objeto do tipo Produto.
        //  Antes de retornar deve criar um objeto do tipo Produto.
        // SELECT * FROM nome_tabela WHERE campo_codigo = cod_pesquisa

        Statement stmt = ConexaoMySQL.obterConexao().createStatement();

        String sql = "SELECT * FROM Produto prod WHERE prod.idProduto < "+limite;

        ResultSet rs = stmt.executeQuery(sql);

        // Criar uma LISTA DE OBJETOS
        while (rs.next()) {
            Categoria temp = new Categoria(rs.getInt("idcategoria"), rs.getString("descricao"));
            Produto obj = new Produto(rs.getInt("idProduto"), rs.getString("nome"), rs.getInt("quantidade"), rs.getFloat("preco"), temp);
        }

        return obj;
    }

    public List<Produto> listar(int limite) throws ClassNotFoundException, SQLException {

        // Pesquisa no banco e retorna, através de um List, 
        // todos os produtos que estão com a quantidade abaixo
        // 	do limite
        // No seu Frame, chame essa função e preencha a tabela com o
        //	resultado do List
        // SELECT * FROM nome_tabela  WHERE qtde < limite
        // return lista;
        java.util.List<Produto> lista = new ArrayList();

        Statement stmt = ConexaoMySQL.obterConexao().createStatement();

        String sql = "SELECT * FROM Produto prod WHERE prod.quantidade < "+limite;

        ResultSet rs = stmt.executeQuery(sql);

        // Criar uma LISTA DE OBJETOS
        while (rs.next()) {
            Categoria temp = new Categoria(rs.getInt("idcategoria"), rs.getString("descricao"));
            Produto obj = new Produto(rs.getInt("idProduto"), rs.getString("nome"), rs.getInt("quantidade"), rs.getFloat("preco"), temp);
            lista.add(obj);
        }

        return lista;
    }

    public List<Produto> listar() throws SQLException, ClassNotFoundException {

        // Pesquisa no banco e retorna, através de um List,
        // todos os produtos
        // 	
        // No seu Frame, chame essa função e preencha a tabela com o
        //	resultado do List
        // SELECT * FROM nome_tabela 
        // return lista;
        java.util.List<Produto> lista = new ArrayList();

        Statement stmt = ConexaoMySQL.obterConexao().createStatement();

        String sql = "SELECT * FROM Produto";

        ResultSet rs = stmt.executeQuery(sql);

        // Criar uma LISTA DE OBJETOS
        while (rs.next()) {
            Categoria temp = new Categoria(rs.getInt("idcategoria"), rs.getString("descricao"));
            Produto obj = new Produto(rs.getInt("idProduto"), rs.getString("nome"), rs.getInt("quantidade"), rs.getInt("preco"), temp);
            lista.add(obj);
        }

        return lista;
    }

    public List<Produto> listar(Categoria cat) throws ClassNotFoundException, SQLException {

        // Pesquisa no banco e retorna, através de um List,
        // todos os produtos de uma determinada categoria
        // 	
        // No seu Frame, chame essa função e preencha a tabela com o
        //	resultado do List
        // SELECT * FROM nome_tabela WHERE idCategoria = id_parametro_pesq
        // return lista;
        java.util.List<Produto> lista = new ArrayList();

        Statement stmt = ConexaoMySQL.obterConexao().createStatement();

        String sql = "SELECT * FROM Produto prod WHERE prod.idCategoria = " +cat.getId();

        ResultSet rs = stmt.executeQuery(sql);

        // Criar uma LISTA DE OBJETOS
        while (rs.next()) {
            Categoria temp = new Categoria(rs.getInt("idcategoria"), rs.getString("descricao"));
            Produto obj = new Produto(rs.getInt("idProduto"), rs.getString("nome"), rs.getInt("quantidade"), rs.getInt("preco"), temp);
            lista.add(obj);
        }

        return lista;
    }

}
