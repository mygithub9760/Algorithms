/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
import java.io.*;
public class Main
{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine().trim());
		int[] A = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
		int[] primeList = new int[n];
		
		for(int i = 0 ;i<n;i++)
		    primeList[i] = calculateDistictPrimeFactors(A[i]);
		
		for(int i : A)
		    System.out.print(i + " ");
		  
		System.out.println();  
		for(int i : primeList)
		    System.out.print(i + " ");
		
	}
	
	static int calculateDistictPrimeFactors(int n)
	{
	    List<Integer> primeList = seive_of_eretosthenis(n/2);
		int count = 0;
		//System.out.print(1 + " ");
		for(int i = 0 ;i<primeList.size();i++)
		{
		    boolean flag = false;
		    int val = primeList.get(i);
		    while(n%val == 0 && n>0)
		    {
		        flag = true;
		        //System.out.print(val + " ");
		        n = n/val;
		    }
		    if(flag)
		        count ++;
		}
	
		if(count == 0){
		    //System.out.print(n);
		    //System.out.println();
		    //System.out.println(count + 1);
		    return 1;
		    
		}
		else{
		    //System.out.println();
		    //System.out.println(count);
		    return count;
		}
	}
	
	static List<Integer> seive_of_eretosthenis(int n)
	{
	    int[] prime = new int[n];
	    for(int i= 0;i<n;i++)
	    {
	        prime[i] = i+1;
	    }
	    
	    
	    prime[0] = -1;
	    for(int i = 1;i<n;i++)
	    {
	        int val = prime[i];
	        int j = i+1;
	        
	        if(val != -1)
    	        while(j<n)
    	        {
    	            if(prime[j]%val == 0)
    	                prime[j] = -1;
    	            j++;
    	        }
	    }
	    
	    ArrayList<Integer> list = new ArrayList<>();
	    for(int i : prime)
	    {
	        if(i!= -1)
	            list.add(i);
	    }
	    
	    return list;
	}
}
