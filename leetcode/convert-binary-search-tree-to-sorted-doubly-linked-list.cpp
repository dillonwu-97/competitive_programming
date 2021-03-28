/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    vector <Node*> v;
    void solve(Node* root) {
        if (root!=NULL) {
            solve(root->left);
            v.push_back(root);
            // cout << root->val << endl;
            solve(root->right);
        }
    }
        Node* treeToDoublyList(Node* root) {
        // v[0]->right = v[1];
        solve(root);
        if (v.size() == 0) {return NULL;}
        // cout << v.size() << endl;
        if (v.size() == 1) { v[0]->left = v[0]; v[0] -> right = v[0]; return 
            v[0];}
        for (int i = 0; i < v.size(); i++) {
            // cout << v[i]->val << endl;
            if (i == 0) {
                v[0]->left = v[v.size()-1];
                v[i]->right = v[i+1];
            } else if (i == v.size()-1) {
                v[i]->right = v[0];
                v[i]->left = v[i-1];
            } else {
                v[i]->left = v[i-1];
                v[i]->right = v[i+1];
            }
        }
        return v[0];
    }
};