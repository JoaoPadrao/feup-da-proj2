#ifndef VERTEXEDGE_H
#define VERTEXEDGE_H

#include <vector>
#include <climits>

class Edge;

struct Coords {
    double longitude;
    double latitude;
};

class Vertex {
public:
    Vertex(int id);
    ~Vertex();

    int getId() const;
    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    Edge *getPath() const;
    std::vector<Edge *> getIncoming() const;
    Coords* getCoords() const;

    void setId(int info);
    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Edge *path);
    void setCoords(double longitude, double latitude);
    Edge * addEdge(Vertex *dest, double w);
    bool removeEdge(int destID);
    void removeOutgoingEdges();

protected:
    int id;                // identifier
    std::vector<Edge *> adj;  // outgoing edges

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge *path = nullptr;
    bool operator<(Vertex & vertex) const;

    Coords *coords = nullptr;

    std::vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

    void deleteEdge(Edge *edge);
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double dist);
    Vertex * getDest() const;
    double getDistance() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
protected:
    Vertex * dest;
    double dist;

    // auxiliary fields
    bool selected = false;

    Vertex *orig;
    Edge *reverse = nullptr;

};

#endif //VERTEXEDGE_H
