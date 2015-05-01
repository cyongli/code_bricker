import java.util.HashMap;


public class HashMap_Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashMap<String,String> hash = new HashMap<String,String>();
		for(int i=0;i<10000000;++i){
			hash.put("key"+i, "value");
		}
		System.out.println(hash.size());
		while(true);
	}

}
