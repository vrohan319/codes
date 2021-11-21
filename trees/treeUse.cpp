#include <iostream>
#include <queue>
#include "treeNode.h"
using namespace std;

void deleteTree(TreeNode<int>* root){

    for(int i = 0 ; i < root->children.size() ;i++){
        deleteTree(root -> children[i]) ;
    }
    delete root ;
}

void printLevelWise(TreeNode<int>* root) {
    // Write your code here

    if(root == NULL){
        return  ;
    }

    queue<TreeNode<int>*> pendingNodes ;
    pendingNodes.push(root) ;

    while(pendingNodes.size() != 0){

        TreeNode<int> *temp = pendingNodes.front() ;
        pendingNodes.pop() ;

        cout<< temp->data <<":" ;

        int k = temp->children.size() ;
        if(k > 0){
            // cout << endl ;
            // continue ;

        int i = 0 ;
        while(i < k - 1){
            cout << temp->children[i]->data <<"," ;
            pendingNodes.push(temp->children[i]) ;
            i++ ;
        }
        cout << temp->children[i]->data;
        pendingNodes.push(temp->children[i]) ;

        }
        cout << endl ;
    }
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* currMax = root ;

    for(int i = 0 ; i < root->children.size() ;i++){

        TreeNode<int>* temp = maxDataNode(root->children[i]) ;
        if(temp->data > currMax->data){
            currMax = temp ;
        }
    }
    return currMax ;

}

int sumOfNodes(TreeNode<int>* root) {
    if(root == NULL){
        return 0 ;
    }
    int ans = root->data ;

    for(int i = 0 ; i < root -> children.size() ; i++){
        ans += sumOfNodes(root->children[i]) ;
    }
    return ans ;
}

int getLeafNodeCount(TreeNode<int>* root) {
    if(root  == NULL)
        return 0 ;

    int ans = 0 ;
    if(root->children.size() == 0 ){
        ans = 1 ;
    }else{
        for(int i = 0 ; i < root->children.size() ;i++){
        	ans += getLeafNodeCount(root->children[i]) ;
    	}
    }
    return ans ;
}

int getHeight(TreeNode<int>* root) {
    int hmax = 0 ;

    for(int i = 0 ; i < root->children.size() ; i++){
        int temp = getHeight(root->children[i]) ;
        if(temp > hmax){
            hmax = temp ;
        }
    }
    return 1 + hmax ;
}

void printPreOrder(TreeNode<int>* root) {
    if(root == NULL)
        return ;

    cout << root -> data << " " ;

    for(int i = 0 ; i < root -> children.size() ; i++){
        printPreOrder(root -> children[i]) ;
    }
}

void printPostOrder(TreeNode<int>* root) {
    if(root == NULL)
        return ;

    for(int i = 0 ; i < root -> children.size() ; i++){
        printPostOrder(root -> children[i]) ;
    }
    cout << root -> data << " " ;
}

int countNodes(TreeNode<int>* root){

    int ans = 1;
    for(int i = 0 ; i < root->children.size() ; i++){
        ans += countNodes(root->children[i]) ;
    }
    return ans ;
}
/**
TreeNode<int>* takeInputLewelWise(){

    cout << "enter root data" << endl ;
    int rootData;
    cin >> rootData ;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes ;
    pendingNodes.push(root) ;

    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front() ;
        pendingNodes.pop() ;

        cout << "enter the num of children of " << front -> data << endl ;
        int numChild ;
        cin >> numChild ;

        for(int i = 0 ;  i < numChild ; i++){
            int childData ;
            cout << "enter " <<  i << "th child of " << front->data << endl ;
            cin >> childData ;
            TreeNode<int>* child = new TreeNode<int>(childData) ;
            front->children.push_back(child) ;
            pendingNodes.push(child) ;
        }
    }
    return root ;
}
***********************************************************/

TreeNode<int>* takeInputLevelWise(){

    cout << "enter roots data" << endl ;
    int rootData ;
    cin >> rootData ;
    TreeNode<int>* root = new TreeNode<int>(rootData) ;

    queue<TreeNode<int>*> pendingNode ;
    pendingNode.push(root) ;
    while(!pendingNode.empty()){

        TreeNode<int>* front = pendingNode.front() ;
        pendingNode.pop() ;
        int numChild ;
        cout << "enter the number of child of " << front->data << endl ;
        cin >> numChild ;

        for(int i = 0 ; i < numChild ; i++){
            cout << "enter the " << i << "th child of " << front->data << endl ;
            int childData ;
            cin >> childData ;

            TreeNode<int>* child =  new TreeNode<int>(childData) ;
            front->children.push_back(child) ;
            pendingNode.push(child) ;
        }
    }
    return root ;
}

/*****************************************/


TreeNode<int>* takeInput(){

    cout << "enter data" << endl ;
    int rootData;
    cin >> rootData ;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "enter num of children of " << rootData << endl ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child) ;
    }

    return root ;

}

void printTree(TreeNode<int>* root){
    if(root == NULL){
        return ; //edge case not a base case
    }

    cout << root-> data << " : " ;

    for(int i = 0 ; i < root->children.size() ; i++){
        cout << root->children[i]->data <<" " ;
    }
    cout << endl ;

    for(int i = 0 ; i < root->children.size() ; i++){
        printTree(root->children[i]) ;
    }

}

/*************************/


/***************************/

int main(){

    /*
    TreeNode<int>* root = new TreeNode<int>(1) ;
    TreeNode<int>* node1 = new TreeNode<int>(2) ;
    TreeNode<int>* node2 = new TreeNode<int>(3) ;

    root->children.push_back(node1) ;
    root->children.push_back(node2) ;
    */

    TreeNode<int>* root = takeInputLevelWise() ;

    printTree(root) ;




    //TODO delete tree

    //deleteTree(root) ;

    delete root ;
}




































