// cycle 6 : linked list
// pgm by Aromal

/* Questions :

1.
	1. append at end of linked list

2.
	2. insert after node data
	3. insert before node data
	4. insert at pos

3.
	5. delete node given data
	6. delete node at pos
	7. delete smallest element

4.
	8. Reverse list

5.	
	9. search for element and print pos

6.
	10. create list in sorted order

11. implement stack

*/

#include<stdio.h>
#include<stdlib.h>

void append(int c);		//
void insert(int c);		//
void delete(int c);		//
void reverse(void);		//
int search(int c);		//
void sort(void);		//
void display(void); 	//

// linked list structure
struct node
{
	int data;
	struct node*link; // next
};
struct node*first = NULL; // First node (global)

// append
void append(int c)
{
	/* 
	Help :
		Append element int c at end of linked list.
	*/
	
	struct node*temp = first;
	struct node*new; // new node
	
	// size allocation
	new = (struct node*)malloc(sizeof(struct node));
	
	new->data = c;
	new->link = NULL;
	
	if (first == NULL)
	{
		first = new;
	}
	else
	{
		while(temp->link!=NULL)
		{
			temp = temp->link;
		}
		temp->link = new;
	}
	
}

// insert
void insert(int c)
{
	/* 
	Help :
		inserts element :
			1. before data
			2. after data
			3. at postion
		based on c.
	*/
	
	struct node*temp = first;	// temp node
	
	// new node
	struct node*new;
	new = (struct node*)malloc(sizeof(struct node));
	
	printf("Please enter value of node to be inserted : ");
	scanf("%d",&new->data);
	new->link = NULL;
	
	switch(c)
	{
		case 1: // before data
		
			printf("Enter value to insert before of : ");
			scanf("%d",&c);
			
			// if first node
			if (temp->data == c)
			{
				new->link = temp;
				first = new;
			}
			else
			{
				while (temp->link->data != c && temp->link != NULL)
				{
					temp = temp->link;
				}
				
				if (temp->link == NULL)
				{
					printf("Error : Data not in list.\nElement insertion failed.\n");
					return;
				}
				
				new->link = temp->link;
				temp->link = new;
			}
			
			break;
		
		case 2:	// after data
		
			printf("Enter value to insert after of : ");
			scanf("%d",&c);
			
			while(temp->data != c && temp != NULL)
			{
				temp = temp->link;
			}
			
			if (temp == NULL)
			{
				printf("Error : Data not in list.\nElement insertion failed.\n");
				return;
			}
			
			new->link = temp->link;
			temp->link = new;
			
			break;
		
		case 3:	// at pos
		
			int i=0;
		
			printf("Enter index to be inserted at : ");
			scanf("%d",&c);
			
			if (c == 0)
			{
				new->link = temp;
				first = new;
				return;
			}
		
			while(i < c-1 && temp != NULL)
			{
				temp = temp->link;
				i++;
			}
			
			if (temp == NULL)
			{
				printf("Error : Out of index range.\nElement insertion failed.\n");
				return;
			}
			
			new->link = temp->link;
			temp->link = new;
		
			break;
		
		default:
			printf("Error : Invalid case!");
			return;
			break;
	}
	printf("Element Inserted.\n");
}

// small
int small()
{
	/* 
	Help : 
		returns index of node with smallest data
	*/

	struct node*temp = first;	// temp node
	if (temp == NULL)
	{
		//printf("Error : Empty List. Enter elements before function.\n")
		return -1;
	}
	
	int value = temp->data, pos = 0, c = 0;
	
	while(temp!=NULL)
	{
		if (temp->data < value)
		{
			value = temp->data;
			pos = c;
			
		}
		c++;
		temp = temp->link;
	}
	
	return pos;
	
}

// delete
void delete(int c)
{
	/* 
	Help :
		delete node :
			1. of data
			2. of postion
			3. of smallesty data
		based on c.
	*/
	
	struct node*temp = first;	// temp node
	struct node*del_temp;
	
	int i = 1;
	
	if (temp == NULL)
	{
		printf("Error : Empty List. Enter elements before deletion.\n");
		return;
	}
	
	switch(c)
	{
		case 1: // delete node of data
			printf("Enter Data value : ");
			scanf("%d",&c);
			
			// if first
			if (temp->data = c)
			{
				del_temp = temp;
				first = temp->link;
				free(temp);
				return;
			}
			
			while(temp->link->data != c && temp->link != NULL)
			{
				temp = temp->link;
			}
			
			if(temp->link == NULL)
			{
				printf("Error : element not in list.\nDeletion Failed.\n");
				return;
			}
			
			del_temp = temp->link;
			temp->link = del_temp->link;
			free(del_temp);
			break;
			
		case 2: // delete node of position
			printf("Enter index of value to be deleted : ");
			scanf("%d",&c);
			
			// if first
			if (c == 0)
			{
				del_temp = temp;
				first = temp->link;
				free(temp);
				return;
			}
			
			while (i<c && temp != NULL)
			{
				temp = temp->link;
				i++;
			}
			
			if (temp == NULL)
			{
				printf("Error : Out of index range.\nDeletion failed.\n");
				return;
			}
			
			del_temp = temp->link;
			temp->link = del_temp->link;
			free(del_temp);
			break;
		
		case 3:
			
			c = small();
			
			if (c == 0)
			{
				del_temp = temp;
				first = temp->link;
				free(temp);
				return;
			}
			
			while (i<c && temp != NULL)
			{
				temp = temp->link;
				i++;
			}
			
			if (temp == NULL)
			{
				printf("Error : Out of index range.\nDeletion failed.\n");
				return;
			}
			
			del_temp = temp->link;
			temp->link = del_temp->link;
			free(del_temp);
			break;
	}
	printf("Element Deleted.\n");
}

