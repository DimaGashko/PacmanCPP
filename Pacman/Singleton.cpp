#include "Singleton.hpp"

namespace pg {

	template<class T>
	inline T& Singleton<T>::getInstance() {
		if (s_instance) {
			s_instance = new T();
		}

		return *s_instance;
	}

	template<class T>
	inline void Singleton<T>::destroyInstance() {

		if (s_instance) {
			delete s_instance;
		}

	}

	template<class T>
	T* Singleton<T>::s_instance = nullptr;

}; // namespace pg
