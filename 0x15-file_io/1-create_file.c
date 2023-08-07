#include <fcntl.h>   
#include <sys/stat.h> 
#include <unistd.h> 
#include <string.h>
#include "main.h"

/**
 * create_file - create a file and write into it 
 * @filename: the name of the file
 * @text_content: the data to write 
 *
 * Return:  1 if success Otherwise -1.
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t data = 0;
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd < 0)
		return (-1);

	if (text_content)
		data = write(fd, text_content, strlen(text_content));

	close(fd);

	if (data < 0)
		return (-1);
	return (1);
}

