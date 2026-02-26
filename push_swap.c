/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:28:04 by amigdadi          #+#    #+#             */
/*   Updated: 2026/02/26 19:46:37 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	char	**tokens;
	int		*arr;
	int		count;
	t_node	*a;

	if (ac < 2)
		return (0);
	count = 0;
	tokens = collect_tokens(ac, av, &count);
	if (!tokens)
		return (0);

	arr = validate_and_parse(tokens, &count);
	if (!arr)
	{
		free_tokens_partial(tokens, count);
		error_exit();
	}

	a = build_stack_a(arr, count);
	free_tokens_partial(tokens, count);
	free(arr);
	if (!a)
		error_exit();

	if (is_sorted(a))
		return (free_stack(a), 0);

	/* algorithms later */
	free_stack(a);
	return (0);
}