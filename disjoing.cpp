#include<iostream>
#include<vector>
using namespace std;
struct dis{
    int parent;
    int rank;
};
class disjn{
    public:
    vector<dis> node;
    disjn(int n){
        node.resize(n);
    }

    void makeset(int x){
        node[x].parent=x;
        node[x].rank=0;
    }

    int findset(int x){
        if(x!=node[x].parent){
            node[x].parent=findset(node[x].parent);
        }
        return node[x].parent;
    }

    void link(int x, int y){
        if(node[x].rank>node[y].rank){
            node[y].parent=x;
        }
        else{
            node[x].parent=y;
            if(node[x].rank==node[y].rank){
                node[y].rank+=1;
            }
        }
    }

    void Union(int x, int y){
        link(findset(x), findset(y));
    }

    void print(){
        for(int i=0; i<=node.size(); i++){
            cout<<"node: "<<i<< " parent: "<<node[i].parent<<" Rank: "<<node[i].rank<<endl;
        }
    }

};


int main(){
    
    int n=10;
    disjn a(n);
    for(int i=1; i<=10; i++){
        a.makeset(i);
    }
    a.Union(4, 7);
    a.Union(3, 10);
    a.Union(1, 10);
    a.Union(2, 4);
    a.Union(4, 10);
    a.findset(4);
    a.print();
    return 0;
}