#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int val;
	struct Node* leftchild;
	struct Node* rightchild;

} Node, *NodePtr;

NodePtr MakeNode(int value)
{
	NodePtr nptr = malloc(sizeof(Node));
	nptr->val = value;
	nptr->leftchild = NULL;
	nptr->rightchild = NULL;
	return nptr;
}

void AddNode(NodePtr node, int val)
{
    NodePtr newnode = MakeNode(val);

    NodePtr currentnode = node;

    while (currentnode != NULL)
    {
        if (currentnode->val > newnode->val)
        {
            if (currentnode->leftchild == NULL)
            {
                currentnode->leftchild = newnode;
                break;
            }

            currentnode = currentnode->leftchild;
        }
        else
        {
            if (currentnode->rightchild == NULL)
            {
                currentnode->rightchild = newnode;
                break;
            }
            currentnode = currentnode->rightchild;
        }

    }
}


void InOrder(NodePtr node)
{
    if (node != NULL)
    {
        InOrder(node->leftchild);
        printf("InOrder %d \n", node->val);
        InOrder(node->rightchild);
    }
}

void PostOrder(NodePtr node)
{
    if (node != NULL)
    {
        PostOrder(node->leftchild);
        PostOrder(node->rightchild);
        printf("PostOrder %d \n", node->val);
    }
}

void PreOrder(NodePtr node)
{
    if (node != NULL)
    {
        printf("Pre Order %d \n", node->val);
        PreOrder(node->leftchild);
        PreOrder(node->rightchild);
    }
}

void DeleteNodes(NodePtr node)
{
    if (node != NULL)
    {
        DeleteNodes(node->leftchild);
        DeleteNodes(node->rightchild);
    }

    free(node);
}

int main()
{
	NodePtr node = MakeNode(40);
    AddNode(node,10);
    AddNode(node,30);
    AddNode(node,45);
    AddNode(node,50);
    AddNode(node, 60);
    AddNode(node, 100);
    AddNode(node, 35);
    AddNode(node, 65);
    AddNode(node, 82);
    AddNode(node, 57);
    AddNode(node, 41);
    AddNode(node, 120);
    AddNode(node, 130);
    AddNode(node, 15);
    AddNode(node, 25);
    InOrder(node);
    PostOrder(node);
    PreOrder(node);
    DeleteNodes(node);
}
