#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define true 1
#define false 0

typedef struct {

	int val;
	struct Node* previous;
	struct Node* next;

}Node, *NodeP;

NodeP Initializelist(int value)
{
	NodeP start = malloc(sizeof(Node));

	start->val = value;

	start->previous = NULL;

	start->next = NULL;

	return start;
}

void Addelements(NodeP start, int value)
{
	NodeP current = start;

	
	while (current->next != NULL)
	{
		current = current->next;
	}

	NodeP newnode = malloc(sizeof(Node));

	newnode->val = value;

	current->next = newnode;

	newnode->previous = current;

	newnode->next = NULL;
}

void Print(NodeP start)
{
	NodeP current = start;
	
	printf("\n");
	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

int size(NodeP start)
{
	NodeP current = start;

	int size = 0;

	while (current != NULL) {
		size++;
		current = current->next;
	}

	return size;
}

void DeleteList(NodeP node)
{
	NodeP current = node;

	if (current != NULL) {

		DeleteList(current->next);
	}

	free(node);
}

bool IfElementExists(NodeP start, int value)
{
	NodeP current = start;
	bool doesexists = false;

	while (current != NULL)
	{
		if (current->val == value)
		{
			doesexists = true;
			break;
		}
		current = current->next;
	}
	return doesexists;
}

int GetIndexof(NodeP start,int value)
{
	NodeP current = start;
	int index = 0;

	bool doeselelementexist = IfElementExists(current, value);

	while (current != NULL) {
		if (current->val == value)
		{
			break;
		}
		index++;
		current = current->next;
	}
	if (doeselelementexist)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

void AddAfter(NodeP start, int after, int value)
{
	bool doeselelementexist = IfElementExists(start, after);

	if (doeselelementexist)
	{
		NodeP current = start;

		while (current->val != after)
		{
				current = current->next;
			
		}

		if (current->next == NULL)
		{
			Addelements(start, value);
		}
		else
		{
			NodeP newnode = malloc(sizeof(Node));

			newnode->val = value;

			NodeP currnext = current->next;

			current->next = newnode;

			currnext->previous = newnode;

			newnode->previous = current;

			newnode->next = currnext;
		}

	}
	else
	{
		printf("Error Element does not exists");
	}
}

void PrintReverse(NodeP node)
{
	NodeP current = node;

	while (current->next != NULL)
	{
		current = current->next;
	}
	printf("\nReverse\n");
	while (current != NULL)
	{
		printf("%d\n", current->val);
		current = current->previous;
	}
}

void InsertAt(NodeP start, int index, int value)
{
	if (index == size(start))
	{
		Addelements(start, value);
	}
	else if (index == 0)
	{
		int secondval = start->val;

		start->val = value;

		NodeP newnode = malloc(sizeof(Node));

		newnode->val = secondval;

		NodeP third = start->next;

		start->next = newnode;

		newnode->previous = start;

		newnode->next = third;

		third->previous = newnode;
	}
	else if (index < size(start) && index > 0)
	{
		int counter = 0;

		NodeP current = start;

		while (current->next != NULL)
		{
			if (counter == index)
			{
				break;
			}
			counter++;
			current = current->next;
		}

		AddAfter(start, current->val, value);
	}
	else
	{
		printf("Index Out bound error");
	}
	
}

void DeleteAt(NodeP first, int index)
{
	if (index == (size(first)-1))
	{
		NodeP current = first;

		while (current->next != NULL)
		{
			current = current->next;
		}

		NodeP newlast = current->previous;

		current->previous = NULL;
		newlast->next = NULL;
		current->val = 0;
		free(current);
	}
	else if (index == 0)
	{
		
		printf("Not Implemented yet");
	}
	else if (index > 0 && index < size(first))
	{
		int counter = 0;

		NodeP current = first;

		while (current->next != NULL)
		{
			if (counter == index)
			{
				break;
			}
			counter++;
			current = current->next;
		}

		NodeP prev = current->previous;
		NodeP aft = current->next;

		prev->next = aft;
		aft->previous = prev;

		free(current);
	}
}


int main()
{
	NodeP node = Initializelist(10);

	Addelements(node, 20);
	Addelements(node, 30);
	Addelements(node, 40);
	Addelements(node, 50);
	Addelements(node, 60);

	AddAfter(node, 60, 65);

	AddAfter(node, 10, 70);

	InsertAt(node, 8, 80);

	InsertAt(node, 9, 90);

	InsertAt(node, 0, 8);

	InsertAt(node, 2, 22);

	InsertAt(node, 3, 33);

	DeleteAt(node, 12);

	DeleteAt(node, 0);

	Print(node);

	PrintReverse(node);
	
	printf("\n Test Priting\n");
	printf("%d\n", size(node));

	printf("%d\n", GetIndexof(node, 8));

	printf("%d\n", IfElementExists(node, 60));

	DeleteList(node);

}