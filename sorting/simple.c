/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@local>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:55:00 by copilot           #+#    #+#             */
/*   Updated: 2026/02/26 23:55:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_min_index(t_node *a)
{
    int     idx;
    int     i;
    int     min;
    t_node  *cur;

    if (!a)
        return (-1);
    i = 0;
    idx = 0;
    cur = a;
    min = cur->data;
    while (cur)
    {
        if (cur->data < min)
        {
            min = cur->data;
            idx = i;
        }
        cur = cur->next;
        i++;
    }
    return (idx);
}

void	simple_min_extract(t_node **a, t_node **b, t_ops *ops)
{
    int n;
    int idx;

    if (!a || !*a)
        return ;
    n = stack_size(*a);
    if (n <= 3)
    {
        if (!is_sorted(*a))
            sort_3(a, ops);
        return ;
    }
    while (stack_size(*a) > 3)
    {
        idx = find_min_index(*a);
        n = stack_size(*a);
        if (idx <= n / 2)
        {
            while (idx-- > 0)
                ra(a, ops);
            pb(a, b, ops);
        }
        else
        {
            idx = n - idx;
            while (idx-- > 0)
                rra(a, ops);
            pb(a, b, ops);
        }
    }
    if (!is_sorted(*a))
        sort_3(a, ops);
    while (*b)
        pa(a, b, ops);
}
