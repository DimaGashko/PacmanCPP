#pragma once

#include "GameObject.hpp"

namespace pg {

	class Actor : public GameObject {
	public:
		Actor();

		void goLeft();
		void goRight();
		void goTop();
		void goBottom();

		~Actor();

	private:
		bool m_goingLeft = false;
		bool m_goingRight = false;
		bool m_goingTop = false;
		bool m_goingBottom = false;
		
	};

}; // namespace pg