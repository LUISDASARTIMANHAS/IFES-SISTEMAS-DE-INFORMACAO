package primeiroprojeto;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.boot.Metadata;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;

import primeiroprojeto.model.domain.Usuario;
import primeiroprojeto.utils.PersistenceUtil;

public class TesteConexao {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

				
		//StandardServiceRegistry ssr = new StandardServiceRegistryBuilder().configure("hibernate.cfg.xml").build();  
        //Metadata meta = new MetadataSources(ssr).getMetadataBuilder().build();  
        
        
        //SessionFactory factory = meta.getSessionFactoryBuilder().build();  
        //Session session = factory.openSession();  
        
        Session session = PersistenceUtil.getSession();
        
        
        Transaction t = session.beginTransaction();  

        Usuario u = new Usuario();
        
        u.setNome("teste");
        
        session.save(u);
        
        t.commit();
        
        session.close();
        //factory.close();
        //ssr.close();
        
		
	}

}
