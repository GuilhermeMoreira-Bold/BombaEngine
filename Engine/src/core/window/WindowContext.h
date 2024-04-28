#pragma once

namespace KongWindow{
	struct WindowContext {
		enum Context {
			OPEN_GL_WINDOW,
			VULKAN_WINDOW,
			WINDOWS_WINDOW,
		};
	};
}