#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace pg {

	class Bonus : public GameObject {
	public:
		Bonus();
		~Bonus();

	protected: 
		void _initProperties() override;

	private:
		
	};

}