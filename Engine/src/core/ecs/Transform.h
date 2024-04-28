#pragma once
#include "IComponent.h"
#include "../../../Includes/glm/glm.hpp"
#include "../../../Includes/glm/gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"

namespace KongEcs {
	class Transform {
	private:
		glm::mat4 model;
	public:
		Transform() {
			model = glm::mat4(1.0f);
			rotate(45);
		}

		void rotate(float degrees) {
			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(degrees), glm::vec3(0.5, 1.0, 1.0));
		}

		void scale(float scale) {
			model = glm::scale(model, glm::vec3(scale, scale, scale));
		}

		void incrisePosition(glm::vec3 position) {
			Log::print("Dentro", Log::INFO);
			model = glm::translate(model, position);
		}

		glm::mat4 getModel() const {
			return model;
		}


	};
}