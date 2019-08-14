import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
class K_thNonRepeating
{
    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine().trim();
        int k = Integer.parseInt(br.readLine().trim());
        Map<Character, Integer> m = new LinkedHashMap<>();
        int size=str.length();
        for (int i =0;i<size ; i++ )
        {
            char ch = str.charAt(i);
            if(m.containsKey(ch))
                m.put(ch, m.get(ch)+1);
            else
                m.put(ch, 1);
        }
        
        Iterator<Map.Entry<Character, Integer>> itr = m.entrySet().iterator();
        while(itr.hasNext())
        {
            Map.Entry<Character, Integer> obj = itr.next();
            if(obj.getValue() == 1) k--;
            if(k==0) System.out.println(obj.getKey());
        }
    }
}
