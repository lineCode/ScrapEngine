#pragma once

#include <vulkan/vulkan.hpp>
#include <stb_image.h>
#include <Engine/Rendering/Buffer/StagingBuffer/BaseStagingBuffer.h>

namespace ScrapEngine
{
	namespace Render
	{
		class ImageStagingBuffer : public BaseStagingBuffer
		{
		public:
			ImageStagingBuffer(const vk::DeviceSize& image_size, stbi_uc* pixels);

			~ImageStagingBuffer() = default;

			static void copy_buffer_to_image(vk::Buffer* buffer, vk::Image* image, const uint32_t& width,
			                                 const uint32_t& height);
			static void copy_buffer_to_image(vk::Buffer* buffer, vk::Image* image, const uint32_t& width,
			                                 const uint32_t& height, vk::BufferImageCopy* region, int regioncount = 1,
			                                 vk::ImageLayout layout = vk::ImageLayout::eTransferDstOptimal);
		};
	}
}
