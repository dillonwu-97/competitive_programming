/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        long long ret = 0;
        for (auto x : tree) {
            ret ^= x->val;
            for (auto y: x->children) {
                ret ^= y->val;
            }
        }
        Node * ret2;
        for (auto x: tree) {
            if (x->val == ret) {
                ret2 = x;
            }
        }
        return ret2;
        // return tree[0];
    }
};