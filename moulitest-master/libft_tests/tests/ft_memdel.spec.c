void	*mem;

mem = malloc(2000);
ft_memdel(&mem);
UT_ASSERT_EQ(mem, NULL);

/* test edge cases */
void	*mem2;
mem2 = NULL;
ft_memdel(NULL);
ft_memdel(&mem2);
