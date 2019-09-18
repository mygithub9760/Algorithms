import java.io.*;
import java.util.*;

class PrintDecimalOfLengthK
{
    public static void main (String[] args) {
        
        int[] A = new int[] {0,1,2,3,4,5,6,7,8,9};
        int k;
        StringBuffer sb = new StringBuffer();
        System.out.println(print(A,3,sb));
    }
    
    static int print(int[] A, int k, StringBuffer sb)
    {
        if(k==0){
            System.out.println(sb);
            return 1;
        }
        else
        {
            int count = 0;
            for(int i = 0;i<A.length;i++)
            {
                sb.append(i);
                count = count + print(A, k-1, sb);
                sb.deleteCharAt(sb.length()-1);
            }
            return count;
        }
    }
    
}





