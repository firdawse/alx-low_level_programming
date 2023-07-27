#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file.
 * @filename: Pointer to the name of the file to create.
 * @text_content: Pointer to the content to write into the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
        int file, n, length = 0;

        if (filename == NULL)
                return (-1);

        if (text_content != NULL)
        {
                for (length = 0; text_content[length]; length++);
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

