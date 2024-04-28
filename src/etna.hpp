#pragma once

#include "window.hpp"
#include "pipeline.hpp"
#include "device.hpp"
#include "swapchain.hpp"
#include "model.hpp"
#include "model.hpp"

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
        void loadModels();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void freeCommandBuffers();
        void drawFrame();
        void recreateSwapChain();
        void recordCommandBuffer(int imageIndex);

        Window window{WIDTH, HEIGHT, "Etna"};
        Device device{window};
        std::unique_ptr<SwapChain> swapchain;
        std::unique_ptr<Pipeline> pipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<Model> model;
    };
}