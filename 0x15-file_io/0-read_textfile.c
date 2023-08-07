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
	char *buffer;
	ssize_t o, r, w;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}


