
#ifndef POLYGON_H
#define	POLYGON_H

using namespace std;

class Polygon {
public:
    
    Polygon(Vertex vertexArray[], int size);
    Polygon() : vertices(0), arraySize(0) {}
    ~Polygon() {delete[] vertices;}
    void add(Vertex v);
    float area();
    int minx();
    int maxx();
    int miny();
    int maxy();
    int numVertices() {return arraySize;}
    
private:
    
    int arraySize;
    Vertex * vertices;
    
};




#endif	/* POLYGON_H */

