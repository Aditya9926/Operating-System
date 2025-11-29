#include <stdio.h>
int main()
{
    FILE *file;
    char ch;
    // Open the file in read mode
    file = fopen("sample.txt", "r");
    // Check if file exists
    if (file == NULL)
    {
        printf("Error: Cannot open file!\n");
        return 1;
    }
    printf("File contents:\n\n");
    // Read and print file contents character by character
    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }
    // Close the file
    fclose(file);
    return 0;
}