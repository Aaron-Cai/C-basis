/******************************************************************/
/**Author: Jiayin Cai**********************************************/
/**Date: Feb 7, 2015***********************************************/
/**This program explains what is va_list and how to use it*********/
/******************************************************************/

#include <stdio.h>
#include <stdlib.h>


//Definition of a node of binary tree.
typedef struct Node
{
    int key_val;
    struct Node *Left;
    struct Node *Right;
}Node;

//Insert a value into a binary tree
void insert(int val,Node **node)
{
    if((*node) == 0)
    {
        *node = malloc(sizeof(Node));
        (*node)->key_val = val;
        (*node)->Left = 0;
        (*node)->Right = 0;
    }
    else
    {
        if(val < (*node)->key_val)
        {
            insert(val,&(*node)->Left);
        }
        if(val > (*node)->key_val)
        {
            insert(val,&(*node)->Right);
        }
    }
}


//search a val in a binary tree
Node* search(int key, Node *tree)
{
    if(tree != 0)
    {
        if(key == tree->key_val)
            return tree;
        else if(key < tree->key_val)
            return search(key, tree->Left);
        else
            return search(key, tree->Right);
    }
    else
        return 0;
}

//destroy a binary tree
void destroy(Node *root)
{
    if(root != 0)
    {
        destroy(root->Left);
        destroy(root->Right);
        free(root);
    }
}

//traversal a binary tree in pre order
void traversal(Node *root)
{
    if(root != 0)
    {
        printf("%d)",root->key_val);
        traversal(root->Left);
        traversal(root->Right);
    }
}

//initialize a binary tree in following form
//					10
//				6		  14
//			 5	   8	11	 18
Node* iniTree()
{
    Node *root = malloc(sizeof(Node));
    root->key_val = 10; // root

    //left sub tree
    root->Left = malloc(sizeof(Node));
    root->Left->key_val = 6;
    root->Left->Left = malloc(sizeof(Node));
    root->Left->Left->key_val = 5;
    root->Left->Left->Left = 0;
    root->Left->Left->Right = 0;
    root->Left->Right = malloc(sizeof(Node));
    root->Left->Right->key_val = 8;
    root->Left->Right->Left = 0;
    root->Left->Right->Right = 0;

    //right sub tree
    root->Right = malloc(sizeof(Node));
    root->Right->key_val = 14;
    root->Right->Left = malloc(sizeof(Node));
    root->Right->Left->key_val = 11;
    root->Right->Left->Left = 0;
    root->Right->Left->Right = 0;
    root->Right->Right = malloc(sizeof(Node));
    root->Right->Right->key_val = 18;
    root->Right->Right->Left = 0;
    root->Right->Right->Right = 0;

    return root;
}


int main()
{
    int i;
    Node* root = iniTree();

    traversal(root);
    printf("\n");
    for(i=0;i<10;i++)
    {
        insert(i,&root);
    }

    traversal(root);
    printf("\n");
    Node *p = search(5,root);
    printf("%d\n",p->key_val);
    return 0;
}