#include <iostream>
#include <queue>
#include "treeNode.h"
using namespace std;

void printLevelWise(TreeNode<int>* root){

    if(root == NULL)
        return ;

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root) ;

    while(!pendingNodes.empty()){

        TreeNode<int>* front = pendingNodes.front() ;
        pendingNodes.pop() ;

        cout << front->data << "::"  ;
        int childNum = front->children.size() ;

        if(childNum > 0){
            int i = 0 ;
            while(i < childNum - 1){
                cout << front->children[i]->data <<"," ;
                pendingNodes.push(front->children[i]);
                i++;
            }
            cout << front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        cout << endl ;
    }
}

TreeNode<int>* takeInputLevelWise(){

    int data ;
    cout<< "enter roots data " <<endl ;
    cin >> data ;
    TreeNode<int>* root = new TreeNode<int>(data) ;

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root) ;

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front() ;
        pendingNodes.pop() ;

        int childNum ;
        cout << "enter the num of children of " << front->data << endl;
        cin >> childNum ;

        for(int i = 0 ; i < childNum ; i++){
            int childData ;
            cout << "enter "<< i << "th child " << front->data << endl;
            cin >> childData ;
            TreeNode<int>* child = new TreeNode<int>(childData) ;
            front->children.push_back(child) ;
            pendingNodes.push(child) ;
        }
    }
    return root ;
}

TreeNode<int>* takeInput(){

    int data ;
    cout<< "enter roots data " <<endl ;
    cin >> data ;

    TreeNode<int>* root = new TreeNode<int>(data) ;

    cout << "enter num of children of " << root->data << endl ;
    int numChild ;
    cin >> numChild ;

    for(int i = 0 ; i < numChild ; i++){
        root->children.push_back(takeInput());
    }

    return root ;
}

void printTree(TreeNode<int>* root){

    if(root == NULL)
        return ;

    cout << root -> data << " :" ;

    for(int i = 0 ; i < root->children.size() ; i++){
        cout << root->children[i]->data <<" " ;
    }
    cout << endl ;

    for(int i = 0 ; i < root->children.size() ; i++){
        printTree(root->children[i]) ;
    }

}

int main(){

    TreeNode<int>* root = takeInputLevelWise() ;

    printLevelWise(root) ;

    return 0 ;
}
