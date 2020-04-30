import java.io.*;
import java.util.*;

public class Main
{
    public static void main (String[] args) {
        Calculate c = new Calculate();
        List<Integer> list = new ArrayList<>();
        list.add(2);
        list.add(1);
        list.add(3);
        list.add(4);
        
        List<Set<Integer>> resultList = new ArrayList<>();
        resultList = c.getSubsets(list, 2);
        
        for(int i = 0 ;i<resultList.size();i++)
            System.out.println(resultList.get(i));
    }
}


class Calculate{
private static void getSubsets(List<Integer> superSet, int k, int idx, Set<Integer> current,List<Set<Integer>> solution) {
    //successful stop clause
    if (current.size() == k) {
        solution.add(new HashSet<>(current));
        return;
    }
    //unseccessful stop clause
    if (idx == superSet.size()) return;
    Integer x = superSet.get(idx);
    current.add(x);
    //"guess" x is in the subset
    getSubsets(superSet, k, idx+1, current, solution);
    current.remove(x);
    //"guess" x is not in the subset
    getSubsets(superSet, k, idx+1, current, solution);
}

public static List<Set<Integer>> getSubsets(List<Integer> superSet, int k) {
    List<Set<Integer>> res = new ArrayList<>();
    getSubsets(superSet, k, 0, new HashSet<Integer>(), res);
    return res;
}
}
