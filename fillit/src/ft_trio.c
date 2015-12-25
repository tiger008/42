#include "fillit.h"

short	ft_trio(short x)
{
	short	*t;
	short	trio;

	trio = 0;
	t = I;
	if (++trio && ft_search(x, t, 4))
		return (trio);
	t = I_h;
	if (++trio && ft_search(x, t, 4))
		return (trio);
	t = J;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = J_i;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = J_rg;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = J_rd;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = L;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = L_i;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = L_rg;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = L_rd;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = S;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = S_r;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = Z;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = Z_r;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = T;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = T_i;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = T_rg;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = T_rd;
	if (++trio && ft_search(x, t, 6))
		return (trio);
	t = T_rd;
	if (++trio && ft_search(x, t, 8))
		return (trio);
	return (0);
}
