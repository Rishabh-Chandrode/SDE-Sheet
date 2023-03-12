# include <bits/stdc++.h>
using namespace std;

 void heapify_up(vector<int>& heap){
        int i=heap.size()-1;
        while(i>0){
            int p = i/2;
            if(heap[p] < heap[i]){
                swap(heap[p],heap[i]);
                i = p;
            }else{
                return;
            }
        }
        return;
    }
    void push(vector<int>& heap, int k){
        heap.push_back(k);
        heapify_up(heap);
        return ;
    }
    void heapify_down(vector<int> &heap){
        int i=0;
        int n= heap.size();
        while(i<n){
            int lc = i==0?1:i*2;
            int rc = i==0?2:i*2 +1;
            if(lc < n && heap[lc] > heap[i]){
                if(rc<n && heap[rc] >heap[lc]){
                    swap(heap[rc],heap[i]);
                    i = rc;
                }else{
                    swap(heap[lc],heap[i]);
                    i = lc;
                }
            }else if(rc < n && heap[rc] > heap[i]){
                swap(heap[rc],heap[i]);
                i = rc;
            }else{
                return;
            }

        }
    }
    void pop(vector<int> &heap){
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        heapify_down(heap);

        return ;
    }

    int main(){
        vector<int> heap;
    }