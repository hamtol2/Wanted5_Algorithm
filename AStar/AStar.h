#pragma once

#include "Node.h"
#include <vector>

class AStar
{
private:
	// 이동 방향과 해당 방향의 이동 비용.
	struct Direction
	{
		int x = 0;
		int y = 0;
		float cost = 0.0f;
	};

public:
	AStar();
	~AStar();

	// 메시지(객체 지향 프로그래밍 용어) - 공개 메소드(인터페이스).

	// 경로 탐색 요청 함수.
	std::vector<Position> FindPath(
		const Position& startPosition,
		const Position& goalPosition,
		std::vector<std::vector<int>>& grid);

	// 탐색한 최종 경로를 출력하는 함수.
	void DisplayGridWithPath(
		std::vector<std::vector<int>>& grid,
		const std::vector<Position>& path);

private:
	// 메소드.

	// 이전 탐색에 사용한 정보 및 노드를 정리하는 함수.
	void Clear();

	// 노드 생성 전문 함수.
	Node* CreateNode(const Position& position, Node* parent = nullptr);

private:
	// 동적 할당된 모든 노드를 소유하는 목록.
	// 메모리 관리를 위해 사용.
	std::vector<Node*> allocatedNodes;

	// 탐색할 노드 목록/탐색을 마친 노드 목록.
	std::vector<Node*> openList;
	std::vector<Node*> closedList;

	// 시작 노드/목표 노드.
	Node* startNode = nullptr;
	Node* goalNode = nullptr;
};