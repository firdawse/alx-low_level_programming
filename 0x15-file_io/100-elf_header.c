#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints an error message to stderr and exits with code 98.
 * @message: The error message to be printed.
 */
void print_error(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(98);
}

/**
 * display_elf_header_info - Displays information about the ELF header.
 * @elf_header: A pointer to the ELF header structure to be displayed.
 */
void display_elf_header_info(Elf64_Ehdr *elf_header)
{
    int i; 

    printf("ELF Header:\n");

    printf("  Magic: ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", elf_header->e_ident[i]);
    printf("\n");

    
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
    const char *filename; 
    int file_descriptor;
    Elf64_Ehdr elf_header;

    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
    }

    filename = argv[1];
    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
    {
        print_error("Error opening file");
    }

    if (read(file_descriptor, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
    {
        print_error("Error reading ELF header");
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3)
    {
        print_error("Not an ELF file");
    }

    display_elf_header_info(&elf_header);

    close(file_descriptor);
    return 0;
}

