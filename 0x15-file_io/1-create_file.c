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
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		length = strlen(text_content);
	}

	o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(o, text_content, length);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}

