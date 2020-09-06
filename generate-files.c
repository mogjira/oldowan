#include <stdlib.h>

int main(int argc, char *argv[])
{
    system("gcc str-gen.c -o bin/strgen");
    system("./bin/strgen template/def.h gen/def.txt");
    system("./bin/strgen template/v_def.h gen/v_def.txt");
    system("./bin/strgen template/v_video.h gen/v_video_h.txt");
    system("./bin/strgen template/v_video.c gen/v_video_c.txt");
    system("./bin/strgen template/v_memory.c gen/v_memory_c.txt");
    system("./bin/strgen template/v_memory.h gen/v_memory_h.txt");
    system("./bin/strgen template/r_render.c gen/r_render_c.txt");
    system("./bin/strgen template/r_render.h gen/r_render_h.txt");
    system("./bin/strgen template/r_pipeline.c gen/r_pipeline_c.txt");
    system("./bin/strgen template/r_pipeline.h gen/r_pipeline_h.txt");
    system("./bin/strgen template/r_commands.c gen/r_commands_c.txt");
    system("./bin/strgen template/r_commands.h gen/r_commands_h.txt");
    system("./bin/strgen template/d_display.c gen/d_display_c.txt");
    system("./bin/strgen template/d_display.h gen/d_display_h.txt");
    system("./bin/strgen template/i_input.c gen/i_input_c.txt");
    system("./bin/strgen template/i_input.h gen/i_input_h.txt");
    system("./bin/strgen template/m_math.h gen/m_math_h.txt");
    system("./bin/strgen template/m_math.c gen/m_math_c.txt");
    system("./bin/strgen template/utils.c gen/utils_c.txt");
    system("./bin/strgen template/utils.h gen/utils_h.txt");
    system("./bin/strgen template/Makefile gen/makefile.txt");
    system("./bin/strgen template/main.c gen/main.txt");
    system("./bin/strgen template/shaders/default.frag gen/default_frag.txt");
    system("./bin/strgen template/shaders/default.vert gen/default_vert.txt");
    return 0;
}
