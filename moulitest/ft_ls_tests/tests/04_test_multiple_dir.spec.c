#include <project.h>

UT_TEST(04_test_multiple_dir)
{
	char *cmd;

	reset_sandbox();
	cmd = "-1 mydir mydir2";
	sandbox_cmd("mkdir mydir mydir2 && touch mydir/{aaa,bbb,ccc} && touch mydir2/{111,222,333}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	cmd = "-1 mydir mydir2";
	sandbox_cmd("mkdir mydir mydir2 && touch mydir/file{10..20} && touch mydir2/file{30..40}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	cmd = "-1 mydir{1..7}";
	sandbox_cmd("mkdir mydir{1..7} && touch mydir{1..7}/file{1..11}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	cmd = "-1 mydir";
	sandbox_cmd("mkdir mydir && touch mydir/a");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	cmd = "-1 ./mydir";
	sandbox_cmd("mkdir ./mydir && touch ./mydir/{a,b,c}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}