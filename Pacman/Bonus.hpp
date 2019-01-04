#pragma once

#include <SFML/Graphics.hpp>

#include "GObject.hpp"

namespace pg {

	class Bonus : public GObject {
	public:

		Bonus();

		void updateAnimation(int frameTime) override;
		void updateSpeed(int frameTime) override;
		void setStartAnim() override;
		void interact(pg::GObject *obj);

		virtual void use(pg::GObject *obj) = 0;
		virtual bool canItUseTheBonus(pg::GObject *obj) = 0;

		~Bonus();

	private:
		
	};

}