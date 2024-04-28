#pragma once
#include <vector>
#include <fstream>
#include "ILoader.h"
#include <string>
#include "../../ecs/GameObject.h"
#include "../../../log/Log.h"
#include <tuple>
#include <sstream>

namespace KongLoad {
	class LoadObject : ILoader<std::tuple<std::vector<float>, std::vector<unsigned int>>, std::string> {
	public:
		std::tuple<std::vector<float>, std::vector<unsigned int>> load(std::string path) override
		{
			std::ifstream model(path);

			if (!model) {
				Log::print("Error to read the 3D model arquive", Log::ERROR);
			}
			
			std::string line;
			while (std::getline(model, line)) {
				if (line[0] == 'v' && line[1] == ' ') {
					std::string number;
					for (int numberIndice = 2; numberIndice <= line.size();numberIndice++) {
						if(line[numberIndice] == ' ' || numberIndice == line.size()) {
							float f = toFloat(number);
							vertices.push_back(f);
							number = "";
							continue;
						}
						number += line[numberIndice];
					}
				}
				if (line[0] == 'f') {
					std::string number;
					for (int numberIndice = 2; numberIndice <= line.size(); numberIndice++) {
						if (line[numberIndice] == '/' || numberIndice == line.size()) {
							unsigned int i = toUnsigned(number);
							indices.push_back(i);
							number = "";
							continue;
						}
						if (line[numberIndice] != ' ') {
							number += line[numberIndice];
						}
					}
					
				}
			}
			std::tuple<std::vector<float>, std::vector<unsigned>> value(vertices, indices);
			return value;
		};


	private:
		std::vector<float> vertices;
		std::vector<unsigned int> indices;
		float toFloat(const std::string& str) {
			std::istringstream iss(str);
			float number;
			iss >> number;
			return number;
		}
		
		unsigned int toUnsigned(const std::string& str) {
			std::istringstream iss(str);
			unsigned int number;
			iss >> number;
			return number;
		}

		//TODO MELHORAR ISSO AQUI, GASTANDO MUITA MEMÓRIA INEFICIENTE
		std::string split(const std::string& line, char delimiter) {
			std::string result;
			while (true) {
				int position = 0;
				if (line[position] != delimiter) {
					result += line[position];
					position++;
					continue;
				}
				break;
			}
			return result;
		}
	};
}