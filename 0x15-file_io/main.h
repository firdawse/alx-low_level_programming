#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int _strncmp(const char *s1, const char *s2, size_t n);
void elf_close(int fd);
void file_read(int fd, char *buf, size_t count);
void magic(const unsigned char *buffer);
size_t class(const unsigned char *buffer);
int data(const unsigned char *buffer);
void version(const unsigned char *buffer);
void osabi(const unsigned char *buffer);
void abi(const unsigned char *buffer);
void type(const unsigned char *buffer, int needed);
void entry(const unsigned char *buffer, size_t bit_mode, int needed);
