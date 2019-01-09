#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();

		// ���������� ���� �� ���� � ����
		// ���� ���� ����� �� ����������
		// �� ������� ����������� ����� get
		sf::Sound get(std::string url);

		// ��������� ���� � SoundManager
		bool add(std::string url);

		~SoundManager();

	private:

		// unordered_map ����������� ������
		// (�� static, ��� ��� � ���� ������ ��� ������ 
		// ����������� �������� ������� ��� �����, � ��� 
		// � ���� ����� ����� �������������� � ������ �����������)
		std::unordered_map<std::string, sf::SoundBuffer*> m_soundBuffers;


	};

}; // namespace pg
