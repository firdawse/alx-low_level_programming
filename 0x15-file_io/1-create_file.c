#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file -function that creates  a file.
 * @filename: pointer to the name of filename we will create .
 * @text_content: A pointer to the part of text in the file .
 *
 * Return: If the function fails - -1.
 *         or  - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int file, n, length = 0;

	if (filename == NULL)
		return (-1);


	if (text_content != NULL)
	{
		for (len = 0; text_content[length]; length++;
	}

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file == -1)
		return (-1);

	n = write(file, text_content, length);

	if (n == -1)
	{
		close(file);
		return (-1);
	}

	close(file);

	return (1);
}
