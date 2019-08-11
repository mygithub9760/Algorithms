/******************************************************************************

                            This program prints all permutatins of numbers on
                            n dices where sum of numbers is equal to a given 
                            number.

*******************************************************************************/
import java.util.*;
import java.io.*;
public class DiceBCT
{
    static int count;
    static void diceHelper(int n, Stack<Integer> list, int desiredSum, int sumSoFar)
    {
        if(n == 0)
        {
            System.out.println(list);
            count++;
        }
        else
        {
            for(int i = 1; i <= 6; i++)
            {
                if(((sumSoFar + i + 1*(n-1))<= desiredSum) && ((sumSoFar + i + 6*(n-1)) >= desiredSum))
                {
                    list.push(i);
                    diceHelper(n-1, list, desiredSum, sumSoFar + i);
                    list.pop();
                }
            }
        }
    }
    
    public static void dice(int n, int desiredSum)
    {
        Stack<Integer> list = new Stack<>();
        int sumSoFar = 0;
        diceHelper(n, list, desiredSum, sumSoFar);
    }
    
	public static void main(String[] args) {
	    dice(10, 11);
	    System.out.println(count);
	}
}
