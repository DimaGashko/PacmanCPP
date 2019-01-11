#pragma once

namespace pg {

	template <class T>
	class Singleton {
	public:

		static T& getInstance();
		static void destroyInstance();

	private:
		Singleton() {};
		~Singleton() {};

		static T* s_instance;
	};

}; // namespace pg
