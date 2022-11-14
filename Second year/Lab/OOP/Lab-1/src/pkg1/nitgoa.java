package pkg1;

public class nitgoa {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StringBuffer college = new StringBuffer("College name is National Of Goa which is located in India, National Of Kerala which is located in south india");
		college.insert(college.indexOf("National Of") +11," Technology");
		college.insert(college.indexOf("National Of") + 8, " Institute");
//		college.insert(college.," Technology");
		
		System.out.println(college);
	}

}
