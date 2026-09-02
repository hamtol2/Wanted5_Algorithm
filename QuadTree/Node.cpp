#include "Node.h"

Node::Node(const Bounds& bounds, int depth)
	: bounds(bounds), depth(depth)
{
}

Node::~Node()
{
	Clear();
}

bool Node::Insert(Node * node)
{
	return false;
}

void Node::Query(const Bounds& queryBounds, std::vector<Node*>& results) const
{}

void Node::Clear()
{}

bool Node::Subdivide()
{
	return false;
}

bool Node::IsDivided() const
{
	return false;
}

NodeIndex Node::TestRegion(const Bounds& targetBounds) const
{
	return NodeIndex();
}

std::vector<NodeIndex> Node::GetQuads(const Bounds& targetBounds) const
{
	return std::vector<NodeIndex>();
}

void Node::ClearChildren()
{}
