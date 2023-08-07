#ifndef MAIN
#define MAIN

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *file_name, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
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

#endif
