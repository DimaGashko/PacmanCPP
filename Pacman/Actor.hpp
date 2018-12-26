#pragma once

#include "GameObject.hpp"

namespace pg {

	class Actor : public GameObject {
	public:
		Actor();

		void update(int frameTime) override;
		void updateAnimation(int frameTime) override;
		void setStartAnim() override;
		void interact(pg::GameObject *obj) override;

		void goLeft();
		void goTop();
		void goRight();
		void goBottom();

		~Actor();

	protected:
		float m_step;

		bool m_goingLeft = false;
		bool m_goingTop = false;
		bool m_goingRight = false;
		bool m_goingBottom = false;
		
		virtual void go(int frameTime);

	private:

	};

}; // namespace pg