#pragma once
#include <GL/glew.h>

#include <vector>
#include "../ecs/GameObject.h"
#include "../../log/Log.h"
#include "ShaderProgram.h"
#include <string>

namespace KongGraphics {
	class RenderAPI {
	private:
		static std::vector<KongEcs::GameObject> gameObjects;
		static ShaderProgam* shaderProgram;
	public:
		static void init(KongGraphics::ShaderProgam* shader) { shaderProgram = shader; };
		
		static void update() {
			shaderProgram->use();


			for (auto& object : gameObjects) {
				shaderProgram->setUniformMatrix("model", object.getTransform().getModel());
				//object.getTransform().rotate(50);
				object.update();
			}

			glBindVertexArray(0);
			glUseProgram(0);
		};

		static void addGameObject(KongEcs::GameObject& gameObject) {
			gameObjects.push_back(gameObject);
		}

		static void shutdown() {};
	};
}