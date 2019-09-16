import java.io.*;
import java.util.*;

class generateStringOfLengthKFromASetOfNCharacters
{
    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        char[] set = br.readLine().trim().toCharArray();
        int k = Integer.parseInt(br.readLine().trim());
        
        generate(set, k);
    }
    
    static void generate(char[] set, int k)
    {
        StringBuffer sb = new StringBuffer();
        helper(set, sb, k);
    }
    
    static void helper(char[] set, StringBuffer sb, int k)
    {
        if(k == 0)
        {
            System.out.println(sb.toString());
            return;
        }
        
        for(int i = 0;i<set.length;i++)
        {
            sb.append(set[i]);
            helper(set, sb, k-1);
            sb.deleteCharAt(sb.length()-1);
        }
    }
    
}
