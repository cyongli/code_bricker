import java.util.Random;


public class RandomDemo {

	public static void main(String[] args) {
		Random rand = new Random();
		int n = rand.nextInt(50);
		System.out.println(n);
	}

}
