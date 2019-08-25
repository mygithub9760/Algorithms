/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
import java.io.*;
public class Knapsack_01
{
    public static int Knapsack(int[] W, int[] P)
    {
        int w = W.length;
        int p = P.length;
        int[][]  T = new int[p+1][w+1];
        
        for(int i = 0; i<=p; i++)
        {
            for(int j = 0;j<=w;j++)
            {
                if(j==0 || i==0)
                    T[i][j] = 0;
                else{
                    if(W[i-1]<= j && P[i] + T[i-1][j-W[i-1]] > T[i-1][j])
                        T[i][j] = P[i] + T[i-1][j-W[i-1]];
                    else
                        T[i][j] = T[i-1][j];
                }
            }
        }
        return T[p][w];
    }
    
	public static void main(String[] args) throws IOException{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String[] str = br.readLine().trim().split(" ");
	    int[] W = Arrays.stream(str).mapToInt(Integer::parseInt).toArray();
	    str = br.readLine().trim().split(" ");
	    int[] P = Arrays.stream(str).mapToInt(Integer::parseInt).toArray();
	    System.out.println(Knapsack(W,P));
	}
}
