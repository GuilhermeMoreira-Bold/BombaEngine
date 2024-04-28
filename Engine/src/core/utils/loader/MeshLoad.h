#pragma once
#include <GL/glew.h>

#include "ILoader.h"
#include "../../../log/Log.h"
#include "../EBO.h"
#include "../VAO.h"
#include "../VBO.h"
#include <vector>


namespace KongLoad {
	class MeshLoad : ILoader<unsigned int,std::vector<float>,std::vector<unsigned int>> {
	public:
		unsigned int load(std::vector<float> vertices,std::vector<unsigned int>  indices) override {
			KongUtils::VAO<float> vao;
			KongUtils::VBO<float> vbo(vertices);
			KongUtils::EBO<unsigned int> ebo(indices);
			
			vao.bind();
			glVertexArrayElementBuffer(vao.getVAO(),ebo.getEboId());
			vbo.bind();
			ebo.bind();
			vao.enalbeVertexAttrib(0,3,GL_FLOAT,0,0);
			vao.unbid();

			return vao.getVAO();
		 }
	};
}