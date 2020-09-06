#include "r_commands.h"
#include "r_render.h"
#include "v_video.h"
#include "r_pipeline.h"
#include "v_memory.h"
#include "def.h"
#include <assert.h>
#include <vulkan/vulkan_core.h>

static V_block* vertexBlock;
static Vertex*  vertices;

static void createTriangle(void)
{
    // Create vertex buffer

    vertexBlock = v_RequestBlock(sizeof(Vertex) * 3);
    vertices = (Vertex*)vertexBlock->address;

    // make triangle

    vertices[0].pos.x =  0.0;
    vertices[0].pos.y = -0.5;

    vertices[1].pos.x = -0.5;
    vertices[1].pos.y =  0.5;

    vertices[2].pos.x =  0.5;
    vertices[2].pos.y =  0.5;

    // colors of hydrogen atom spectral lines
    // bahmer series for n = 3, 4, 5
    vertices[0].color.x =  1.0;
    vertices[0].color.y =  0.0;
    vertices[0].color.z =  0.0;

    vertices[1].color.x =  0.0;
    vertices[1].color.y =  0.93725;
    vertices[1].color.z =  1.0;

    vertices[2].color.x =  0.15686;
    vertices[2].color.y =  0.0;
    vertices[2].color.z =  1.0;

}

void r_InitRenderCommands(void)
{
    createTriangle();

    for (int i = 0; i < FRAME_COUNT; i++) 
    {
        r_RequestFrame();
        
        r_UpdateRenderCommands();

        r_PresentFrame();
    }

}

void r_UpdateRenderCommands(void)
{
    VkResult r;
    Frame* frame = &frames[curFrameIndex];
    vkResetCommandPool(device, frame->commandPool, 0);
    VkCommandBufferBeginInfo cbbi = {.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
    r = vkBeginCommandBuffer(frame->commandBuffer, &cbbi);

    VkClearValue clearValue = {0.002f, 0.003f, 0.009f, 1.0f};

    const VkRenderPassBeginInfo rpassInfoFirst = {
        .sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
        .clearValueCount = 1,
        .pClearValues = &clearValue,
        .renderArea = {{0, 0}, {WINDOW_WIDTH, WINDOW_HEIGHT}},
        .renderPass =  frame->renderPass,
        .framebuffer = frame->frameBuffer 
    };

    vkCmdBeginRenderPass(frame->commandBuffer, &rpassInfoFirst, VK_SUBPASS_CONTENTS_INLINE);

    vkCmdBindPipeline(frame->commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipelines[R_OBJ_PIPELINE]);

    vkCmdBindVertexBuffers(
            frame->commandBuffer, 0, 1, vertexBlock->vBuffer, &vertexBlock->vOffset);

    vkCmdDraw(frame->commandBuffer, 3, 1, 0, 0);

    vkCmdEndRenderPass(frame->commandBuffer);

    r = vkEndCommandBuffer(frame->commandBuffer);
    assert ( VK_SUCCESS == r );
}
