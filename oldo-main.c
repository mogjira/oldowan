#include <stdio.h>
#include <assert.h>
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
    const char* headerString = 
    "/*\n"
    "v_video.c\n"
    " */\n"
    "#ifndef V_VIDEO_H\n"
    "#define V_VIDEO_H\n"
    "\n"
    "#include \"v_def.h\"\n"
    "\n"
    "extern VkDevice         device;\n"
    "extern VkPhysicalDevice physicalDevice;\n"
    "extern uint32_t graphicsQueueFamilyIndex;\n"
    "extern VkQueue  graphicsQueues[G_QUEUE_COUNT];\n"
    "extern VkQueue  presentQueue;\n"
    "\n"
    "extern VkImage        swapchainImages[FRAME_COUNT];\n"
    "extern const VkFormat swapFormat;\n"
    "extern VkSwapchainKHR   swapchain;\n"
    "extern VkSemaphore    imageAcquiredSemaphores[FRAME_COUNT];\n"
    "extern uint64_t       frameCounter;\n"
    "\n"
    "void v_Init(void);\n"
    "void v_AcquireSwapImage(uint32_t* pImageIndex);\n"
    "void v_CleanUp(void);\n"
    "\n"
    "#endif /* end of include guard: V_VIDEO_H */\n";
    FILE* outFile = fopen("v_video.h", "w");
    assert(outFile);
    fputs(headerString, outFile);
    fclose(outFile);
    printf("Wrote video header at %s\n", "v_video.h");
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
