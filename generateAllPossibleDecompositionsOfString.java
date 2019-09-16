import java.io.*;
import java.util.*;

class generateAllPossibleDecompositionsOfString
{
    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String str = br.readLine().trim();
        
        generateAllPossibleDecompositions(str);
    }
    
    static void generateAllPossibleDecompositions(String str)
    {
        List<String> l = new ArrayList<>();
        helper(str, l);
    }
    
    static void helper(String str, List<String> l)
    {
        if(str.length() == 0)
        {
            System.out.println(l);
            return;
        }
        
        for(int i = 0;i<str.length();i++)
        {
            if(isPalindrome(str.substring(0,i+1)))
            {
                l.add(str.substring(0,i+1));
                helper(str.substring(i+1),l);
                l.remove(l.size()-1);
            }
        }
    }
    
    static boolean isPalindrome(String str)
    {
        if(str.length()<2)
            return true;
        
        return (str.charAt(0) == str.charAt(str.length()-1)) && isPalindrome(str.substring(1, str.length()-1));            
    }
    
}
