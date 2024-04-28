#pragma once
#include "IComponent.h"
#include <memory>
#include "../../log/Log.h"

namespace KongEcs {
	class Mesh{
	private:
		unsigned int vaoID;
		int vertices;
	public:
		Mesh(unsigned int vao, int vertices) : vaoID(vao), vertices(vertices) {};
		unsigned int getVao() {return vaoID;};
		int getVertices() { return vertices; };
	};
}