#pragma once

#include <GL/glew.h>
#include <vector>

namespace KongUtils {
	template<typename T>
	class EBO {
	public:
		EBO(std::vector<T>& data) {
			glGenBuffers(1, &eboId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(T), data.data(), GL_STATIC_DRAW);
		}
		void bind() {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
		}

		void unbind() {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		unsigned int getEboId() { return eboId; };
	private:
		unsigned int eboId;
	};
}