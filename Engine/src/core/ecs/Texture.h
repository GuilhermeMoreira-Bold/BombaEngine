#pragma once
#include <memory>
#include "IComponent.h"
namespace KongEcs {
	class Texture {
	private:
		std::shared_ptr<int> textureId;
	public:
		void update() {};
		Texture(int textureId) : textureId(std::make_shared<int>(textureId)) {};

		int getTextureId() {return *textureId;}
	};
}