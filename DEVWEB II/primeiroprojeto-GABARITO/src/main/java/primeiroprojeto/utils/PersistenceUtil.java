package primeiroprojeto.utils;



import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.boot.Metadata;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import org.hibernate.cfg.Configuration;
import org.hibernate.service.ServiceRegistry;

public class PersistenceUtil {

	private static Session s = null;
	
	public static Session getSession() {
		
		if (s == null) {
			StandardServiceRegistry ssr = new StandardServiceRegistryBuilder().configure("hibernate.cfg.xml").build();  
	        Metadata meta = new MetadataSources(ssr).getMetadataBuilder().build();  
	        
	        SessionFactory factory = meta.getSessionFactoryBuilder().build();  
	        s = factory.openSession();   
	        
	        //Configuration configuration = new Configuration();
	        //configuration.configure();
	        //ServiceRegistry serviceRegistry = new StandardServiceRegistryBuilder().applySettings(configuration.getProperties()).build();
	        //SessionFactory sessionFactory = configuration.buildSessionFactory(serviceRegistry);
	        
	        //s = sessionFactory.openSession();
	       
		}
		
		return s;
	}
		
}
