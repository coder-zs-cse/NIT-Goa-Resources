package pkg1;

import java.util.Collection;
import java.util.Vector;

public class cities_collections {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
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

}
