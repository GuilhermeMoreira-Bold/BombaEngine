#pragma once


#include <memory>
#include <string>

#include "IComponent.h"
#include "Mesh.h"
#include "../../log/Log.h"

#include <GL/glew.h>


namespace KongEcs {
	class GraphicsComponent :public IComponent {
	private:
		Mesh& mesh;

	public:
		GraphicsComponent(Mesh& mesh) : mesh(mesh) {};

		void update() override {
			glBindVertexArray(mesh.getVao());
			glDrawElements(GL_TRIANGLES, mesh.getVertices(), GL_UNSIGNED_INT, 0);
			//Log::print(std::to_string(mesh.getVertices()), Log::INFO);
		}
		int getVao() {
			return mesh.getVao();
		}
	};
}