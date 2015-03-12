import java.net.InetSocketAddress;
import java.net.InetAddress;
import net.spy.memcached.MemcachedClient;
public class MemcachedJava {
	public static void main(String[] args) throws Exception{
		//Connecting to Memcached server on localhost
		MemcachedClient mcc = new MemcachedClient(new InetSocketAddress("127.0.0.1", 11211));
		System.out.println("Connection to server sucessfully");
		System.out.println("set status:"+mcc.set("tutorialspoint", 900, "memcached"));
		//Get value from cache
		System.out.println("Get from Cache:"+mcc.get("tutorialspoint"));
	}
}
