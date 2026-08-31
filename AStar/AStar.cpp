#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

std::vector<Position> AStar::FindPath(
    const Position & startPosition, 
    const Position & goalPosition, 
    std::vector<std::vector<int>>&grid)
{
    return std::vector<Position>();
}

void AStar::DisplayGridWithPath(
    std::vector<std::vector<int>>& grid, 
    const std::vector<Position>& path)
{}

void AStar::Clear()
{}

Node* AStar::CreateNode(const Position & position, Node * parent)
{
    return nullptr;
}
