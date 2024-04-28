#pragma once
namespace KongLoad {
	template <typename T,typename ...Args>
	class ILoader {
		virtual T load(Args ...) = 0;
	};
};