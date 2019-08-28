/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;
import java.io.*;
public class CreatePostOrder
{
    static int[] Find_PostOrder(int n, int[] inorder, int[] preorder)
    {
        if(n<=0) 
        {
            int[] ret = new int[0];
            return ret;
        }
        int root_val = preorder[0];
        int i = 0;
        for(i = 0;i<n;i++)
        {
            if(inorder[i] == root_val)
                break;
        }
        
        int root_index = i;
        
        int r = n-1-i;
        int l = i;
        int[] iL = new int[l];
        int[] pL = new int[l];
        
        int[] iR = new int[r];
        int[] pR = new int[r];
        
        for(int j =0;j<i;j++)
        {
            iL[j]=inorder[j];
        }
        
        for(int j =0;j<l;j++)
        {
            pL[j] = preorder[j+1];
        }
        
        int[] postL = Find_PostOrder(l, iL, pL);
        
        int j = i+1;
        for(int k =0;k<r;k++)
        {
            iR[k]=inorder[j];
            j++;
        }
        
        for(int k = l+1;k<n;k++)
        {
            pR[k-l-1] = preorder[k];
        }
        
        int[] postR = Find_PostOrder(r, iR, pR);
        
        int[] result = new int[n];
        i = 0;
        
        while(i<l)
        {
            result[i] = postL[i];
            i++;
        }
        
        j = 0;
        while(j<r)
        {
            result[i] = postR[j];
            j++;
            i++;
        }
        
        result[i] = root_val;
        return result;
    }
    
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine().trim());
		int[] inorder = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
		int[] preorder = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
		
		int[] postOrder = new int[n];
		postOrder = Find_PostOrder(n, inorder, preorder);
		for(int i = 0;i<n;i++)
		{
		    System.out.print(postOrder[i] + " ");
		}
	}
}
