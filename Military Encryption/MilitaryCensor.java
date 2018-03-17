import java.util.*;

public class MilitaryCensor {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String a = "";
		int c1 = 0;
		for(int f = 0; f<5; f++)
		{

			System.out.print("Enter next sentence: ");
			Scanner kb = new Scanner (System.in);
			a = kb.nextLine();
			StringTokenizer t = new StringTokenizer(a, ", \n.");
			while (t.hasMoreTokens())
			{

				String tok = t.nextToken();

				if (tok.equalsIgnoreCase("Hermes") || tok.equalsIgnoreCase("bridge") || 
						tok.equalsIgnoreCase("Muddy") || tok.equalsIgnoreCase("River") || 
						tok.equalsIgnoreCase("assault") || tok.equalsIgnoreCase("offensive"))
				{
					c1=c1+1;
				}
			}
			if(c1>0)
				System.out.println(a + ">>>REJECTED");
			else 
				System.out.println(a + ">>>OK");
			c1=0;
		}

	}

}
