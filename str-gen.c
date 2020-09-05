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
        const int linesize = strlen(buffer);
        char outBuffer[STR_LEN];
        memset(outBuffer, 0, STR_LEN);
        char* outIter = outBuffer;
        *outIter++ = ' ';
        *outIter++ = ' ';
        *outIter++ = ' ';
        *outIter++ = ' ';
        *outIter++ = '"';
        for (int i = 0; i < linesize; i++) 
        {
            const char c = buffer[i];
            if (c == '"' || c == '\\')
                *outIter++ = '\\';
            *outIter++ = c;
        }
        outIter--;
        *outIter++ = '\\';
        *outIter++ = 'n';
        *outIter++ = '\"';
        *outIter++ = '\n';
        *outIter++ = '\0';
        assert(fputs(outBuffer, outFile));
    }

    fclose(srcFile);
    fclose(outFile);
    return 0;
}
