#pragma once

#include <vector>

#include "GameObject.hpp"

namespace pg {

	class GameField {
	public:
		GameField(sf::Vector2f size, sf::Vector2f cellSize);

		/**
		* ��������� ���������� ������� � �����
		* ���� �����-�� ������ ��� ��� � �����, �� �� ������� ��������� � ����������� �����
		* @param object ����������� ������
		*/
		void addAllObjects(std::vector<GameObject> objects);

		/**
		* ��������� ������ � �����
		* ���� ������ ��� ��� � �����, �� �� ������� ��������� � ����������� �����
		* @param object ����������� ������
		*/
		void addObject(GameObject &object);

		~GameField();
	
	private:
		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;
		 
		std::vector<std::vector<std::vector<GameObject *>>> grid;

		void createGrid();
		
	};

} // namespace pg
