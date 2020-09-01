#include <stdio.h>
#include <stdbool.h>

#define STR_LEN 16

typedef struct 
{
    bool audio;
    bool video;
    bool input;
    bool render;
} Parms;

Parms parms;

void buildAudioFiles()
{
    printf("Building Audio files...\n");
    const char* headerString = "";
}

void buildVideoFiles()
{
    printf("Building Video files...\n");
}

void buildRenderFiles()
{
    printf("Building Render files...\n");
}

void buildInputFiles()
{
    printf("Building Input files...\n");
}

int main(int argc, char *argv[])
{
    printf("The stone age has begun!\nWhich modules would you like to create?\n");
    printf("a: audio \tv: video\tr: render \ti: input \tnothing: all\n");
    char input[STR_LEN];
    fgets(input, STR_LEN, stdin);
    for (int i = 0; i < STR_LEN; i++) 
    {
        switch (input[i]) 
        {
            case 'a': parms.audio  = true; break;
            case 'v': parms.video  = true; break;
            case 'r': parms.render = true; break;
            case 'i': parms.input  = true; break;
            default: parms.input = parms.render = parms.audio = parms.video = true;
        }
    }
    if (parms.audio)
        buildAudioFiles();
    if (parms.video)
        buildVideoFiles();
    if (parms.render) 
        buildRenderFiles();
    if (parms.input)
        buildInputFiles();
    return 0;
}
