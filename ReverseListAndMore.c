#include<stdio.h>
typedef struct LinkedList {
	char key;
	struct LinkedList * next;
}node;

void printList(node* List);
node* deleteFromList(node*head);
node* deleteList(node* list);
node* insertO1(node* list, char key);
node* insertCorrectPosition(node*list, char value);
node* ReverseList(node* list);



void main()
{
	node* charlist = NULL;//empty list.
	int i;
	char input;
	for (i = 0; i < 1; i++)
	{
		printf("Input chars\n");
		scanf(" %c",&input);
		charlist = insertCorrectPosition(charlist, input);

	}
	printList(charlist);
	charlist = ReverseList(charlist);
	printList(charlist);


}
node* insertO1(node* list, char key)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->key = key;
	if (list == NULL)
	{
		list = new_node;
		new_node->next = NULL;
	}
	else {
		new_node->next = list;
		list = new_node;
	}
	return list;
}

node* insertCorrectPosition(node*list, char value)
{
	/*This functions asks us to insert a letter in the list and that this letter will be in the correct position in the list as if the list was sorted.*/
	node* new_node = (node*)malloc(sizeof(node)),*tmp = list;
	new_node->key = value;
	if (list == NULL)//empty list!
	{
		list = new_node;
		new_node->next = NULL;
	}
	else if (tmp->key > value)//in case the new node needs to be first!
	{
		new_node->next = list;
		list = new_node;
	}
	else//none empty list.
	{
		while (tmp->next != NULL &&(tmp->next)->key <= value)//two conditions.
		{
			//if we reached the end of the list then the loop should break or else we will get a running time error since NULL does not have next value.
			tmp = tmp->next;// or if we get to the position where tmp->key is lesser than the inserted letter but tmp->next->key is greater. 
			//this means we are in the position we need to be (between tmp and tmp->next.)
		}
		new_node->next = tmp->next;
		tmp->next = new_node;
	}
	return list;

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
			printf("%4c", temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
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

node* deleteList(node* list)//this list frees the entire list.
{
	while (list != NULL)
	{
		list = deleteFromList(list);//delete last elements of the list each time.
	}
	return list;
}
node* ReverseList(node* list)
{
	/*As the name suggests we need to get a list such as 1->2->3->4->NULL and return 4->3->2->1->NULL*/
	node* prev, *curr, *tmp;//tmp  = next element.i chose to call it tmp since next is already taken by each list element.(the pointer to the next node).
	if (list == NULL || list->next == NULL)//if list is empty
	{
		return list;
	}
	else
	{
		//first initialization.
		prev = list;
		curr = prev->next;
		tmp = curr->next;
		prev->next = NULL;
		curr->next = prev;
		while (tmp != NULL)//loop which keeps advancing and changing the direction of the arrows of the list.
		{
			prev = curr;
			curr = tmp;
			tmp = tmp->next;
			curr->next = prev;
		}
		list = curr;//list is the head of the list - hence we need it to point to the previously "last" node.
		return list;//returnign the reveresed list.
	}
}