// reverse
void reverse()
{
	/*
	Help:
		Reverses current linked list.
	*/
	
	struct node*temp = first;
	struct node*del_temp;
	int a[50],c=0;
	
	while (temp!=NULL)
	{
		a[c] = temp->data;
		
		del_temp = temp;
		temp = del_temp->link;
		free(del_temp);
		c++;
	}
	
	first = NULL;
	
	for (c=c-1;c>=0;c--)
	{
		append(a[c]);
	}
	
	printf("Linked List Reversed.\n");
}

// search
int search(int c)
{
	/*
	Help :
		Search for int c in linked list and returns index and -1 if not in list.
	*/
	
	struct node*temp = first;	// temp node

	int pos = -1, i = 0;
	
	while(temp!=NULL)
	{
		if (temp->data == c)
		{
			pos = i;
			break;
		}
		i++;
		temp = temp->link;
	}
	
	return pos;
}

// node len
int len(struct node*temp)
{
	/*
	Help:
		returns length of linked list.
	*/
	
	int c = 0;
	
	while(temp != NULL)
	{
		c++;
		temp = temp->link;
	}
	
	return c;
}


// sort
void sort()
{
	/* 
	Help:
		Sorts linked list in Ascending order.
	*/
	
	struct node*temp = first;
	int l = len(first)-1,i=0,j=0;
	int k = l;
	
	for(i=0;i<l;i++)
	{
		for(j=0;j<k-i;j++)
		{
			if (temp->data > temp->link->data)
			{
				int t = temp->data;
				
				temp->data = temp->link->data;
				temp->link->data = t;				
			}
			temp = temp->link;
		}
		temp = first;
	}
	
	printf("Linked list Sorted.\n");
}

// display
void display()
{
	/* 
	Help :
		Display entire linked list from first node till end.
	*/	
	
	struct node*temp = first;
	
	if (temp == NULL)
	{
		printf("List Empty.");
		return;
	}
	
	printf("Current list : ");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->link;
	}
}

// main function
int main()
{
	int c;
	
	do
	{
		// Menu
		printf("\nMenu : \n1. Append\n2. Insert\n3. Delete\n4. Reverse\n5. Search\n6. Sort\n7. Display\n8. Exit\n\tchoice : ");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1: // append
				// 1. append at end of linked list
				
				printf("Please enter value of node : ");
				scanf("%d",&c);
				append(c);
				printf("Node Appended.\n");
				
				break;
			
			case 2: // insert
				// 2. insert after node data
				// 3. insert before node data
				// 4. insert at pos
				
				printf("\nSub Menu :\n1. Before node data\n2. After node data\n3. At position\n\tChoice : ");
				scanf("%d",&c);
				insert(c);
				
				break;
			
			case 3: // delete
				// 5. delete node given data
				// 6. delete node at pos
				// 7. delete smallest element
				
				printf("\nSub Menu :\n1. node of data\n2. node of position\n3. node of smallest data\n\tChoice : ");
				scanf("%d",&c);
				delete(c);
				
				break;
			
			case 4: // reverse
				// 8. Reverse list
				
				reverse();
				
				break;
			
			case 5: // search
				// 9. search for element and print pos
				
				printf("Please enter value of node to search : ");
				scanf("%d",&c);
				c = search(c);
				if(c!=-1)
					printf("Element found in index %d.\n",c);
				else
					printf("Element not in list.\n");
				
				break;
			
			case 6: // sort
				// 10. create list in sorted order
				
				sort();
				
				break;
				
			case 7: // displays current linked list
				display();
				printf("\nList Printed.");
				c = -20;
				break;
			
			case 8: // exit
				printf("Thank you!");
				return 0;
				break;
			
			default: // invalid input
				printf("Invalid Input!");
				break;
		}
		
		if (c!=-20)
			display();
		printf("\n");
	}
	while(1);
	
	return 0;
}