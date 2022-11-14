package pkg1;
import java.util.*;
class String_algo{
	private static boolean string1_greater_than_string2(String s1,String s2) {
		int  n = s1.length();
		for(int i=0;i<n;i++) {
			if(i>=s2.length()) {
				return true;
			}
			if(s1.charAt(i)<s2.charAt(i))  return false;
			else if(s1.charAt(i)>s2.charAt(i)) return true;
		}
		return false;
	}
	public static void sort(Vector<String> city) {
		int n = city.size();
		for(int i = n-1; i >= 1;i--) {
			for(int j = 0;j<i;j++) {
				if(String_algo.string1_greater_than_string2(city.elementAt(j), city.elementAt(j+1))) {
					String temp = city.elementAt(j);
					city.set(j, city.elementAt(j+1));
					city.set(j+1, temp);
				}
			}
		}
	}
}
public class cities {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Collections.EMPTY_LIST = 
		Vector<String> city = new Vector<String>();
		city.add("Delhi");
		city.add("Kolkata");
		city.add("Agartala");
		city.add("Goa");
		city.add("Kerala");
		city.add("daman");
		String_algo.sort(city);
		System.out.println("Sorted String :");
		for(String str: city) {
			System.out.println(str);
		}
		
	
		
	}

	

