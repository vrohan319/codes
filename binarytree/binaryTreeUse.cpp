#include <iostream>
#include <queue>
#include "binaryTree.h"
#include "pair.h"
#include <algorithm>
using namespace std ;

binaryTreeNode<int>* takeInputLevelWise(){
    int rootData ;
    cout << "enter root data" << endl ;
    cin >> rootData ;
    if(rootData == -1){
        return NULL ;
    }



    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData) ;

    queue<binaryTreeNode<int>*> pendingNodes ;
    pendingNodes.push(root) ;

    while(!pendingNodes.empty()){

        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop() ;
        cout << "enter left child of "<< front->data <<endl ;
        int leftData ;
        cin >> leftData ;
        if(leftData != -1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(leftData) ;
            front->left = child ;
            pendingNodes.push(child) ;
        }

        cout << "enter right child of "<< front->data <<endl ;
        int rightData ;
        cin >> rightData ;
        if(rightData != -1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(rightData) ;
            pendingNodes.push(child) ;
            front->right = child ;
        }

    }
    return root ;

}

void printTree(binaryTreeNode<int>* root){

    if(root == NULL){
        return ;
    }
    cout << root->data <<" : " ;

    if(root->left != NULL){
        cout << "L " << root->left->data <<" " ;
    }
    if(root->right != NULL){
        cout << "R " << root->right->data ;
    }
    cout <<endl ;

    printTree(root->left) ;
    printTree(root->right) ;

}

binaryTreeNode<int>* takeInput(){
    int rootData ;
    cout << "enter data" << endl ;
    cin >> rootData ;

    if(rootData == -1){
        return NULL ;
    }

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData) ;
    binaryTreeNode<int>* leftChild = takeInput() ;
    binaryTreeNode<int>* rightChild = takeInput() ;

    root->left = leftChild ;
    root->right = rightChild ;

    return root ;
}

void inorder(binaryTreeNode<int>* root){

    if(root == NULL){
        return ;
    }

    inorder(root->left) ;
    cout << root -> data << " " ;
    inorder(root -> right) ;
}

int height(binaryTreeNode<int>* root){
    if(root == NULL){
        return 0 ;
    }

    int ans = 1 ;
    int leftans = height(root->left) ;
    int rightans = height(root->right) ;

    ans = ans + max(leftans , rightans) ;

    return ans ;

}

int diameter(binaryTreeNode<int>* root){

    if(root == NULL){
        return 0 ;
    }

    int option1 = height(root->left) + height(root->right) ;
    int option2 = diameter(root->left) ;
    int option3 = diameter(root->right) ;

    return max(option1,max(option2,option3)) ;
}

Pair diameterBetterhelper(binaryTreeNode<int>* root){

    if(root == NULL){
        Pair ans ;
        return ans ;
    }

    Pair leftans = diameterBetterhelper(root->left) ;
    Pair rightans = diameterBetterhelper(root->right) ;

    Pair ans ;

    ans.height = 1 + max(leftans.height ,rightans.height) ;
    int option1 = leftans.height + rightans.height ;
    ans.diameter = max(option1, max(leftans.diameter,rightans.diameter)) ;

    return ans ;
}

int diameterBetter(binaryTreeNode<int>* root){

    Pair ans = diameterBetterhelper(root) ;
    return ans.diameter;
}


binaryTreeNode<int>* buildTree(int *preorder, int preSi, int preEi , int *inorder, int inSi , int inEi){

    if(preEi > preSi ||  inEi > inSi){
        return NULL ;
    }

    int rootData = preorder[preSi] ;

    int rootIndex = -1 ;
    for(int i = inSi ; i <= inEi ; i++){
        if(inorder[i] == rootData){
            rootIndex = i ;
            break ;
        }
    }
    int leftStartInorder = inSi ;
    int leftEndInorder = rootIndex - 1;
    int leftStartPreorder = preSi + 1;
    int leftEndPreorder = leftEndInorder - leftStartInorder + leftStartPreorder;
    int rightStrartPre = leftEndPreorder + 1 ;
    int rightEndPre = preEi;
    int rightStartIn = rootIndex + 1;
    int rightEndIn = inEi ;

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData) ;

    root->left = buildTree(preorder , leftStartPreorder , leftEndPreorder , inorder ,leftStartInorder ,leftEndInorder);
    root->right = buildTree(preorder , rightStrartPre, rightEndPre ,inorder ,rightStartIn ,rightEndIn) ;

    return root ;
}

binaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    return buildTree(preorder ,0 ,preLength - 1 ,inorder,0 ,inLength - 1) ;

}

/***************************/

int TreeToArray(binaryTreeNode<int>* root ,int arr[] ,int si){

    if(root == NULL){
        return si ;
    }

    si= si + 1 ;
    arr[si] = root->data ;


    si = TreeToArray(root->left , arr , si) ;

    si = TreeToArray(root->right , arr , si) ;

    return si ;

}

//2 1 3 9 5 6 7 -1 -1 -1 -1 8 4 -1 -1 -1 -1 -1 -1

int main(){
    /*
    binaryTreeNode<int> * root = new binaryTreeNode<int>(1) ;
    binaryTreeNode<int> * node1 = new binaryTreeNode<int>(2) ;
    binaryTreeNode<int> * node2 = new binaryTreeNode<int>(3) ;

    root->left = node1 ;
    root->right = node2 ;


    binaryTreeNode<int>* root = takeInputLevelWise() ;

    inorder(root) ;



    int preorder[] ={1,2,4,5,3,6,8,9,7} ;
    int inorder[] = {4,2,5,1,8,6,9,3,7} ;

    //binaryTreeNode<int>* root = construct() ;

    */

    binaryTreeNode<int>* root = takeInputLevelWise() ;

    printTree(root) ;

    int arr[100] ;
    int n = TreeToArray(root,arr,-1) ;

    for(int i = 0 ; i <= n ; i++){
        cout << arr[i] << " " ;
    }

    cout << endl ;

    sort(arr , arr + n) ;

    for(int i = 0 ; i <= n ; i++){
        cout << arr[i] << " " ;
    }

   // int ans = diameterBetter(root) ;
    //cout << ans << endl ;

    delete root ;

}
















