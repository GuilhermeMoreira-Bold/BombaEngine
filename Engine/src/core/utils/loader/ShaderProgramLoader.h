#pragma once
#include <GL/glew.h>

#include "ILoader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../../../log/Log.h"

namespace KongLoad {
	class ShaderProgramLoader : public KongLoad::ILoader<unsigned int, std::string&, std::string&>{// Engine\src\core\renderer\programs
		public:
		unsigned int load(std::string& vertexShader, std::string& fragmentShader) override {
			std::string vertexCode;
			std::string fragmentCode;
			std::ifstream vShaderFile;
			std::ifstream fShaderFile;
			unsigned int id = glCreateProgram();

			vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			try {
				vShaderFile.open(vertexShader);
				fShaderFile.open(fragmentShader);
				std::stringstream vShaderStream, fShaderStream;

				vShaderStream << vShaderFile.rdbuf();
				fShaderStream << fShaderFile.rdbuf();

				vShaderFile.close();
				fShaderFile.close();

				vertexCode = vShaderStream.str();
				fragmentCode = fShaderStream.str();
			}
			catch (std::ifstream::failure e) {
				Log::print("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" + std::string(e.what()), Log::ERROR);
				Log::print(vertexShader, Log::INFO);
			}

			const char* vShaderCode = vertexCode.c_str();
			const char* fShaderCode = fragmentCode.c_str();

			//compiling shader

			unsigned int vertex, fragment;

			vertex = compileShader(GL_VERTEX_SHADER, vShaderCode);
			fragment = compileShader(GL_FRAGMENT_SHADER, fShaderCode);
			
			glAttachShader(id, vertex);
			glAttachShader(id, fragment);
			glLinkProgram(id);
			
			getError(GL_LINK_STATUS, id);
	
			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return id;
		}
	private:
		unsigned int compileShader(GLenum shaderType, const char* shaderCode) {
			unsigned int shader;
			shader = glCreateShader(shaderType);
			glShaderSource(shader, 1, &shaderCode,nullptr);
			glCompileShader(shader);
			getError(shaderType, shader);

			return shader;
		}

		void getError(GLenum type,unsigned int shader) {

			char infoLog[512];
			int success;

			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

			if (!success) {
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				Log::print("ERROR::SHADER::COMPILATION::FAILED::" + std::to_string(type) + "\n" + std::string(infoLog), Log::ERROR);
			}
		}
	};
}