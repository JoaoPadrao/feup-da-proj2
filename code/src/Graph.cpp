#include "../headers/Graph.h"
#include "../headers/VertexPlaceEdge.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}
std::vector<VertexPlace *> Graph::getVertexPlaceSet() const {
    return vertexPlaceSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id));
    return true;
}

bool Graph::addPlace(Place *place) {
    if (findPlace(place->getID()) != nullptr)
        return false;
    vertexPlaceSet.push_back(new VertexPlace(place));
    return true;
}

VertexPlace *Graph::findPlace(int id) const {
    for (auto v : vertexPlaceSet)
        if (v->getPlace()->getID() == id)
            return v;
    return nullptr;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

bool Graph::addBidirectionalEdgePlace(const int &sourc, const int &dest, double w) {
    auto v1 = findPlace(sourc);
    auto v2 = findPlace(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdgePlace(v2, w);
    auto e2 = v2->addEdgePlace(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}