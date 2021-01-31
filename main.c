#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage: ./main input output key");
        return 1;
    }
    
    char *key = argv[3];
    
    FILE *fp = fopen(argv[1], "r");
    
    if (fp == NULL)
    {
        perror("Could not open the input file");
        return 1;
    }
    
    FILE *fpw = fopen(argv[2], "w");
    
    if (fp == NULL)
    {
        perror("Could not open/create the output file");
        return 1;
    }
    
    size_t keylen = strlen(key);
    char c;
    for (unsigned int i = 0; 1; i++)
    {
        if (fread(&c, sizeof(char), 1, fp) != 1)
        {
            break;
        }
        c = c ^ key[i % keylen];
        fwrite(&c, sizeof(char), 1, fpw);
    }
    
    fclose(fp);
    fclose(fpw);
    
    return 0;
}
