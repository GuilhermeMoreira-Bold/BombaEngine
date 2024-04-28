#pragma once
#include <iterator>
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <string>
#include <memory>
#include <tuple>

#include "LoadObject.h"


#include "ShaderProgramLoader.h"
#include "MeshLoad.h"
#include "../../ecs/Mesh.h"

#include "../../renderer/ShaderProgram.h"
#include "../../ecs/GraphicsComponent.h"


namespace KongLoad {
	class LoadAPI {
	private:
	public:
		static KongGraphics::ShaderProgam* loadShader(std::string vertexPath, std::string fragmentPath) {
			ShaderProgramLoader load;
			std::shared_ptr<std::string> vPath = std::make_shared<std::string>(std::filesystem::current_path().parent_path().generic_string() + "/Engine/src/core/renderer/programs/" + vertexPath);
			std::shared_ptr<std::string> fPath = std::make_shared<std::string>(std::filesystem::current_path().parent_path().generic_string() + "/Engine/src/core/renderer/programs/" + fragmentPath);

			return new KongGraphics::ShaderProgam(load.load(*vPath, *fPath));
		};

		static KongEcs::Mesh* looadMesh(std::string objectPath){
			LoadObject load;
			auto values = load.load(std::filesystem::current_path().parent_path().generic_string() + "/Engine/src/3DModels/" + objectPath + ".obj");
			return loadMesh(std::get<0>(values), std::get<1>(values));
		}

		static KongEcs::Mesh* loadMesh(std::vector<float> vertices, std::vector<unsigned int>  indices) {
			MeshLoad meshLoader;

			//Log::print("Vertices size:" + std::to_string(vertices.size()) + "\nIndices size:" + std::to_string(indices.size()), Log::INFO);
			return new KongEcs::Mesh(meshLoader.load(vertices, indices), indices.size());
		};

		static KongEcs::GraphicsComponent* loadGraphic(KongEcs::Mesh* mesh) {
			KongEcs::GraphicsComponent* graphic = new KongEcs::GraphicsComponent(*mesh);
			return graphic;
		}


	};
}