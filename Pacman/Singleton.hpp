#pragma once

namespace pg {

	template <class T>
	class Singleton {
	public:

		static T* getInstance() {
			if (!s_instance) {
				s_instance = new T();
			}

			return s_instance;
		}

		static void destroyInstance() {

			if (s_instance) {
				delete s_instance;
			}

		}


	private:
		Singleton() {};
		~Singleton() {};

		static T* s_instance;
	};

	template<class T>
	T* Singleton<T>::s_instance = nullptr;


}; // namespace pg
