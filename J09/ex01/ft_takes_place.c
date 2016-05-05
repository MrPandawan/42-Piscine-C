/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 13:16:23 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/23 13:18:36 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_place(int hour, int hour2)
{
	if (hour < 11 && hour > 0)
		printf("%d.00 A.M. AND %d.00 A.M.\n", hour2, hour2 + 1);
	else if (hour == 11)
		printf("%d.00 A.M. AND %d.00 P.M.\n", hour2, hour2 + 1);
	else if (hour == 12)
		printf("12.00 P.M AND 01.00 P.M.\n");
	else if (hour > 11 && hour < 23)
		printf("%d.00 P.M. AND %d.00 P.M.\n", hour2, hour2 + 1);
	else if (hour == 23)
		printf("11.00 P.M. AND 12 A.M.\n");
	else
		printf("12.00 A.M. AND 01.00 A.M.\n");
}

void	ft_takes_place(int hour)
{
	int hour2;

	hour2 = hour % 12;
	write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
	ft_place(hour, hour2);
}
