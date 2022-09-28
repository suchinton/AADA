#include <iostream>
#include <limits.h>

using namespace std;

#define V 5

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    dist[src] = 0;
 
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main()
{    system ("clear");

    printf("\n| Suchinton (A2345920063)           |");
    printf("\n|-----------------------------------|");
    printf("\n| WAP to implement Dijkstra's Algo. |");
    printf("\n|-----------------------------------|\n");

    int graph[V][V] = {  //   0  1  2  3  4   
                            { 0, 1, 2, 3, 0 },  // 0  
                            { 1, 0, 2, 1, 0 },  // 1
                            { 2, 2, 0, 0, 5 },  // 2
                            { 3, 1, 0, 0, 4 },  // 3
                            { 0, 0, 5, 4, 0 }   // 4
                      };
    int src;

    cout<<"For given graph g:\n ";

    for(int i=0; i<V; i++)
    {
        cout<<"\n | ";
        for(int j=0; j<V; j++)
        {
            cout<<graph[i][j]<<" | ";
        }
        cout<<"\n ";
        for(int n=0; n<V; n++)
            cout<<"----";
    }

    cout<<"\n\nEnter source vertex: ";
    cin>>src;
    //int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
    cout<<"\n\n==============================================\n\n";
   
    dijkstra(graph, src);
    return 0;
}