#include<stdio.h>
typedef struct LinkedList {
	int key;
	struct LinkedList *next;
}node;

void printList(node* List);

node* insert(node* head, int value);
node* insertO1(node* head, int value);
node* deleteFromList(node*head);
node* deleteList(node* list);
int OddEvenLists(node**list1, node**list2);
int SumOfList(node* head, int*max, int*min);


void main()
{
	node *list1, *list2;
	int test,min,max;
	list1 = list2 = NULL;//empty lists.
	test = OddEvenLists(&list1, &list2);
	printList(list1);
	printList(list2);
	test = SumOfList(list2, &max, &min);
	printf("Sum = %d, max = %d, min = %d\n", test, max, min);
	list1 = deleteList(list1);
	printList(list1);
	
	
}

node* insert(node* head, int value)
{
	//allocate a new node, and insert it into the list which was given.
	node* new_node = (node*)malloc(sizeof(node)),*temp = head;//creating a new node.
	new_node->key = value;
	new_node->next = NULL;
	if (head == NULL)//list is empty
	{
		head = new_node;
	}
	else//run all the way to the last node, which points to NULL, make the last node point to new_node => new_node is the last node.
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
	return head;
}

node* insertO1(node* head, int value)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->key = value;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		
		new_node->next = head ;
		head = new_node;
	}
	return head;
}
node* deleteFromList(node*head)
{
	node* temp = head;
	if (head == NULL)
	{
		printf("List is empty!");
	}
	else if (head->next == NULL)//only one item
	{
		free(head);
		return NULL;
	}
	else
	{
		while ((temp->next)->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;

	}
	return head;
}

void printList(node* List)
{
	node* temp = List;
	if (List == NULL)
	{
		printf("List is empty!\n");
	}
	else
	{
		while (temp != NULL)
		{
			printf("%4d", temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
}
int OddEvenLists(node**list1, node**list2)
{
	int input, counter = 0;
	printf("Input the next value:\n");
	scanf("%d", &input);
	while (input != -1)
	{
		counter++;
		if (input % 2 == 0)
		{
			*list1 = insertO1(*list1, input);
		}
		else
		{
			*list2 = insertO1(*list2, input);
		}
		printf("Input the next value:\n");
		scanf("%d", &input);
	}
	return counter;
}
node* deleteList(node* list)
{
	while (list != NULL)
	{
		list = deleteFromList(list);
	}
	return list;
}
int SumOfList(node* head, int*max, int*min)
{
	node* temp = head;
	int sum;
	if (head == NULL)
	{
		*max = *min = sum = 0;
		return sum;
	}
	*max = *min = sum = temp->key;
	temp = temp->next;

	while (temp != NULL)
	{
		sum += temp->key;
		if (temp->key > *max)
		{
			*max = temp->key;
		}
		else if (temp->key < *min)
		{
			*min = temp->key;
		}
		temp = temp->next;
	}
	return sum;
}