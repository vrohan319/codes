
#include <climits>
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public:
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

class BST {
    // Define the data members
    BinaryTreeNode<int>* root ;

    BinaryTreeNode<int>* remove(int data , BinaryTreeNode<int>* node){
        if(node == NULL){
            return NULL;
        }

        if(data > node->data){
            node->right = remove(data , node->right) ;
            return node ;
        }else if(data < node->data){
            node->left = remove(data , node->left) ;
            return node ;
        }else {
            if(node->left == NULL && node->right == NULL){
                delete node ;
                return NULL ;
            }else if(node->left == NULL ){
                BinaryTreeNode<int>* temp = node->right ;
                node->right = NULL ;
                delete node ;
                return temp ;
            }else if(node->right == NULL){
                BinaryTreeNode<int>* temp = node->left ;
                node->left = NULL ;
                delete node ;
                return temp ;
            }else{
                BinaryTreeNode<int>* minNode = node->right ;
				while(minNode->left != NULL){
                    minNode = minNode->left ;
                }

                int Rightmin = minNode->data ;
                node->data = Rightmin ;
                node->right = remove(Rightmin, node->right) ;
                return node ;
            }
        }
    }

    void print(BinaryTreeNode<int>* node){
        if(node == NULL){
            return ;
        }

        cout << node->data <<":" ;
        if(node->left != NULL){
            cout << "L:" << node->left->data <<"," ;
        }
        if(root->right != NULL){
            cout << "R:" << node->right->data ;
        }

        cout << endl ;

        print(node->left) ;
        print(node->right) ;

    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node , int data){
        if(node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data) ;
            return newNode ;
        }

        if(data > node->data ){
            node->right = insert(node->right , data) ;
        }else{
            node->left = insert(node->left , data) ;
        }
        return node ;
    }

    bool search(BinaryTreeNode<int>* node , int data){
        if(node == NULL){
            return false ;
        }

        if(node->data == data){
            return true ;
        }else if(data < node->data){
            return search(node->left,data) ;
        }else{
            return search(node->right,data) ;
        }
    }


   public:
    // Implement the Constructor
    BST() {
        root = NULL ;
    }

    ~BST(){
        delete root ;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) {
        // Implement the remove() function
        root = remove(data ,root) ;
    }

    void print() {
        // Implement the print() function
        print(root);
    }

    void insert(int data) {
        // Implement the insert() function
        this->root = insert(this->root,data) ;
    }

    bool search(int data) {
		// Implement the search() function
        return search(root ,data) ;
    }
};














