#include "m_math.h"
#include "utils.h"
#include "def.h"
#include "d_display.h"
#include "v_video.h"
#include "r_render.h"
#include "a_audio.h"
#include "i_input.h"
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>

jmp_buf exit_game;

#define NS_TARGET 16666666 // 1 / 60 seconds
//#define NS_TARGET 500000000
#define NS_PER_S  1000000000

int main(int argc, char *argv[])
{
    a_Init();
    printf("Audio initialized\n");
    d_Init();
    printf("Display initialized\n");
    v_Init();
    printf("Video initialized\n");
    r_Init();
    printf("Renderer initialized\n");
    i_Init();
    printf("Input initialized\n");

    struct timespec startTime = {0, 0};
    struct timespec endTime = {0, 0};
    struct timespec diffTime = {0, 0};
    struct timespec remTime = {0, 0}; // this is just if we get signal interupted

    uint64_t frameCount   = 0;
    uint64_t nsTotal      = 0;
    unsigned long nsDelta = 0;
    uint32_t shortestFrame = NS_PER_S;
    uint32_t longestFrame = 0;

    while( 1 ) 
    {
        if (setjmp(exit_game)) break;

        clock_gettime(CLOCK_MONOTONIC, &startTime);


        clock_gettime(CLOCK_MONOTONIC, &endTime);

        nsDelta  = (endTime.tv_sec * NS_PER_S + endTime.tv_nsec) - (startTime.tv_sec * NS_PER_S + startTime.tv_nsec);
        nsTotal += nsDelta;

        if (nsDelta > longestFrame) longestFrame = nsDelta;
        if (nsDelta < shortestFrame) shortestFrame = nsDelta;

        diffTime.tv_nsec = NS_TARGET - nsDelta;

        assert ( NS_TARGET > nsDelta );

        nanosleep(&diffTime, &remTime);

        frameCount++;
    }



    i_CleanUp();
    r_CleanUp();
    v_CleanUp();
    d_CleanUp();
    a_CleanUp();
    return 0;
}
