import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
class FindExtraChar
{
    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine().trim();
        String str2 = br.readLine().trim();
        
        int size1 = str1.length();
        int size2 = str2.length();
        int sum1 =0, sum2 =0;
        for(int i  =0 ;i<size2;i++)
        {
            if(i<size1)
            {
                sum1 += (int)str1.charAt(i);
                sum2 += (int)str2.charAt(i);
            }
            else
                sum2 += (int)str2.charAt(i);
        }
        
        System.out.println((char)(sum2-sum1));
    }
}
