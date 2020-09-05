#include <stdlib.h>

int main(int argc, char *argv[])
{
    system("gcc str-gen.c -o bin/strgen");
    system("./bin/strgen as/def.h gen/def.txt");
    system("./bin/strgen as/v_def.h gen/v_def.txt");
    system("./bin/strgen as/v_video.h gen/v_video_h.txt");
    system("./bin/strgen as/v_video.c gen/v_video_c.txt");
    system("./bin/strgen as/v_memory.c gen/v_memory_c.txt");
    system("./bin/strgen as/v_memory.h gen/v_memory_h.txt");
    system("./bin/strgen as/r_render.c gen/r_render_c.txt");
    system("./bin/strgen as/r_render.h gen/r_render_h.txt");
    system("./bin/strgen as/r_pipeline.c gen/r_pipeline_c.txt");
    system("./bin/strgen as/r_pipeline.h gen/r_pipeline_h.txt");
    system("./bin/strgen as/r_commands.c gen/r_commands_c.txt");
    system("./bin/strgen as/r_commands.h gen/r_commands_h.txt");
    system("./bin/strgen as/d_display.c gen/d_display_c.txt");
    system("./bin/strgen as/d_display.h gen/d_display_h.txt");
    system("./bin/strgen as/i_input.c gen/i_input_c.txt");
    system("./bin/strgen as/i_input.h gen/i_input_h.txt");
    system("./bin/strgen as/m_math.h gen/m_math_h.txt");
    system("./bin/strgen as/m_math.c gen/m_math_c.txt");
    system("./bin/strgen as/utils.c gen/utils_c.txt");
    system("./bin/strgen as/utils.h gen/utils_h.txt");
    system("./bin/strgen as/Makefile gen/makefile.txt");
    system("./bin/strgen as/main gen/main.txt");
    return 0;
}
