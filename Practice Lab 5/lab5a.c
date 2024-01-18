/*
*
* Author: Prof. Neerja Mhaskar
* Course: Operating Systems Comp Sci/SFWRWENG 3SH3

*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Define the needed macros
#define BUFFER_SIZE 10
#define OFFSET_MASK 4095
#define PAGES 8
#define OFFSET_BITS 12
#define PAGE_SIZE 20

int main(int argc, char *argv[])
{
	// declare variables and declare and initialize the page table.
	int logical_address;
	int page_number;
	int page_offset;
	int page_table[PAGES] = {6, 4, 3, 7, 0, 1, 2, 5};
	int frame_number;
	int physical_address;

	/*Declare a file pointer fptr. fopen initializes an object of type file.
	 This is stored in fptr. The mode 'r' indicates that the file is for
	read only purpose.*/
	FILE *fptr = fopen("labaddr.txt", "r");
	char buff[BUFFER_SIZE];
	while (fgets(buff, BUFFER_SIZE, fptr) != NULL)
	{
		buff[strcspn(buff, "\n")] = 0;
		logical_address = atoi(buff);
		page_number = logical_address >> OFFSET_BITS;
		page_offset = logical_address & OFFSET_MASK;
		frame_number = page_table[page_number];
		physical_address = (frame_number << OFFSET_BITS) | page_offset;
		printf("Virtual addr is %s: Page# = %d & Offset = %d. Physical address = %d \n", buff, page_number, page_offset, physical_address);
	}
	fclose(fptr);

	return 0;
}
