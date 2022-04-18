- 👋 Hi, I’m @sidde2k01
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...

<!---
sidde2k01/sidde2k01 is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->

#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}
int findParent(int v,int *parent){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v],parent);
}
void kruskals(Edge *input,int E,int n){
    sort(input,input+E,compare);
    Edge *output=new Edge[n-1];
    int *parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count!=n-1){
        Edge currEdge=input[i];
        int sourceParent=findParent(currEdge.source,parent);
        int destParent=findParent(currEdge.dest,parent);
        if(sourceParent!=destParent){
            output[count]=currEdge;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    for(int i=0;i<n-1;i++){
        if(output[i].source<output[i].dest){
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
        cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}
int main(){
    int n,E;
    cin>>n>>E;
    Edge *input=new Edge[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    cout<<"The MST is : "<<endl;
    kruskals(input,E,n);
    return 0;
}
