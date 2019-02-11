/* Maximum depth of a tree */
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
    int depth(Node *tree);
};

/* Get max depth of a tree */
int BST::depth(Node *tree)
{
    if(tree == NULL) return 0;
    
    return (std::max(depth(tree->left), depth(tree->right)) + 1); 
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
 
    std::cout<<"InOrder Tree 1: ";
    tree->InOrder(head);
    std::cout<<"\n";
    
    std::cout<<"Depth of tree: "<<tree->depth(head);
	
    delete tree;
    
    return 0;
}
