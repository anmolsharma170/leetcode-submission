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
    vector<Node*> nodeRegister;
    void dfs(Node* node, Node* clone){
        for(auto neighbor: node->neighbors){
            if(!nodeRegister[neighbor->val]){
                Node* newnode = new Node(neighbor->val);
                nodeRegister[newnode->val]=newnode;
                clone->neighbors.push_back(newnode);
                dfs(neighbor,newnode);
            }
            else{
                clone->neighbors.push_back(nodeRegister[neighbor->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        nodeRegister.resize(125,NULL);
        Node* clone = new Node(node->val);
        nodeRegister[node->val]=clone;
        dfs(node,clone);
        return clone;
    }
};