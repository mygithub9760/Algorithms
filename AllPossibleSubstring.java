import java.io.*;
import java.util.*;

class AllPossibleSubstring
{
    public static void main (String[] args) {
        StringBuffer A = new StringBuffer("jbms");
        
        StringBuffer path = new StringBuffer();
        
        printPath(A,path);
    }
    
    static void printPath(StringBuffer A, StringBuffer path)
    {
        if(A.length() == 0)
        {
            System.out.println(path);
        }
        else
        {
                char ch = A.charAt(0);
                A.deleteCharAt(0);
                
                path.append(ch);
                printPath(A, path);
                
                path.deleteCharAt(path.length() -1);
                printPath(A, path);
                
                
                A.insert(0,ch);
        }
    }
}





