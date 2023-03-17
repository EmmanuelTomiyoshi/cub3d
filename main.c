#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;
    
    // Open the directory
    dir = opendir("./assets/maps");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    
    // Count the number of files
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            ++count;
        }
    }

    // Close the directory
    if (closedir(dir) != 0) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }
    
    printf("The directory contains %d files.\n", count);
    return 0;
}