#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the max number of bytes to compare
 *
 * Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}

/**
 * elf_close - close a file descriptor and print an error message upon failure
 * @fd: the file descriptor to close
 */
void elf_close(int fd)
{
	if (close(fd) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

/**
 * file_read - read from a file and print an error message upon failure
 * @fd: the file descriptor to read from
 * @buf: the buffer to write to
 * @count: the number of bytes to read
 */
void file_read(int fd, char *buf, size_t count)
{
	if (read(fd, buf, count) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	elf_close(fd);
	exit(98);
}

/**
 * magic - print ELF magic
 * @buffer: the ELF header
 */
void magic(const unsigned char *buffer)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", buffer[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class - print ELF class
 * @buffer: the ELF header
 *
 * Return: bit mode (32 or 64)
 */
size_t class(const unsigned char *buffer)
{
	printf("  %-34s ", "Class:");

	if (buffer[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buffer[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buffer[EI_CLASS]);
	return (32);
}

/**
 * data - print ELF data
 * @buffer: the ELF header
 *
 * Return: 1 if big endian, otherwise 0
 */
int data(const unsigned char *buffer)
{
	printf("  %-34s ", "Data:");

	if (buffer[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buffer[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * version - print ELF version
 * @buffer: the ELF header
 */
void version(const unsigned char *buffer)
{
	printf("  %-34s %u", "Version:", buffer[EI_VERSION]);

	if (buffer[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * osabi - print ELF OS/ABI
 * @buffer: the ELF header
 */
void osabi(const unsigned char *buffer)
{
	const char *os_table[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  %-34s ", "OS/ABI:");

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * abi - print ELF ABI version
 * @buffer: the ELF header
 */
void abi(const unsigned char *buffer)
{
	printf("  ABI Version:                       %d\n",
	       buffer[EI_ABIVERSION]);
}

/**
 * type - print ELF type
 * @buffer: the ELF header
 * @needed: endianness (big endian if non-zero)
 */
void type(const unsigned char *buffer, int needed)
{
	if (buffer[EI_DATA] == ELFDATA2MSB)
		needed >>= 8;

	printf("  Type:                              ");

	switch (needed)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", needed);
	}
}

/**
 * entry - print entry point address
 * @buffer: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @needed: endianness (big endian if non-zero)
 */
void entry(const unsigned char *buffer, size_t bit_mode, int needed)
{
	int address_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	if (needed)
	{
		while (address_size && !*(buffer))
			--address_size, ++buffer;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += address_size;

		while (address_size && !*(--buffer))
			--address_size;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(--buffer) & 0xff);
	}

	printf("\n");
}

/**
 * main - copy the content of a file to another one
 * @argc: the argument count
 * @argv: the argument values
 *
 * Return: Always 0
 */
int main(int argc, const char *argv[])
{
	unsigned char buffer[18];
	unsigned int bit_mode;
	int needed;
	int fd;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Can't read from file");
		exit(98);
	}

	file_read(fd, (char *) buffer, 18);

	magic(buffer);
	bit_mode = class(buffer);
	needed = data(buffer);
	version(buffer);
	osabi(buffer);
	abi(buffer);
	type(buffer, needed);

	lseek(fd, 24, SEEK_SET);
	file_read(fd, (char *) buffer, bit_mode / 8);

	entry(buffer, bit_mode, needed);

	elf_close(fd);

	return (0);
}

