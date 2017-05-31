#ifndef _Core_h_
#define _Core_h_

#include<iostream>
#include<vector>
#include<string>
#include<vector>
#include<opencv2/opencv.hpp>
#include<core.hpp>

using namespace std;
using namespace cv;

#define WINDOW_NAME "simple CAD"

struct Point_set;
class Windows;
void triangle(Mat image, Point_set point, Scalar sca);

class mPoint {
	friend class Rectangle;
	friend class Triangle;
	friend class Circle;
	friend class Line;

public:
	mPoint(const int x = 0, const int y = 0):_x(x), _y(y) {}
	void Set(const int x, const int y) {
		_x = x;
		_y = y;
	}
	void Move(const int x, const int y) {
		_x += x;
		_y += y;
	}
	mPoint& operator= (const mPoint point) {
		_x = point._x;
		_y = point._y;
		return *this;
	}
	operator Point() const {
		return Point(_x, _y);
	}

private:
	int _x, _y;
};

struct Point_set {
	Point_set(mPoint point_1, mPoint point_2, mPoint point_3 = mPoint(0, 0)) :point1(point_1), point2(point_2), point3(point_3) {}
	mPoint point1;
	mPoint point2;
	mPoint point3;
};

class Graph {
public:
	Graph(string name, int x = 0,int y = 0, int f = 0) :main_point(x,y), id(name), flag(f) {}
	virtual void Set(int x, int y)
	{
		main_point.Set(x, y);
	}
	virtual void Move(int x, int y, Windows& win)=0;
	virtual void Print() = 0;
	virtual string GetId() { return id; }
	virtual int GetFlag() { return flag; }
	virtual void Draw(Windows& win)=0;
	virtual bool IsOut() = 0;
	virtual void MarkAsRed(Windows& win)=0;
	virtual void remove(Windows& win) = 0;
	virtual void Set(int para[], Windows& win) =0;
	string GetShape();

protected:
	mPoint main_point;
	string id;
	int flag;
};

class Windows {
public:
	Windows(string name = WINDOW_NAME, string path = "test.jpg") {
		src_image = imread(path);
		namedWindow(WINDOW_NAME);
	}
	void push_back(Graph* p_gra) { root.push_back(p_gra); }
	int size() { return (int)root.size(); }
	Graph* operator[] (int i) { return root[i]; }
	void remove(int i) { root.erase(root.begin() + i); }
	void move(int i, int x, int y) { root[i]->Move(x, y, *this); }
	void PrintEle();
	void PrintElements();
	void DrawAll(); 
	void Out();

private:
	vector<Graph*> root;

public:
	Mat src_image;
};

class Rectangle : public Graph {
public:
	Rectangle(string name, int width, int height, int x = 0, int y = 0) :Graph(name,x,y,1), _width(width), _height(height) {}
	void Print() { cout << "this is a rectangle \n"; }
	void remove(Windows& win);
	Rect GetRect() { return Rect(main_point._x, main_point._y, _width, _height); }
	void Draw(Windows& win){ rectangle(win.src_image, GetRect(), Scalar(0, 0, 0)); }
	void Move(int x, int y, Windows& win);
	void Set(int para[], Windows& win);
	bool IsOut();
	void MarkAsRed(Windows& win);

private:
	int _width, _height;

};

class Triangle : public Graph {
public:
	Triangle(string name, int x_1, int y_1, int x_2, int y_2, int x = 0, int y = 0) :Graph(name, x, y, 2), point_1(x_1, y_1), point_2(x_2, y_2), _point(main_point, point_1, point_2){}
	void Print() { cout << "this is a triangle \n"; }
	Point_set GetPointSet() { return _point; }
	void remove(Windows& win);
	void Draw(Windows& win) { triangle(win.src_image, GetPointSet(), Scalar(0, 0, 0)); }
	void Move(int x, int y, Windows& win);
	void Refresh();
	bool IsOut();
	void Set(int para[], Windows& win);
	void MarkAsRed(Windows& win);

private:
	mPoint point_1, point_2;
	Point_set _point;
};

class Circle : public Graph {
public:
	Circle(string name, int radius, int x = 0, int y = 0) :Graph(name, x, y, 3), _radius(radius){}
	void Print() { cout << "this is a circle \n"; }
	mPoint GetPoint() { return main_point; }
	int GetRadius() { return _radius; }
	void remove(Windows& win);
	void Move(int x, int y, Windows& win);
	void Set(int para[], Windows& win);
	void Draw(Windows& win) { circle(win.src_image, GetPoint(), GetRadius(), Scalar(0, 0, 0)); }
	bool IsOut();
	void MarkAsRed(Windows& win);
private:
	int _radius;
};

class Line : public Graph {
public:
	Line(string name, int x_1, int y_1, int x = 0, int y = 0) :Graph(name, x, y, 4), point_1(x_1, y_1), _point(main_point, point_1) {}
	void Print() { cout << "this is a line \n"; }
	Point_set GetPoint() { return _point; }
	void remove(Windows& win);
	void Move(int x, int y, Windows& win);
	void Set(int para[], Windows& win);
	void Draw(Windows& win) { line(win.src_image, GetPoint().point1, GetPoint().point2, Scalar(0, 0, 0)); }
	bool IsOut();
	void MarkAsRed(Windows& win);
private:
	mPoint point_1;
	Point_set _point;
};


#endif
