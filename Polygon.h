
#ifndef POLYGON_H
#define	POLYGON_H

using namespace std;

class Polygon {
public:
    
    Polygon(Vertex vertexArray[], int size);
    Polygon() : vertices(0), arraySize(0) {}
    ~Polygon() {delete[] vertices;}
    void add(Vertex v);
    float area() ;
    int minx();
    int maxx();
    int miny();
    int maxy();
    int numVertices() const {return arraySize;}
    friend ostream &operator << (ostream &output, const Polygon& polygon);
    friend bool operator < (Polygon polygon1, Polygon polygon2);
    const Polygon & operator=(const Polygon & arr);
    Polygon(const Polygon& rhs);
  
private:
    
    int arraySize;
    Vertex * vertices;
    
};


#endif	/* POLYGON_H */

