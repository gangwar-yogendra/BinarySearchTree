/* Insert node in a Binary Search Tree */
/**
  50
 / \
40  70
   / \
  60  80
  
**/

// Example program
#include <iostream>
#include <string>

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
    void InsertBST(Node **head, int value);
    void InOrder(Node *head);
    void PreOrder(Node *head);
    void PostOrder(Node *head);
    
    /*Count the number of Nodes in BST */
    int countNodes(Node *head);
};

int BST::countNodes(Node *head)
{
    if(head == NULL) return 0;
    
    return ( countNodes(head->left) 
             + 1 +
             countNodes(head->right));
}

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

/* left -> root -> right */
void BST::PreOrder(Node *head)
{
    if(head == NULL) return;
    
    PreOrder(head->left);
    std::cout<<head->data<<" ";
    PreOrder(head->right);
}

/* left -> right -> left*/
void BST::PostOrder(Node *head)
{
    if(head == NULL) return;
    
    std::cout<<head->data<<" ";
    PostOrder(head->right);
    PostOrder(head->left);
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
    std::cout<<"\nPreOrder: ";
    tree->PreOrder(head);
    std::cout<<"\nPostOrder: ";
    tree->PostOrder(head);
    std::cout<<"\n";
    
    std::cout<<"Number of Nodes in BST: "
                   <<tree->countNodes(head)<<"\n";
				   
    delete tree;
}