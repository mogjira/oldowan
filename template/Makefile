CC = gcc
CFLAGS = -Wall 
LIBS = -lm -lvulkan -lxcb -lxcb-keysyms 

O = build
GLSL = shaders
SPV  = shaders/spv

NAME = fizz


DEPS =  \
    d_display.h  \
    v_video.h    \
    v_def.h      \
    v_memory.h   \
    r_render.h   \
    r_commands.h \
    r_pipeline.h \
    i_input.h    \
    m_math.h     \
    utils.h      \
    def.h        \


OBJS =  \
    $(O)/d_display.o  \
    $(O)/v_video.o    \
    $(O)/v_memory.o   \
    $(O)/r_render.o   \
    $(O)/r_commands.o \
    $(O)/r_pipeline.o \
    $(O)/i_input.o \
    $(O)/m_math.o     \
    $(O)/utils.o      \


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

$(O)/$(NAME): main.c $(OBJS) $(DEPS) shaders
	$(CC) $(CFLAGS) $(OBJS) $< -o $@ $(LIBS)

$(O)/%.o:  %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(SPV)/%-vert.spv: $(GLSL)/%.vert
	glslc $< -o $@

$(SPV)/%-frag.spv: $(GLSL)/%.frag
	glslc $< -o $@
