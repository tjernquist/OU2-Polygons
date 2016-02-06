
#include <iostream>
#include "Vertex.h"
#include "Polygon.h"

using namespace std;

int main() {

    Vertex v[] = {Vertex(0, 0), Vertex(6, 0), Vertex(6, 6), Vertex(0, 6)};

    Polygon p(v, 4);

    cout << "Antal vertices " << p.numVertices() << endl;
    cout << "Area " << p.area() << endl;
    cout << "min x: " << p.minx() << endl;
    cout << "max x: " << p.maxx() << endl;
    cout << "min y: " << p.miny() << endl;
    cout << "max y: " << p.maxy() << endl << endl;

    p.add(Vertex(-1, 3));

    cout << "Antal vertices " << p.numVertices() << endl;
    cout << "Area " << p.area() << endl;
    cout << "min x: " << p.minx() << endl;

    Polygon p1;
    p1.add(Vertex(0, 0));
    p1.add(Vertex(3, 3));
    p1.add(Vertex(3, 0));

    cout << "Area " << p1.area() << endl;




    return 0;

}
