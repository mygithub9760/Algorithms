/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.io.*;
import java.util.*;
public class GreedyKnapsack
{
     public static <K, V extends Comparable<V>> TreeMap<K, V> 
    sortByValues(final TreeMap<K, V> map) {
    Comparator<K> valueComparator = 
             new Comparator<K>() {
      public int compare(K k1, K k2) {
        int compare = 
              map.get(k2).compareTo(map.get(k1));
        if (compare == 0) 
          return 1;
        else 
          return compare;
      }
    };
 
    TreeMap<K, V> sortedByValues = 
      new TreeMap<K, V>(valueComparator);
    sortedByValues.putAll(map);
    return sortedByValues;
  }
    
    
	public static void main(String[] args) throws IOException{
		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		String[] str1 = br.readLine().trim().split(" ");
		String[] str2 = br.readLine().trim().split(" ");
		int n = Integer.parseInt(br.readLine().trim());
		TreeMap<Integer, Double> mp = new TreeMap<>();
		int size = str1.length;
		for(int i =0;i<size;i++)
		{
		    int a = Integer.parseInt(str2[i]);
		    mp.put(a, Integer.parseInt(str1[i])/(double)a);
		}
		
		TreeMap<Integer, Double> m = sortByValues(mp);
		
		Set set = m.entrySet();
 
        // Get an iterator
        Iterator i = set.iterator();
     
        // Display elements
        double val = 0.0;
        int key = 0;
        double p = 0;
        while(i.hasNext()) {
          Map.Entry me = (Map.Entry)i.next();
          val = (double)me.getValue();
          key = (int)me.getKey();
          if(n>key && n>0)
          {
              p = p + key*val;
              n = n - key;
          }
          else break;
        }
        if(n>0)
        {
            p = p + n*val;        
        }
        System.out.println(p);
	}
}
