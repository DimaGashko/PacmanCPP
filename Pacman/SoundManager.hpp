#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();

		enum Type {Sound, Music};

		// ���������� Sound�Source �� ���� � ����
		// ���� ���� ����� �� ����������
		// �� ������� ����������� ����� get
		sf::SoundSource* get(std::string url);

		// ��������� ���� � Sound�Manager
		bool add(std::string url, Type type = Type::Sound);

		~SoundManager();

	private:
		static std::unordered_map<std::string, sf::SoundSource*> s_sounds;


	};

}; // namespace pg
