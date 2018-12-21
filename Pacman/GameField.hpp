#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

#include "GameObject.hpp"

namespace pg {

	class GameField {
	public:
		GameField();
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
		std::vector<GameObject *> **m_grid;

		// ������, ���������� ���������� ���� �������� � ����� �� �� id
	    // ������������ ��� �������� ����������� ��� � ������ ������ ��������� ������
	    // (������������, ��� �� �������� ������ �� ����������� �����)
		std::unordered_map<GameObject*, sf::Vector2i> m_objectCoords;
		bool hasCell(sf::Vector2i coords);
		sf::Vector2i getCoordsInGrid(sf::Vector2f coords);

		void createGrid();
		
	};

} // namespace pg
