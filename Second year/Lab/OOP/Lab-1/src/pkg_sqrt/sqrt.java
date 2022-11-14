package pkg_sqrt;
import java.util.*;  
public class sqrt {
	public static double mysqrt(double a) {
		for(double i = 1;i<a;i+=0.00000001) {
			if(i*i>=a) return i;
		}
		return 0;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scn = new Scanner(System.in);
		double number = scn.nextDouble();
		double a = mysqrt(number);
		System.out.println(a);
	}
	

}
