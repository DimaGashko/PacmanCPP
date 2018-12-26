#pragma once

#include "GameObject.hpp"

namespace pg {

	class Actor : public GameObject {
	public:
		Actor();

		enum States {Stay, Go}; 

		void update(int frameTime) override;
		void updateAnimation(int frameTime) override;

		void goLeft();
		void goTop();
		void goRight();
		void goBottom();

		~Actor();

	private:
		float m_step;

		bool m_goingLeft = false;
		bool m_goingTop = false;
		bool m_goingRight = false;
		bool m_goingBottom = false;
		
		void go(int frameTime);
	};

}; // namespace pg