/* Are two binary trees same */
/**
  50                 50
 / \                / \
40  70             40 70
   / \                / \
  60  80             60 80
  
**/

// Example program
#include <iostream>

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
    bool isSameTree(Node *a, Node *b);
};

bool BST::isSameTree(Node *a, Node *b)
{
    if(a==NULL && b==NULL) {
        return true;
    }
    else 
    {    
        if(a!=NULL && b!=NULL)
        {
            return ((a->data == b->data) &&
                isSameTree(a->left, b->left) &&
                isSameTree(a->right, b->right));
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
 
    std::cout<<"InOrder Tree 1: ";
    tree->InOrder(head);
    std::cout<<"\n";
    
    Node *head1 = NULL;  
    //BST *tree = new BST();
  
    tree->InsertBST(&head1, 50);
    tree->InsertBST(&head1, 40);
    tree->InsertBST(&head1, 70);
    tree->InsertBST(&head1, 60);
    tree->InsertBST(&head1, 80);
 
    std::cout<<"InOrder Tree 2: ";
    tree->InOrder(head1);
    std::cout<<"\n";
    
    if((tree->isSameTree(head, head1)) == true)
    {
        std::cout<<"Tree are same\n";
    } else
    {
        std::cout<<"Tree are not same\n";
    }
	
    delete tree;
    
    return 0;
}
