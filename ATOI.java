import java.io.*;
import java.util.*;

class ATOI
{
    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringBuffer sb = new StringBuffer(br.readLine().trim());
        sb.reverse();
        System.out.println(calculate(sb.toString()));
    }
    
    static int calculate(String s)
    {
        if(s.length() == 1)
            return Integer.parseInt(s);
        
        int val = Integer.parseInt(s.substring(0,1));
        return val + 10*calculate(s.substring(1));
    }
}
