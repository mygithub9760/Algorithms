/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Iterator;
public class PrintDuplicateWords
{
	public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().trim().split(" ");
        Map<String, Integer> m = new LinkedHashMap<>();
        
        for(int i = 0; i<str.length; i++)
        {
            String s = str[i];
            if(m.containsKey(s))
                m.put(s, m.get(s)+1);
            else
                m.put(s, 1);
        }
        
        Iterator<Map.Entry<String, Integer>> itr = m.entrySet().iterator();
        while(itr.hasNext())
        {
            Map.Entry<String, Integer> obj = itr.next();
            if(obj.getValue()>1)
                System.out.println(obj.getKey());
        }
	}
}
