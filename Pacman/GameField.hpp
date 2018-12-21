#pragma once

#include <vector>
#include <unordered_map>

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
		void addAllObjects(std::vector<GameObject*> objects);

		/**
		* ��������� ������ � �����
		* ���� ������ ��� ��� � �����, �� �� ������� ��������� � ����������� �����
		* @param object ����������� ������
		*/
		void addObject(GameObject *object);

		~GameField();
	
	private:
		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;
		 
		// C���� ����
		std::vector<std::vector<std::vector<GameObject *>>> m_grid;

		// ������, ���������� ���������� ���� �������� � ����� �� �� id
	    // ������������ ��� �������� ����������� ��� � ������ ������ ��������� ������
	    // (������������, ��� �� �������� ������ �� ����������� �����)
		std::unordered_map<GameObject*, sf::Vector2i> m_objectCoords;

		sf::Vector2i getCoordsInGrid(sf::Vector2f);

		void createGrid();
		
	};

} // namespace pg
