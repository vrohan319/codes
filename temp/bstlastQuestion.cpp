#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left)
       		delete left;
    	if(right)
       		delete right;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

/**********************************************************************************/

/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
        class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
        };

        1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
        3 3

        5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
        6 1

        8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
        10 2

***********************************************************/
void print(BinaryTreeNode<int>* root , int k){

    if(root == NULL ){
        return ;
    }

    if(k == 0){
        cout << root->data << endl ;
        return ;
    }

    print(root->left , k - 1) ;
    print(root->right , k - 1) ;
}

int nodeAtK(BinaryTreeNode<int>* root ,int value ,int k){

    if(root == NULL){
        return -1 ;
    }

    if(root->data == value){
        print(root,k) ;
        return 0 ;
    }

    int leftAns = nodeAtK(root->right ,value ,k) ;
    if(leftAns != -1){
        if(leftAns == k - 1){
            cout << root->data << endl ;
            return -1 ;
        }
        print(root->right ,k - leftAns - 2) ;
        return leftAns + 1 ;
    }

    int rightAns = nodeAtK(root->right ,value ,k) ;
    if(rightAns != -1){
        if(leftAns == k - 1){
            cout << root->data << endl ;
            return -1 ;
        }
        print(root->left ,k - rightAns - 2) ;
        return rightAns + 1 ;
    }

    return -1 ;
}



void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    nodeAtK(root , node , k) ;
}



/**********************************************************************************/

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}



















