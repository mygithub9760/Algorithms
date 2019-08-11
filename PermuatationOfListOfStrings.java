/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
public class PermuatationOfListOfStrings
{
    static int count = 0;
    static  Set<List> finalList = new HashSet<>();
    static void permuteHelper(List<String> s, List list)
    {
        if(s.size() == 0)
        {
            if(!finalList.contains(list))
            {
                System.out.println(list);
                finalList.add(list);
            }
            count++;
        }
        else
        {
            for(int i = 0; i<s.size(); i++)
            {
                String str = s.get(i);
                list.add(str);
                s.remove(i);
                permuteHelper(s,list);
                s.add(i, str);
                list.remove(str);
            }
        }
        
    }
    
    static void permute(List<String> s)
    {
        List set = new ArrayList();
        permuteHelper(s, set);
    }
    
	public static void main(String[] args) {
	    List<String> s = new ArrayList<>();
	    s.add("ab");
	    s.add("ab");
	    s.add("cd");
	    
	    permute(s);
	    System.out.println(count);
	}
}

