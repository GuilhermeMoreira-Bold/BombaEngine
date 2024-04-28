#pragma once
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <unordered_map>
#include <string>
#include "../../../includes/glm/glm.hpp"
#include "../../../includes/glm/gtc/type_ptr.hpp"

namespace KongGraphics {
	class ShaderProgam {
	private:
		mutable std::unordered_map<std::string, unsigned int> uniforms;
		std::shared_ptr<unsigned int> id;
		unsigned int getUniform(const std::string& uniformName) const {
			if (uniforms.find(uniformName) != uniforms.end()) {
				return uniforms[uniformName];
			}
			unsigned int location = glGetUniformLocation(*id, uniformName.c_str());

			return location;
		}
	public:
		 ShaderProgam(int shaderId) :id(std::make_shared<unsigned int>(shaderId)) {};
		 void use() { glUseProgram(*id); };

		 void setUniformMatrix(std::string uniformName, glm::mat4 values){
			 glUniformMatrix4fv(getUniform(uniformName), 1, GL_FALSE,glm::value_ptr(values));
		 }
	};
};