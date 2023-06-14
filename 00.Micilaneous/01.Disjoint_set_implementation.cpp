#include <bits/stdc++.h>
using namespace std;

class disjoint_set{
    private:
        vector<int> parent,rank,size;
    
    public:
        disjoint_set(int n){
            parent.resize(n+1,0);
            rank.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findupar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findupar(parent[node]);
        }

        void unionbyrank(int u,int v){
            int ulp_u = findupar(u);
            int ulp_v = findupar(v);
            if(ulp_u == ulp_v) return ;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionbysize(int u,int v){
            int ulp_u = findupar(u);
            int ulp_v = findupar(v);

            if(ulp_u == ulp_v) return ;

            if(size[ulp_u] < size[ulp_v] ){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] +=size[ulp_v];
            }
        }

};

int main(){
    disjoint_set ds(7);
    ds.unionbysize(1,2);
    ds.unionbysize(2,3);
    ds.unionbysize(4,5);
    ds.unionbysize(6,7);
    ds.unionbysize(5,6);
    
    if(ds.findupar(3) == ds.findupar(7)){
        cout<<"same \n";
    }else cout<<"not same \n";

    ds.unionbyrank(3,7);
    if(ds.findupar(3) == ds.findupar(7)){
        cout<<"same \n";
    }else cout<<"not same \n";

    return 0;
}