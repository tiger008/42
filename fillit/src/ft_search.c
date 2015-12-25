short	ft_search(short val, short *t, short size)
{
	short	start;
	short	end;
	short	mid;

	start = 0;
	end = size - 1;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (t[mid] == val)
			return (1);
		else if (val > t[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}
