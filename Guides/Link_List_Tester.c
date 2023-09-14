#include "libft.h"
#include <stdio.h>

int	main()
{
	t_list	*list = NULL; // Initi Link List Pointer
	t_list	*current; // Initi current to traverse link list during printf
	int	i; // Counter for printf
	
	// 3 ways to define a NODE
	
	//Option 1: Define a t_list node 1, assign it directly with dot notation
	t_list	node_1; // node1 of struct t_list is defined and memory is created
	char n1[20] = "hello node1"; // create content
	node_1.content = n1; // assign content with dot notation
	node_1.next = NULL; // assign next with dot notation

	
	//Option 2: create a pointer, assign pointer to allocated memory, assign content with -> notation
	t_list	*node_2; // create pointer to point to t_list struct
	node_2 = malloc(sizeof(t_list)); // create memory to allocate content and next address
	char n2[20] = "hello node2"; //create string as content for node 2
	(*node_2).content = n2; // same as ->
	node_2->next = NULL; // same as (*XX).next


	//Option 3: use fs_lstnew function to malloce and assign it to pointer
	t_list	*node_3; // define a pointer that function will point to
	node_3 = ft_lstnew("Hello node3"); // use ft_lstnew to create a new node. Pointer will point to created t_list


	// Testing functions to add node to front or back
	ft_lstadd_back(&list, node_2); // not address because node 1 is a pointer
	ft_lstadd_back(&list, node_3); // not address because node 3 is a pointer
	ft_lstadd_front(&list, &node_1); // need to feed &node_1 because node1 is not a pointer
	ft_lstadd_back(&list, ft_lstnew("Hello node4")); // use function in function

	// Print the content of the list using current to traverse
	current = list;
	i = 1;
	while (current != NULL)
	{
	printf("node %d content: %s\n", i ,(char *)current->content);
	current = current->next;
	i++;
	}
	
	return 0;
}
