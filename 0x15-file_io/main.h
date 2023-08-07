#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
int create_file(const char *filename, char *text_content);
int _strncmp(const char *s1, const char *s2, size_t n);
void elf_close(int fd);
void magic(const unsigned char *buffer);
size_t class(const unsigned char *buffer);
int data(const unsigned char *buffer);
void version(const unsigned char *buffer);
void osabi(const unsigned char *buffer);
void abi(const unsigned char *buffer);
void type(const unsigned char *buffer, int needed);
void entry(const unsigned char *buffer, size_t bit_mode, int needed);

