#pragma once

#include <SFML/Graphics.hpp>

#include "GObject.hpp"

namespace pg {

	class Wall : public GObject {
	public:
		Wall();

		void updateAnimation(int frameTime) override;
		void updateSpeed(int frameTime) override;
		void setStartAnim() override;
		void interact(pg::GObject *obj) override;

		~Wall();

	private:

	};

}; // namespace pg

