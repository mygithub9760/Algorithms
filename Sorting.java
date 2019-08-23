/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Sorting
{
	public static void main(String[] args) {
	    int[] a = {3,2,1,0,89,8,9,1,3};
		Sort s = new Sort(9,a);
		//s.SelectionSort();
		//s.BubbleSort();
		//s.InsertionSort();
		s.QuickSort();
	}
}

class Sort
{
    int n;
    int[] a = new int[n];
    
    Sort(int n, int[] a)
    {
        this.n = n;
        this.a = a;
    }
    
    public void SelectionSort()
    {
        int min=0;
        for(int i = 0;i<n;i++)
        {
            min = i;
            
            for(int j = i+1;j<n;j++)
            {
                if(a[j]<a[min])
                    min = j;
            }
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        
        printArray("By Selection Sort");
    }
    
    
    public void BubbleSort()
    {
        for(int i = 0;i<n-1;i++)
        {
            for(int j = 1; j<n-i;j++)
            {
                if(a[j]<a[j-1])
                {
                    int temp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = temp;
                }
            }
        }
        printArray("By Bubble Sort");
    }
    
    public void InsertionSort()
    {
        for(int i = 1;i<n;i++)
        {
            int j = i-1;
            int temp = a[i];
            while(j>=0 && a[j]>temp)
            {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = temp;
        }
        printArray("By Insertion Sort");
    }
    
    public void MergeSort()
    {
        mergeHelper(this.a,0,n-1);
        printArray("By Merge Sort");
    }
    
    void mergeHelper(int[] a, int s, int e)
    {
        int mid = s + (e-s)/2;
        int n = a.length;
        if(e<=s)
            return;
        int[] L = new int[mid+1];
        int[] R = new int[n-mid-1];
        int k = 0;
        for(int i=0;i<mid+1;i++, k++) L[i] = a[k];
        
        for(int i =0;i<n-mid-1;i++,k++) R[i] = a[k];
        
        mergeHelper(L, 0, mid);
        mergeHelper(R, 0, n-mid-2);
        merge(a,L,R); 
    }
    
    void merge(int[] a, int[] L, int[] R)
    {
        int n = a.length;
        int l = L.length;
        int r = R.length;
        int i, j, k;
        i = j = k = 0;
        while(i<l && j<r && k<n)
        {
           if(L[i] <= R[j]){
                a[k] = L[i];
                i++;
           }
           else{
               a[k] = R[j];
               j++;
           }
           k++;
        }
        
        while(i<l && k<n){
            a[k] = L[i]; 
            i++; k++;
        }
        
        while(j<r && k<n){
            a[k] = R[j];
            j++; k++;
        }
    }
    
    
    public void QuickSort()
    {
        QuickHelper(a, 0, n-1);
        printArray("By Quick Sort");
    }
    
    void QuickHelper(int[] a, int s, int e)
    {
        if(s<e)
        {
            int p = partition(a,s,e);
            QuickHelper(a,s,p-1);
            QuickHelper(a,p+1,e);
        }
    }
    
    int partition(int[] a,int s,int e)
    {
        int pivot = a[e];
        int pIndex = 0;
        int temp;
        for(int i =0;i<=e-1;i++)
        {
            if(a[i]<=pivot)
            {
                temp = a[i];
                a[i] = a[pIndex];
                a[pIndex] = temp;
                pIndex++;
            }
        }
        temp = a[e];
        a[e] = a[pIndex];
        a[pIndex] = temp;
        
        return pIndex;
    }
    
    public void printArray(String str)
    {
        System.out.print(str + ":");
        for(int i =0;i<n;i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }
}
