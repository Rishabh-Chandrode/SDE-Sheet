/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// using bfs approach

class Solution {
public:
    queue<Node*> q;
    map<Node*,Node*> m;
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        q.push(node);

        while(!q.empty()){
            Node *root = q.front();
            q.pop();
            if(m[root]==NULL){
                m[root] = new Node(root->val);
            }
            vector<Node*> v = root->neighbors;
            int n = v.size();
            for(int i=0;i<n;i++){
                if(m[v[i]]==NULL){
                    Node *newnode = new Node(v[i]->val);
                    m[v[i]] = newnode;
                    q.push(v[i]);
                }
                m[root]->neighbors.push_back(m[v[i]]);
            }
        }
        return m[node];
    }
    
};

//using dfs approach







