#ifndef PATHFINDING_HH
#define PATHFINDING_HH

#include <list>
#include <algorithm>
#include <iostream>
#include "Map.hh"

class PathFinding{
public:
	PathFinding();
	~PathFinding();

	

	class point {
	public:
    	point( int a = 0, int b = 0 ) { x = a; y = b; }
    	bool operator ==( const point& o ) { return o.x == x && o.y == y; }
    	point operator +( const point& o ) { return point( o.x + x, o.y + y ); }
    	int x, y;

	}; 

	class node {
	public:
    	bool operator == (const node& o ) { return pos == o.pos; }
   		bool operator == (const point& o ) { return pos == o; }
    	bool operator < (const node& o ) { return dist + cost < o.dist + o.cost; }
    	point pos, parent;
    	int dist, cost;
	};



	void aStar();
	int calcDist(point& p);
	bool isValid(point& p);
	bool existPoint(point& p, int cost);
	bool fillOpen(node& n);
	bool search(point& s, point& e, LevelMap &levelMap);
	int path(std::list<point>& path);


	//LevelMap levelM; 
	Map levl;
	//Map.lvl lvl;
	point end;
	point start;
    point neighbours[31];
    std::list<node> open;
    std::list<node> closed;

    //int operator() ( int x, int y ) { return m[x][y]; }
};

#endif // PATHFINDING_HH