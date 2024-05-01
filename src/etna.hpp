#pragma once

#include "window.hpp"
#include "pipeline.hpp"
#include "device.hpp"
#include "swapchain.hpp"
#include "game_object.hpp"

#include <memory>
#include <vector>

namespace etna
{
    class Etna
    {

    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        Etna();
        ~Etna();

        Etna(const Etna &) = delete;
        Etna &operator=(const Etna &) = delete;

        void run();

    private:
        void loadGameObjects();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void freeCommandBuffers();
        void drawFrame();
        void recreateSwapChain();
        void recordCommandBuffer(int imageIndex);
        void renderGameObjects(VkCommandBuffer commandBuffer);

        Window window{WIDTH, HEIGHT, "Etna"};
        Device device{window};
        std::unique_ptr<SwapChain> swapchain;
        std::unique_ptr<Pipeline> pipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::vector<GameObject> gameObjects;
    };
}