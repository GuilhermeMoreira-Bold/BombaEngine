#pragma once

#include<vector>
#include <memory>
#include "IComponent.h"
#include "GraphicsComponent.h"
#include "Transform.h"

namespace KongEcs {
	class GameObject {
	private: 
		std::vector<IComponent*> components;
		KongEcs::Transform transform;
	public:

		void update() {
			for (auto& it : components) {
				it->update();
			}
		};

		void addComponent(IComponent* component) {
			components.push_back(component);
		};
		
		KongEcs::Transform& getTransform() {
			return transform;
		}
	};
}