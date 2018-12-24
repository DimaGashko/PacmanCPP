#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "Math.hpp"
#include "GameObject.hpp"
#include "Actor.hpp"

namespace pg {

	class GameField {
	public:
		GameField();
		GameField(sf::Vector2i size, sf::Vector2i cellSize);

		void addAllObjects(std::vector<GameObject*> objects);
		void addObject(GameObject *object);

		void draw(sf::RenderWindow &window, sf::FloatRect visibleRange);
		void update(sf::Vector2f gameSize, int frameTime);

		void setPlayer(Actor *actor);
		Actor* getPlayer();

		// ������������ ��������� ������
		// ��� ��������� ��������������� �������:
		// auto side = eSides::Left;
		// auto coSide = eSides(-side);
		enum eSides {
			Left = -1,
			Right = 1,

			Top = -2,
			Bottom = 2,
		};

		~GameField();
	
	private:
		int m_pointsCount = 0;
		Actor *m_player;

		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;
		 
		// C���� ����
		std::vector<std::vector<std::vector<GameObject *>>> m_grid;

		// ������, ���������� ���������� ���� �������� � ����� �� �� id
	    // ������������ ��� �������� ����������� ��� � ������ ������ ��������� ������
	    // (������������, ��� �� �������� ������ �� ����������� �����)
		std::unordered_map<GameObject*, sf::Vector2i> m_objectCoords;

		template<typename F>
		void forEachObjectsOfRange(sf::FloatRect range, F &&func);

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

		sf::FloatRect _getActiveRange(sf::Vector2f gameSize);

		bool _hasCell(sf::Vector2i coords);
		sf::Vector2i _getCoordsInGrid(sf::Vector2f coords);

		// ���������� ������� obj2, � ������� ���������� obj1
		eSides getCollitionSide(GameObject *obj1, GameObject *obj2);
	};

} // namespace pg
