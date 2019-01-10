#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();

		// ���������� SoundBuffer �� ���� � ����
		// ���� ���� ����� �� ����������
		// �� ������� ����������� ����� addBuffer
		sf::SoundBuffer* getBuffer(std::string url);

		// ��������� SoundBuffer � SoundManager
		bool addBuffer(std::string url);

		~SoundManager();

	private:

		// unordered_map ����������� ������
		// (�� static, ��� ��� � ���� ������ ��� ������ 
		// ����������� �������� ������� ��� �����, � ��� 
		// � ���� ����� ����� �������������� � ������ �����������)
		std::unordered_map<std::string, sf::SoundBuffer*> m_soundBuffers;


	};

}; // namespace pg
