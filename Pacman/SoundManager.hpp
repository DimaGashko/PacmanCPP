#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();

		// ���������� Sound�Source �� ���� � ����
		// ���� ���� ����� �� ����������
		// �� ������� ����������� ����� get
		sf::SoundSource* get(std::string url);

		// ��������� ���� � SoundManager
		bool add(std::string url);

		~SoundManager();

	private:

		// unordered_map ����������� ������ (��� �� �������� �����)
		// (�� static, ��� ��� � ���� ������ ��� ������ 
		// ����������� �������� ������� ��� �����, � ��� 
		// � ���� ����� ����� �������������� � ������ �����������)
		std::unordered_map<std::string, sf::Sound*> m_sounds;


	};

}; // namespace pg
