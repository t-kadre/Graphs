#include <bits/stdc++.h>
using namespace std;
void printDFS(int**edges,int n,int sv,bool*visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]==false){
                printDFS(edges,n,i,visited);
            }
        }
    }
}
void DFS(int**edges,int n){
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){//printing every connected components
        if(visited[i]==false){
            printDFS(edges,n,i,visited);
        }
    }
    delete[] visited;
}
void printBFS(int**edges,int n,int sv,bool*visited){
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
void BFS(int**edges,int n){
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){//printing every connected components
        if(visited[i]==false){
            printBFS(edges,n,i,visited);
        }
    }
    delete[] visited;
}
int main(){
    int n,e;
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
    cout<<"DFS"<<endl;
    DFS(edges,n);
    cout<<"BFS"<<endl;
    BFS(edges,n);
    return 0;
}