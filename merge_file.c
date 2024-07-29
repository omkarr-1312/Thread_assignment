#include <stdio.h>
#include <stdlib.h>
#include "merge_file.h"

#define NUM_FILES 5

void merge_files(const char *output_filename)
{
	//Open all sorting files for reading
	FILE *sorted_file[NUM_FILES];
	for ( int i = 0; i < NUM_FILES; i++)
	{
		char sort_filename[20];
		snprintf(sort_filename, sizeof(sort_filename), "sorted.%d.txt", i+1);
		sorted_file[i] = fopen(sort_filename,"r");
		if ( NULL == sorted_file[i] )
		{
			perror("Error opening in sort file");
			return ;
		}
	}

	//Open the final output file for writing
	FILE *output_file = fopen(output_filename,"w");
	if ( NULL == output_file )
	{
		perror("Error opening in output file");
		return ;
	}

	FileEntry *entries = (FileEntry *) malloc(NUM_FILES * sizeof(FileEntry));
	if ( NULL == entries )
	{
		perror("Error in allocating memory for struct");
		return ;
	}

	//Initialize the entries with the first integer from each file
	for ( int i = 0; i < NUM_FILES; i++)
	{
		entries[i].valid = fscanf(sorted_file[i],"%d",&entries[i].value) == 1;
	}

	while(1)
	{
		//Find the index of the smallest current integer
		int min_index = -1;
		for ( int i = 0; i < NUM_FILES; i++ )
		{
			if ( entries[i].valid )
			{
				if ( min_index == -1 || entries[i].value < entries[min_index].value )
				{
					min_index = i;
				}
			}
		}

		if ( min_index == -1 )
		{
			break;
		}

		//Write the smallest integer to the final output file
		fprintf(output_file, "%d\n", entries[min_index].value);

		//Read the next integer from the file that had the smallest integer
		entries[min_index].valid = fscanf(sorted_file[min_index],"%d",&entries[min_index].value) == 1;
	}

	//close all files
	for ( int i = 0; i < NUM_FILES; i++ )
	{
		fclose(sorted_file[i]);
	}
	fclose(output_file);

	//Free all allocated memory
	free(entries);

}

