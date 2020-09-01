#include <assert.h>
#include <stdio.h>
#include <string.h>

#define STR_LEN 512

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s path-to-source path-to-output\n", argv[0]);
        return -1;
    }
    FILE* srcFile = fopen(argv[1], "r");
    assert(srcFile);
    FILE* outFile = fopen(argv[2], "w");
    assert(outFile);

    char buffer[STR_LEN];
    while(fgets(buffer, STR_LEN, srcFile))
    {
        int linesize = strlen(buffer);
        char outBuffer[linesize + 4];
        strcpy(outBuffer + 1, buffer);
        outBuffer[0] = '\"';
        outBuffer[linesize] = '\\';
        outBuffer[1 + linesize] = 'n';
        outBuffer[2 + linesize] = '\"';
        outBuffer[3 + linesize] = '\n';
        outBuffer[4 + linesize] = '\0';
        printf("%s\n", outBuffer);
        assert(fputs(outBuffer, outFile));
    }

    fclose(srcFile);
    fclose(outFile);
    return 0;
}
