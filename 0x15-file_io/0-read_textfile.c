#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile-  it fisrt read texfile then  print to STDOUT.
 * @filename: the textfile that will be read
 * @letters: nbr of letterss not  read
 * Return: n - nbr of bytes read
 *         0 if function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	char *buffer;
	ssize_t t, n;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	
	
	if (file == -1)
		return (0);

	buffer  = malloc(sizeof(char) * letters);
	
	
	if (buffer == NULL)
	{
		close(file);
		return (0);
	}

	t = read(file, buffer, letters);


	if (t == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}

	n = write(STDOUT_FILENO, buffer, t);
	if (n == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}

	free(buffer);
	close(file);
	return (n);
}


