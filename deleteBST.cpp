/* Delete all the nodes from a binary tree */
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
	
    /* depth of BST */	
    void deleteBST(Node **head);
};

/* Get max depth of a tree */
void BST::deleteBST(Node **head)
{
    if((*head) == NULL) {
        return;
    }
    
    deleteBST(&(*head)->left);
    deleteBST(&(*head)->right);
    
    if((*head)->left == NULL && (*head)->right == NULL)
    {
        delete (*head);
        (*head) = NULL;
    }
}

/* Insert Node in BST */
void BST::InsertBST(Node **head, int value)
{
    if((*head) == NULL)
    {
        Node *newNode = new Node;
    
        if(newNode != NULL) {
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
    
    tree->deleteBST(&head);
    
    std::cout<<"\nPrint tree after delete all nodes.";
    std::cout<<"\nInOrder: ";
    tree->InOrder(head);
    std::cout<<"\n";
	
    delete tree;
    
    return 0;
}
