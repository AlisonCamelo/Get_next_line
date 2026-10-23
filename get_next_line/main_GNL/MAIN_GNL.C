int main(void)
{
    char 	*next_line;
    int		fd;
    int 	line_num = 1;
	
    fd = open("example.txt", O_RDONLY);
	
    while ((next_line = get_next_line(fd)) != NULL)
    {
        printf("Línea [%d]: %s", line_num++, next_line);
        free(next_line);
    }
	if (next_line)
	free(next_line);
    close(fd);
    return (0);
}

