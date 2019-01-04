#pragma once

#include "GObject.hpp"

namespace pg {

	class Actor : public GObject {
	public:
		Actor();

		void updateSpeed(int frameTime) override;
		void updateAnimation(int frameTime) override;
		void setStartAnim() override;
		void interact(pg::GObject *obj) override;

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

	private:

	};

}; // namespace pg