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
    vector<Node*> noderegister;
    void dfs(Node* node, Node* clone){
        for(auto neigh: node->neighbors){
            if(!noderegister[neigh->val]){
                Node* newNode = new Node(neigh->val);
                noderegister[newNode->val]=newNode;
                clone->neighbors.push_back(newNode);
                dfs(neigh,newNode);
            }
            else{
                clone->neighbors.push_back(noderegister[neigh->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        noderegister.resize(110,NULL);
        Node* clone = new Node(node->val);
        noderegister[node->val] = clone;
        dfs(node,clone);
        return clone;
    }
};