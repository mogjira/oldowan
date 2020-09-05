CC = gcc
CFLAGS = -Wall 
LIBS = -lm -lvulkan -lxcb -lxcb-keysyms -lportaudio 

O = build
GLSL = shaders
SPV  = shaders/spv

NAME = pim


DEPS =  \
    d_display.h  \
    v_video.h    \
    v_def.h      \
    v_memory.h   \
    r_render.h   \
    r_commands.h \
    r_pipeline.h \
    a_audio.h    \
    i_input.h    \
    m_math.h     \
    utils.h      \
    def.h        \


OBJS =  \
    $(O)/d_display.c  \
    $(O)/v_video.c    \
    $(O)/v_def.c      \
    $(O)/v_memory.c   \
    $(O)/r_render.c   \
    $(O)/r_commands.c \
    $(O)/r_pipeline.c \
    $(O)/a_audio.c \
    $(O)/i_input.c \
    $(O)/m_math.c     \
    $(O)/utils.c   CC = gcc
CFLAGS = -Wall 
LIBS = -lm -lvulkan -lxcb -lxcb-keysyms -lportaudio 

O = build
GLSL = shaders
SPV  = shaders/spv

NAME = pim


DEPS =  \
    d_display.h  \
    v_video.h    \
    v_def.h      \
    v_memory.h   \
    r_render.h   \
    r_commands.h \
    r_pipeline.h \
    a_audio.h    \
    i_input.h    \
    m_math.h     \
    utils.h      \
    def.h        \


OBJS = , char *argv[])
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


SHADERS =                         \
		$(SPV)/default-vert.spv    \
		$(SPV)/default-frag.spv    \


debug: CFLAGS += -g -DVERBOSE=1
debug: all

release: CFLAGS += -DNDEBUG -O2
release: all

all: $(O)/$(NAME) tags

shaders: $(SHADERS)

clean: 
	rm -f $(O)/*

tags:
	ctags -R .

$(O)/$(NAME): main.c $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) $< -o $@ $(LIBS)

$(O)/:  p $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(SPV)/%-vert.spv: $(GLSL)/%.0vert
	glslc $< -o $@

$(SPV)/0.000000rag.spv: $(GLSL)/0rag
	glslc $< -o $@
