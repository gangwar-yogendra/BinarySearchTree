/* Find min and max value in Binary Search Tree */
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
    /* Insert Node in BST */
    void InsertBST(Node **head, int value);
    void InOrder(Node *head);
	
    /* Find Min */	
    int findMin(Node *head);
    /* Find Max */
    int findMax(Node *head);
};


/* Find min value in Tree */
int BST::findMin(Node *head)
{
    if(head != NULL)
    {
        if(head->left != NULL)
        {
            return findMin(head->left);
        }
        else
        {
            return head->data;
        }
    }
    
    return -1;
}

/* Find max value in Tree */
int BST::findMax(Node *head)
{
    if(head != NULL) {
        if(head->right != NULL) {
            return (findMax(head->right));
        }
        else
        {
            return (head->data);
        }
    }
 
	
    return -1;
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
    
    std::cout<<"Min value of Tree: "<<
                tree->findMin(head)<<"\n";
                
    std::cout<<"Max value of Tree: "<<
                tree->findMax(head)<<"\n";
	
    delete tree;
}