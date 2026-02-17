/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:06:07 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/02/17 15:26:45 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

double	compute_disorder(t_node *a);
void	error_exit(void);
char	**collect_tokens(int ac, char **av);
int		count_total_tokens(int ac, char **av);
int		*validate_and_parse(char **tokens, int *out);
void	free_tokens_partial(char **tokens, int count);
int		atoi_strict(const char *str, int *out);
int		check_duplicates(int *arr, int n);
int		count_words(char *s);
char	*copy_word(char *s, int *i);
t_node	*build_stack_a(int *arr, int n);
void	free_stack(t_node *stack);
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
t_node	*stack_last(t_node *stack);
typedef struct s_node
{
	int		data;
	struct s_node	*next;
}	t_node;

#endif
