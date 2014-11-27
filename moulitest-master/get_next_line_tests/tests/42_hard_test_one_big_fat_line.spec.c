system("mkdir -p sandbox");
system("openssl rand -base64 $((2**15 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");

char *line;
int fd;
int fd2;


fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

while (get_next_line(fd, &line) == 1)
{
    write(fd2, line, strlen(line));
    write(fd2, "\n", 1);
}
write(fd2, line, strlen(line));
close(fd);
close(fd2);

int fd3;
int	diff_file_size;
system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
diff_file_size = read(fd3, NULL, 10);
close(fd3);

UT_ASSERT(diff_file_size == 0);
