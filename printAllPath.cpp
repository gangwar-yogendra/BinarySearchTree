/* Print all paths from root to child in binary search tree */
/**
  50
 / \
40  70
   / \
  60  80
  
**/

// Example program
#include <iostream>
#include <algorithm>

class Node
{
private:
    int data;
    Node *left;
    Node *right;
    
   friend class BST;
};

class BST 
{
public:
    /* Insert Node in BST */
    void InsertBST(Node **head, int value);
    void InOrder(Node *head);
	
    /* Find Node in BST */	
    void printAllPath(Node *head, int arr[], int length);
    void printPath(int arr[], int len);
};

void BST::printPath(int arr[], int len)
{
    std::cout<<"Path: ";
    for(int i=0; i<len; ++i)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

void BST::printAllPath(Node *head, int arr[], int length)
{
    if(head == NULL)
    {
       std::cout<<"There are no tree\n";
       return;
    }
    
    arr[length++] = head->data;
    
    /* If node of tree have left and right child is NULL */
    if(head->left == NULL && head->right == NULL)
    {
        printPath(arr, length);
        length=0;
    }
    else
    {
        printAllPath(head->left, arr, length);
        printAllPath(head->right, arr, length);
    }
}

/* Insert Node in BST */
void BST::InsertBST(Node **head, int value)
{
    if((*head) == NULL)
    {
        Node *newNode = new Node;
    
        if(newNode != nullptr) {
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
        }
        (*head) = newNode;
    }    
    /* If head value is greater than insert value */
    else if((*head)->data > value) {
        InsertBST(&(*head)->left, value);
    }
    else 
    {
        InsertBST(&(*head)->right, value);
    }
}

/* Print as inorder */
/* root -> left -> right */
void BST::InOrder(Node *head)
{
    if(head == NULL) return;
    
    std::cout<<head->data<<" ";
    InOrder(head->left);
    InOrder(head->right);
}

int main()
{
    Node *head = NULL;  
    BST *tree = new BST();
  
    tree->InsertBST(&head, 50);
    tree->InsertBST(&head, 40);
    tree->InsertBST(&head, 70);
    tree->InsertBST(&head, 60);
    tree->InsertBST(&head, 80);
 
    std::cout<<"InOrder: ";
    tree->InOrder(head);
    std::cout<<"\n";
    
    int *arr = new int[5];
    tree->printAllPath(head, arr, 0);
	
    delete tree;
    delete []arr;
    return 0;
}
