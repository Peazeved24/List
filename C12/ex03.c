#include "struct.h"

t_list *ft_creat(void *data)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;

	return node;
}


t_list *ft_list_last(t_list *begin_list)
{
	t_list	*head;
	t_list	*curr;

	if (!begin_list)
		return (NULL);

	head = begin_list;
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

int	main()
{
	t_list *n1, *n2, *n3;

	int		a, b, c;

	a = 4;
	b = 7;
	c = -2147483648; // ultimo elemento!

	n1 = ft_creat(&a);
	n2 = ft_creat(&b);
	n3 = ft_creat(&c);

	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	t_list *t = ft_list_last(n1);

	printf("%i", *(int*)t->data);

	return 0;
}