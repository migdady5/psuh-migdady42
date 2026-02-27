/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:28:04 by amigdadi          #+#    #+#             */
/*   Updated: 2026/02/27 00:53:19 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_ops	ops;
	t_node	*a;
	t_node	*b;
	int		token_count;
	int		num_count;
	int		first_num_i;
	t_mode	mode;
	int		*arr;
	char	**tokens;

	if (ac < 2)
		return (0);
	ops_init(&ops);
	a = NULL;
	b = NULL;
	arr = NULL;
	tokens = NULL;
	token_count = 0;
	num_count = 0;
	first_num_i = 1;

	if (!parse_flags(ac, av, &mode, &first_num_i))
     error_exit();

	tokens = collect_tokens(ac, av, first_num_i, &token_count);
	if (!tokens)
		error_exit();

	num_count = token_count;
	arr = validate_and_parse(tokens, &num_count);
	free_tokens_partial(tokens, token_count);
	tokens = NULL;

	if (!arr)
		error_exit();

	a = build_stack_a(arr, num_count);
	free(arr);

	if (a && !is_sorted(a))
    sort(&a, &b, &ops, (int)mode);

	free_stack(a);
	free_stack(b);
	return (0);
}