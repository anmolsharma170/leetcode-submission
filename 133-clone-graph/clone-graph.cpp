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

class Solution {
public:
    void dfs(Node* node, Node* clone){
        for(auto neigh: node->neighbors){
            if(!noderegister[neigh->val]){
                Node* newnode = new Node(neigh->val);
                noderegister[newnode->val]= newnode;
                clone->neighbors.push_back(newnode);
                dfs(neigh,newnode);

            }
            else{
                clone->neighbors.push_back(noderegister[neigh->val]);
            }
        }
    }
    vector<Node*> noderegister;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        noderegister.resize(125,NULL);
        Node* clone = new Node(node->val);
        noderegister[clone->val] = clone;
        dfs(node,clone);
        return clone;
    }
};