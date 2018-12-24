#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <typeinfo>

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

		enum eSides { Left, Top, Right, Bottom };

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

		// ��������� ���������� ������� � �����
		// ���� �����-�� ������ ��� ��� � �����, �� �� ������� ��������� � ����������� �����
		void addAllObjectsToGrid(std::vector<GameObject*> objects);

		// ��������� ������ � �����
		// ���� ������ ��� ��� � �����, �� �� ������� ��������� � ����������� �����
		void addObjectToGrid(GameObject *object);

		sf::FloatRect _getActiveRange(sf::Vector2f gameSize);

		bool _hasCell(sf::Vector2i coords);
		sf::Vector2i _getCoordsInGrid(sf::Vector2f coords);

		void procCollision(GameObject *obj1, GameObject *obj2);

		// ���������� ������� obj2, � ������� ���������� obj1
		eSides _getCollisionSide(GameObject *obj1, GameObject *obj2);
	};

} // namespace pg
