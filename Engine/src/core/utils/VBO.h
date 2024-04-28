#pragma once
#include <GL/glew.h>
#include <vector>

namespace KongUtils {
	template<typename T>
	class VBO {
	public:
		VBO(std::vector<T>& data) {
			glGenBuffers(1, &vboId);
			glBindBuffer(GL_ARRAY_BUFFER, vboId);
			glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), data.data(), GL_STATIC_DRAW);
		}
		void bind() {
			glBindBuffer(GL_ARRAY_BUFFER, vboId);
		}

		void unbind() {
			glBindBuffer(GL_ARRAY_BUFFER,0);
		}

		unsigned int getVboId() { return vboId; };
	private:
		unsigned int vboId;
	};
}