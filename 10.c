#include <stdio.h>
#include <dirent.h>   // For directory handling
#include <sys/stat.h> // For file information
#include <string.h>
int main()
{
    char dirname[256];
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    long long totalSize = 0;
    char path[512];
    printf("Enter directory path: ");
    scanf("%s", dirname);
    dir = opendir(dirname);
    if (dir == NULL)
    {
        printf("Error: Unable to open directory!\n");
        return 1;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        // Build full path: directory + "/" + filename
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
        // Get file info
        if (stat(path, &fileStat) == 0)
        {
            // Check if it’s a regular file
            if (S_ISREG(fileStat.st_mode))
            {
                totalSize += fileStat.st_size;
                printf("%s : %lld bytes\n", entry->d_name, (long long)fileStat.st_size);
            }
        }
    }
    closedir(dir);
    printf("\nTotal size of all files: %lld bytes\n", totalSize);
    return 0;
}