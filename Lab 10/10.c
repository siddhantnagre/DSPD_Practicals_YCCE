#include <stdio.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceName[50], destName[50];
    char ch;
    
    printf("Enter the source file name: ");
    scanf("%s", sourceName);

    printf("Enter the destination file name: ");
    scanf("%s", destName);

    // Open source file in read mode
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file %s\n", sourceName);
        return 1;
    }

    // Open destination file in write mode
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Cannot create destination file %s\n", destName);
        fclose(sourceFile);
        return 1;
    }

    // Copy contents from source to destination
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("\nFile copied successfully from %s to %s\n", sourceName, destName);

    // Close files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
