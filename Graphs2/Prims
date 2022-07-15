#include<iostream>
#include<climits>
using namespace std;
int findMinVertex(bool *visited,int *weights,int n){
    int minVertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&(minVertex==-1||weights[i]<weights[minVertex])){
            minVertex=i;
        }
    }
    return minVertex;
}
int prims(int **edges,int n){
    bool *visited=new bool[n];
    int *weights=new int[n];
    int *parents=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        weights[i]=INT_MAX;
    }
    weights[0]=0;
    parents[0]=-1;
    for(int i=0;i<n-1;i++){
        int minVertex=findMinVertex(visited,weights,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j]!=0&&!visited[j]){
                if(edges[minVertex][j]<weights[j]){
                    weights[j]=edges[minVertex][j];
                    parents[j]=minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(i<parents[i]){
            cout<<i<<" "<<parents[i]<<" "<<weights[i]<<endl;
        }
        else{
            cout<<parents[i]<<" "<<i<<" "<<weights[i]<<endl;
        }
    }   
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    cout<<endl;
    prims(edges,n);
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}
