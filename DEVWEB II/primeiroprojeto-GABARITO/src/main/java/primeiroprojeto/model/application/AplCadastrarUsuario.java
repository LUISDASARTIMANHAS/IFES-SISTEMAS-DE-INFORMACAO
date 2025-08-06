package primeiroprojeto.model.application;

import org.hibernate.Session;
import org.hibernate.Transaction;

import primeiroprojeto.model.domain.Usuario;
import primeiroprojeto.utils.PersistenceUtil;

public class AplCadastrarUsuario {
	
	
	public static int incluirUsuario(String nome) {
		
		if ((nome == null) || nome.equals(""))
			return 1;
		
		Usuario u = new Usuario();
		u.setNome(nome);
		
		Session s = PersistenceUtil.getSession();
		Transaction t = null;
		
		try {
		
			t = s.beginTransaction();
			
			s.save(u);
			
			t.commit();
			
			return 0;
			
		}catch(Exception e) {
			
			t.rollback();
			System.out.println(e.getMessage());
			e.printStackTrace();

			return 2;
			
		}finally {
			
			//s.close();
		}
		
	}

}
