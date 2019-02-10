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
    /* Insert Node in BST */
    void InsertBST(Node **head, int value);
    void InOrder(Node *head);
    
    /* Find Node in BST */	
    bool IsBST(Node *head);
};

/* Find min value in Tree */
bool BST::IsBST(Node *head)
{
    if(head != NULL)
    {
        if(head->left && head->right)
        {
            if((head->data > head->left->data) && (head->data < head->right->data))
            {
                return (IsBST(head->left) & IsBST(head->right));
            }
            else
            {
                return false;
            }
        }
        else if(head->left && !(head->right))
        {
            if(head->data > head->left->data) {
                return (IsBST(head->left));
            }
            else
            {
                return false;
            }
        }
        else if(!(head->left) && head->right)
        {
            if(head->data < head->right->data) {
                return (IsBST(head->right));
            }
            else
            {
                return false;
            }
        }
    }
    return true;
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
    /* Test 1: Checking BST */
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

    if(tree->IsBST(head)) {
        std::cout<<"Tree is BST\n";
    }
    else 
    {
        std::cout<<"Tree is not BST\n";	
    }
	
    delete tree;
}