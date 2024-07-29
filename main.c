#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include "sort_file.h"
#include "merge_file.h"

#define NUM_FILES 5


int main() {
    pthread_t threads[NUM_FILES];
    char filenames[NUM_FILES][20];

    // Prepare filenames and create threads for sorting
    for (int i = 0; i < NUM_FILES; i++) {
        snprintf(filenames[i], sizeof(filenames[i]), "shuffled.%d.txt", i + 1);
        pthread_create(&threads[i], NULL, sort_file, (void *)filenames[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_FILES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge the sorted files into a single output file
    merge_files("sorted.full.txt");

    return 0;
}
