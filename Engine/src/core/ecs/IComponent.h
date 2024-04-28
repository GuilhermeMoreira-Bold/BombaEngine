#pragma once
namespace KongEcs {
	class IComponent {
	public:
		virtual void update() = 0;
	};
};