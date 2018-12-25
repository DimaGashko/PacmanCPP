#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace pg {

	class Actor : public GameObject {
	public:
		Actor();
		~Actor();

	protected:

		void _initProperties() override;

	private:
		
	};

};