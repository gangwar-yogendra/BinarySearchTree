/* Check node value is present in binary search tree */
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
    bool findNode(Node *head, int value);
};

/* Find min value in Tree */
bool BST::findNode(Node *head, int value)
{
    if(head != NULL)
    {
        if(head->data == value) {
            return true;
		}
        else if(head->data > value)
        {
            return findNode(head->left, value);
        }
        else
        {
            return findNode(head->right, value);
        }
    }
	
    return false;
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

    if(tree->findNode(head, 50)) {
        std::cout<<"Value is present in BST: 50\n";
    }
    else 
    {
        std::cout<<"Unable to find the value in BST: 50\n";	
    }
	
    if(tree->findNode(head, 150)) {
        std::cout<<"Value is present in BST: 150\n";
    }
    else 
    {
        std::cout<<"Unable to find the value in BST: 150\n";	
    }
	
    delete tree;
    return 0;
}
