int		out;
int		p[2];
char	buf[4];

out = dup(1);
pipe(p);
dup2(p[1], 1);
ft_putendl("aa");
dup2(out, 1);
read(p[0], buf, 3);
buf[3] = 0;
close(p[0]);
close(p[1]);
close(out);
UT_ASSERT_EQ(strcmp(buf, "aa\n"), 0);