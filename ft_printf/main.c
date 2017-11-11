#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"

int	main(void) {
	long long	tmp = LLONG_MIN;
	int	maxint = -104;
	size_t	a = (size_t)((unsigned)-maxint);
	printf(":test du #o %#x:\n", 534455);
	printf(":test cast minint %u:\n", maxint);
	printf(":test cast size_t %lu:\n", a);
	printf(":%3.4f:\n", 534455.6233);
	printf(":%10s:\n", "Hello, world !");
	printf(":%lx:\n", tmp);
	printf(":%+-+lld:\n", tmp);
	printf(":%lu:\n", sizeof(size_t));
	printf(":%.1fiaozkeaozkeaz:\n", 5.7965, 34);
	while (1)
	{
	printf(":test sans argument %d\t%d:\n");
	}
	ft_printf(":Mon printf il est trop cool :DDD:\n%%%\n");
	ft_printf(":Mon printf il est trl :DDD:\n%%%\n");
	ft_printf(":Mon printfcool %d\t%d\t%d\t:DDD:\n%%%\n", INT_MIN);
	return(0);
}
