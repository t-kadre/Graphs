#include <bits/stdc++.h>
using namespace std;
void print(int**edges,int n,int sv,bool*visited){//BFS - queue used
    queue<int> q;
    q.push(sv);
    while(q.size()!=0){
        int w=q.front();
        if(visited[w]==false){cout<<w<<endl;}
        q.pop();
        visited[w]=true;
        for(int i=0;i<n;i++){
            if(w==i){continue;}
            if(edges[w][i]==1 && visited[i]==false){
                q.push(i);
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