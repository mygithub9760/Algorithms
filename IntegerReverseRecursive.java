import java.util.*;
import java.io.*;

public class IntegerReverseRecursive
{
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		///// prompting user to enter a number 
		System.out.println("Enter a number");
		int n = Integer.parseInt(br.readLine().trim());

	    n =	reverse(n, 0);
	    System.out.println(n);//// calling a function which checks whether number passed as argument is prime or not
	}
    
    static int reverse(int num, int sum)
    {
        if(num!=0)
        {
            sum = sum*10 + num%10;
            sum = reverse(num/10, sum);
        }
        return sum;
    }
	
}
