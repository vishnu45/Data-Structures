#include <iostream>
using namespace std;

struct LinkedList
{
	int data;
	struct LinkedList *next;
};

//--------------------------------------------------------------------
// Function: To print all elements in the linked list whose head node 
// is provided
//--------------------------------------------------------------------
void disp_list(struct LinkedList *node)
{
	while(node != NULL)
	{
		cout << node -> data << "->";
		node = node -> next;
	}
	cout << endl;
}

//--------------------------------------------------------------------
// Function: To insert element in between Linked List
//--------------------------------------------------------------------
void insert_btw(struct LinkedList **head, int value)
{
	struct LinkedList *new_node = new LinkedList;
	struct LinkedList *node = new LinkedList;
	node = *head;
	new_node -> data = value;
	while (true)
	{
		// if value lesser than starting element
		if( node -> data >= value)
		{
			new_node -> next = node;
			*head = new_node;
			break;
		}

		// if value greater than last element
		if( node -> next == NULL)
		{
			new_node -> next = NULL;
			node -> next = new_node;
			break;
		}

		if (((node -> data) < value) && 
			(((node -> next) -> data) >= value))
		{
			new_node -> next = node -> next;
			node -> next = new_node;
			break;
		}
		node = node -> next;
	}
}

//--------------------------------------------------------------------
// Function: To delete a particular value from the Linked List
//--------------------------------------------------------------------
void delete_val(struct LinkedList **head, int value)
{
	struct LinkedList *node = new LinkedList;
	node = *head;

	cout << "Value to delete: " << value << endl;
	while(true)
	{
		if(node -> next == NULL)
		{
			cout << "Value requested not in provided Linked list" << endl;
			break;
		}
		if(node -> data == value)
		{
			
			*head = (*head) -> next;			
			break;
		}

		else if( (node -> next) -> data == value )
		{
			if( (node -> next) -> next == NULL )
			{
				node -> next = NULL;
			}
			else
			{
				node -> next = (node -> next) -> next;
			}
			break;
		}		
		node = node -> next;
	}
}


int main()
{
	struct LinkedList *head = new LinkedList;
	head -> data = 1;
	head -> next = NULL;

	// insert few nodes in the linked list
	insert_btw(&head, 2);
	insert_btw(&head, 3);
	insert_btw(&head, 4);
	insert_btw(&head, 5);

	// display original linked list
	disp_list(head);

	// delete elements
	delete_val(&head, 2);
	disp_list(head);
	delete_val(&head, 1);
	disp_list(head);
	delete_val(&head, 5);
	disp_list(head);
	delete_val(&head, 6);
	disp_list(head);

	return 0;
}