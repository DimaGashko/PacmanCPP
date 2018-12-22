#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

#include "GameObject.hpp"

namespace pg {

	class GameField {
	public:
		GameField();
		GameField(sf::Vector2i size, sf::Vector2i cellSize);

		void addAllObjects(std::vector<GameObject*> objects);
		void addObject(GameObject *object);

		/**
		 * ���������� ��� ������� ����������� � ���������� ���������
		 * @param start ����� ������� ���� ���������
		 * @param ned ������ ������ ���� ���������
		*/
		std::vector<GameObject*> getObjectsOfRange(sf::Vector2f start, sf::Vector2f end);

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
		
		/**
		 * ��������� ���������� ������� � �����
		 * ���� �����-�� ������ ��� ��� � �����, �� �� ������� ��������� � ����������� �����
		 * @param object ����������� ������
		 */
		void addAllObjectsToGrid(std::vector<GameObject*> objects);

		/**
		 * ��������� ������ � �����
		 * ���� ������ ��� ��� � �����, �� �� ������� ��������� � ����������� �����
		 * @param object ����������� ������
		 */
		void addObjectToGrid(GameObject *object);

		bool _hasCell(sf::Vector2i coords);
		sf::Vector2i _getCoordsInGrid(sf::Vector2f coords);

		void createGrid();
		
	};

} // namespace pg
