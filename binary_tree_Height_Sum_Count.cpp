#include <iostream>
#include <vector>
using namespace std;

// Define the structure for the tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to build a tree from preorder traversal with -1 as NULL marker
Node* buildTree(const vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return NULL;
    }

    Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

// Function to calculate height of binary tree
int height(Node* root) {
    if (root == NULL){ 
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);
return max(leftHt, rightHt) + 1;
}
//Function to calculate nodes of binary tree

int count(Node* root){
    if(root == NULL){
        return 0;
    }
    int  leftCount = count(root -> left);
    int rightCount = count(root -> right);
return leftCount + rightCount +1 ;
}
 // Function to calculate sum of node in binary tree
 int sumOfNodes(Node* root){
     if(root == NULL){
         return 0;
     }
     int leftSum = sumOfNodes(root->left);
     int rightSum = sumOfNodes(root->right);
return leftSum + rightSum + root->data; 
 }
int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;
    Node* root = buildTree(preorder, index);

    cout << "Height of Nodes: " << height(root) << endl;
    cout << "Count of Nodes: " << count(root) << endl;
    cout << "Sum of Nodes: " << sumOfNodes(root) << endl;
    return 0;
}
