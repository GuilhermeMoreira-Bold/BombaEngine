#pragma once
#include <vector>
#include <GL/glew.h>

namespace KongUtils {
	template <typename T>
	class VAO {
	public:
		VAO() 
		{
			glGenVertexArrays(1, &vaoid);
			bind();
		};

		void enalbeVertexAttrib(int index, int size, GLenum type, bool normalized,const void* pointer) {
			bind();
				glVertexAttribPointer(index, size, type, normalized, sizeof(T) * size,pointer);
				glEnableVertexAttribArray(0);
			unbid();
		}

		void bind() 
		{
			glBindVertexArray(vaoid);
		}

		void unbid()
		{
			glBindVertexArray(0);
		}

		int getVAO() { return vaoid; };
	private:
		unsigned int vaoid;
	};
}