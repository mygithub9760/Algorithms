/******************************************************************************

                            Java program to print all
                            permutations of an stirng

*******************************************************************************/
import java.util.*;
import java.io.*;
public class Permutation_BCT
{
    static int count;
    static void permuteHelper(StringBuffer s, StringBuffer chosen)
    {
        if(s.length() == 0)
        {
            System.out.println(chosen);
            count++;
        }
        else
        {
            int size = s.length();
            for(int i = 0; i < size; i++)
            {
                char c = s.charAt(i);
                chosen.append(c);
                permuteHelper(s.replace(i, i+1, ""), chosen);
                s.insert(i,c);
                chosen.deleteCharAt(chosen.length() - 1);
            }
        }
    }
    
    public static void permute(String s)
    {
        StringBuffer chosen = new StringBuffer();
        
        permuteHelper(new StringBuffer(s), chosen);
    }
    
	public static void main(String[] args) {
	    permute("SPERM");
	    System.out.println(count);
	}
}
