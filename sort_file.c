#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "sort_file.h"

#define BUFF_SIZE 10000000

int compare (const void *a, const void *b)
{
	return ( *(int *)a - *(int *)b );
}

void *sort_file(void *arg) 
{
	char *filename = (char *)arg;
	char output_filename[20];
	sprintf(output_filename, "sorted.%s", filename + 9);  // Filename example: "shuffled.1.txt" -> "sorted.1.txt"
	
	FILE *input_file = fopen(filename, "r");
	if (NULL == input_file) 
	{
		perror("Error opening input file");
		pthread_exit(NULL);
       	}
	
	int *buff_data = malloc(BUFF_SIZE * sizeof(int));
	if (NULL == buff_data) 
	{
		perror("Error allocating memory");
		fclose(input_file);
		pthread_exit(NULL);
	}

	//Read the data from input_file and stores in buff_data
	for (size_t i = 0; i < BUFF_SIZE; i++) 
	{
		fscanf(input_file, "%d", &buff_data[i]);
	}
	fclose(input_file);
	
	// Sort the data in the buff_data using qsort()
	qsort(buff_data, BUFF_SIZE, sizeof(int), compare);
	
	FILE *output_file = fopen(output_filename, "w");
	if (NULL == output_file) 
	{
		perror("Error opening output file");
		free(buff_data);
		pthread_exit(NULL);
	}

	//Write the sorted data from the buff_data
	for (size_t i = 0; i < BUFF_SIZE; i++)
       	{
		fprintf(output_file, "%d\n", buff_data[i]);
	}
	
	fclose(output_file);
	free(buff_data);
	pthread_exit(NULL);
}

		
