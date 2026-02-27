#include "pushswap.h"

/* طباعة الستاك بسرعة */
static void	print_stack(const char *name, t_node *s)
{
	write(1, name, ft_strlen(name));
	write(1, ": ", 2);
	while (s)
	{
		ft_putnbr_fd(s->data, 1);
		if (s->next)
			write(1, " ", 1);
		s = s->next;
	}
	write(1, "\n", 1);
}

static t_node	*push_back(t_node *head, int x)
{
	t_node	*n;
	t_node	*last;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->data = x;
	n->next = NULL;
	if (!head)
		return (n);
	last = head;
	while (last->next)
		last = last->next;
	last->next = n;
	return (head);
}

static void	free_list(t_node *s)
{
	t_node	*tmp;

	while (s)
	{
		tmp = s->next;
		free(s);
		s = tmp;
	}
}

int	main(void)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	/* A = 1 2 3 */
	a = push_back(a, 1);
	a = push_back(a, 2);
	a = push_back(a, 3);

	/* B = 9 8 */
	b = push_back(b, 9);
	b = push_back(b, 8);

	print_stack("A before", a);
	print_stack("B before", b);

	sa(&a, NULL);
	sb(&b, NULL);
	ss(&a, &b, NULL);
	pa(&a, &b, NULL);
	pb(&a, &b, NULL);

	ra(&a, NULL);
	rb(&b, NULL);
	rr(&a, &b, NULL);

	rra(&a, NULL);
	rrb(&b, NULL);
	rrr(&a, &b, NULL);

	print_stack("A after", a);
	print_stack("B after", b);

	free_list(a);
	free_list(b);
	return (0);
}