
public class StaticAndVolatile extends Thread{
	private volatile int condition;
	
	public void setCond(int condition){
		this.condition = condition;
	}

	public void run(){
		System.out.println(condition);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StaticAndVolatile[] test = new StaticAndVolatile[2];
		for(int i=0;i<2;i++){
			test[i] = new StaticAndVolatile();
			test[i].setCond(i);
			test[i].start();
		}
	}

}
