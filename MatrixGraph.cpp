/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Graph
{
    int v;
    int e;
    int **M;
};

Graph* createMatrixGraph(int v)
{
    Graph* g = (Graph*)malloc(sizeof(struct Graph));
    if(!g)
    {
        std::cout << "not allocted space to Graph" << std::endl;
    }
    g->v = v;
    
    g->M = (int **)malloc(v * sizeof(int *)); 
    for (int i=1; i<=v; i++) 
         g->M[i] = (int *)malloc(v * sizeof(int));
         
    if(!g->M)
    {
        std::cout << "not allocated space to matrix" << std::endl;
    }
    for(int i = 1; i <= g->v; i++)
    {
        for(int j = 1; j<= g-> v; j++)
        {
            g->M[i][j] = 0;
        }    
    }

    return g;
}

void addEdge(Graph* g, int v1, int v2)
{
    g->e = g->e + 1;
    g->M[v1][v2] = 1;
    g->M[v2][v1] = 1;
}

void printGraph(Graph* g)
{
    int size = g->v;
    for(int i = 1; i<=size; i++){
        for (int j = 1; j<=size; j++) {
            cout << g->M[i][j] << " ";
        }
        std::cout <<std::endl;
    }
}

int main()
{
    Graph* g = createMatrixGraph(4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 4, 3);
    printGraph(g);
    std::cout << g->e << std::endl;
    return 0;
}
