char	str[] = "tttttt";

ft_strclr(str);
UT_ASSERT_EQ(memcmp(str, "\0\0\0\0\0\0", 7), 0);