
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:59:05 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/08 20:59:06 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max_bits(int *arr, int size)
{
    int max = arr[0];
    int i = 1;

    while (i < size)
    {
        if (arr[i] > max)
            max = arr[i];
        i++;
    }
    unsigned long um = (max < 0) ? (unsigned long)(-(long)max) : (unsigned long)max;

    int bits = 0;
    while ((um >> bits) != 0)
        bits++;

    return bits;
}

static void split_by_bit(int *arr, int size, int bit, int *zero, int *one, int *zi, int *oi)
{
    int i = 0;
    while (i < size)
    {
        if (((arr[i] >> bit) & 1) == 0)
            zero[(*zi)++] = arr[i];
        else
            one[(*oi)++] = arr[i];
        i++;
    }
}

static void merge_arrays(int *arr, int *zero, int *one, int zi, int oi)
{
    int j = 0;
    int i = 0;
    while (i < zi)
        arr[j++] = zero[i++];
    i = 0;
    while (i < oi)
        arr[j++] = one[i++];
}

void radix_pass(int *arr, int size, int bit)
{
    int *zero = calloc(size, sizeof(int));
    int *one = calloc(size, sizeof(int));
    int zi = 0, oi = 0;

    if (!zero || !one)
    {
        free(zero);
        free(one);
        return;
    }

    split_by_bit(arr, size, bit, zero, one, &zi, &oi);
    merge_arrays(arr, zero, one, zi, oi);

    free(zero);
    free(one);
}
