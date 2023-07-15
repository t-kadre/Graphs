#include <bits/stdc++.h>
using namespace std;
//G(V,E) -> Subgraph H(V',E') of G where V' and E' are subsets of V and E (DIRECTED & UNDIRECTED)
//Adjacent vertices if an edge is between them
//Degree of vertex = no. of edges connected to it (InDegree or OutDegree)
//Path exist or not between two vertices
//Connected graph = if there exist a path between any and every pair of vertices
//Connected components = largest subgraphs of a disconnected graph which are connected
//Tree = connected graphs which do not have cycles
//Min no. of edges in a connected graph with n vertices = n-1 = O(n)
//Complete graph = there is an edge between every two vertices
//Min no. of edges in a complete graph with n vertices = nC2 = O(n^2)
//MIN & MAX EDGES POSSIBLE IN A CONNECTED GRAPH -> O(n) to O(n^2)
//ADJACENCY LIST -> O(n^2) time
//ADJACENCY MATRIX -> O(n^2) space as nxn matrix & TRUE at i,j means an edge is there
//waste of space in sparse graph as loads of false
void print(int**edges,int n,int sv,bool*visited){//DFS as recursion used, once we go in one direction from starting vertex (sv) we continue untill dead end
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]==false){
                print(edges,n,i,visited);
            }
        }
    }
}
int main(){
    int n,e;//undirected
    cin>>n>>e;
    int** edges=new int*[n];//adjacency matrix
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0; 
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    print(edges,n,0,visited);
    delete[] visited;
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}