#include"Core.h"

// draw triangle
void triangle(Mat image, Point_set point, Scalar sca);

/*-------------------------------------Move function-------------------------------------------------------------*/
void Rectangle::Move(int x, int y, Windows& win) {
	rectangle(win.src_image, GetRect(), Scalar(255, 255, 255));
	main_point._x += x;
	main_point._y += y;
	rectangle(win.src_image, GetRect(), Scalar(0, 0, 0));
}
void Circle::Move(int x, int y, Windows& win) {
	circle(win.src_image, GetPoint(), GetRadius(), Scalar(255, 255, 255));
	main_point._x += x;
	main_point._y += y;
	circle(win.src_image, GetPoint(), GetRadius(), Scalar(0, 0, 0));

}
void Line::Move(int x, int y, Windows& win) {
	line(win.src_image, GetPoint().point1, GetPoint().point2, Scalar(255, 255, 255));
	main_point._x += x;
	main_point._y += y;
	point_1._x += x;
	point_1._y += y;
	line(win.src_image, GetPoint().point1, GetPoint().point2, Scalar(0, 0, 0));
}

void Triangle::Move(int x, int y, Windows& win){
	triangle(win.src_image, GetPointSet(), Scalar(255, 255, 255));
	main_point.Move(x, y);
	point_1.Move(x, y);
	point_2.Move(x, y);
	Refresh();
	triangle(win.src_image, GetPointSet(), Scalar(0, 0, 0));
}
/*--------------------------------------------------------------------------------------------------*/

/*--------------------------------------Set function------------------------------------------------------------*/
void Rectangle::Set(int para[], Windows& win){
	rectangle(win.src_image, GetRect(), Scalar(255, 255, 255));
	main_point.Set(para[0], para[1]);
	_width = para[2];
	_height = para[3];
	rectangle(win.src_image, GetRect(), Scalar(0, 0, 0));
}

void Triangle::Set(int para[], Windows& win){
	triangle(win.src_image, GetPointSet(), Scalar(255, 255, 255));
	main_point.Set(para[0], para[1]);
	point_1.Set(para[2], para[3]);
	point_2.Set(para[4], para[5]);
	Refresh();
	triangle(win.src_image, GetPointSet(), Scalar(0, 0, 0));
}

void Circle::Set(int para[], Windows& win){
	circle(win.src_image, GetPoint(), GetRadius(), Scalar(255, 255, 255));
	main_point.Set(para[0], para[1]);
	_radius = para[2];
	circle(win.src_image, GetPoint(), GetRadius(), Scalar(0, 0, 0));
}

void Line::Set(int para[], Windows& win){
	line(win.src_image, GetPoint().point1, GetPoint().point2, Scalar(255, 255, 255));
	main_point.Set(para[0], para[1]);
	point_1.Set(para[2], para[3]);
	line(win.src_image, GetPoint().point1, GetPoint().point2, Scalar(0, 0, 0));
}
/*--------------------------------------------------------------------------------------------------*/

/*------------------------------Remove functions-----------------------------------------------*/
void Rectangle::remove(Windows& win){
	rectangle(win.src_image, GetRect(), Scalar(255, 255, 255));
	for (int i = 0; i < win.size(); i++){
		if (win[i]->GetId() == id && win[i]->GetFlag() == 1){
			win.remove(i);
		}
	}
}

void Triangle::remove(Windows& win){
	triangle(win.src_image, GetPointSet(), Scalar(255, 255, 255));
	for (int i = 0; i < win.size(); i++){
		if (win[i]->GetId() == id && win[i]->GetFlag() == 2){
			win.remove(i);
		}
	}
}

void Circle::remove(Windows& win){
	circle(win.src_image, GetPoint(), GetRadius(), Scalar(255, 255, 255));
	for (int i = 0; i < win.size(); i++){
		if (win[i]->GetId() == id && win[i]->GetFlag() == 3){
			win.remove(i);
		}
	}
}

void Line::remove(Windows& win){
	line(win.src_image, GetPoint().point1, GetPoint().point2, Scalar(255, 255, 255));
	for (int i = 0; i < win.size(); i++){
		if (win[i]->GetId() == id && win[i]->GetFlag() == 4){
			win.remove(i);
		}
	}
}
/*--------------------------------------------------------------------------------------------------*/

/*------------------------IsOut function-----------------------------------------------------------*/
bool Rectangle::IsOut() {
	if (main_point._x < 0 || main_point._y < 0 || main_point._x>1080 || main_point._y>720) {
		return false;
	}
	if (main_point._x + _width < 0 || main_point._x + _width>1080 || main_point._y + _height < 0 || main_point._y + _height>720) {
		return false;
	}
	return true;
}

bool Triangle::IsOut() {
	if (main_point._x < 0 || main_point._y < 0 || main_point._x>1080 || main_point._y>720) {
		return false;
	}
	if (point_1._x < 0 || point_1._y < 0 || point_1._x>1080 || point_1._y>720) {
		return false;
	}
	if (point_2._x < 0 || point_2._y < 0 || point_2._x>1080 || point_2._y>720) {
		return false;
	}
	return true;
}

bool Circle::IsOut() {
	if (main_point._x < 0 || main_point._y < 0 || main_point._x>1080 || main_point._y>720) {
		return false;
	}
	if (main_point._x + _radius < 0 || main_point._y + _radius < 0 || main_point._x + _radius>1080 || main_point._y + _radius>720) {
		return false;
	}
	if (main_point._x - _radius < 0 || main_point._y - _radius < 0 || main_point._x - _radius>1080 || main_point._y - _radius>720) {
		return false;
	}
	return true;
}

bool Line::IsOut() {
	if (main_point._x < 0 || main_point._y < 0 || main_point._x>1080 || main_point._y>720) {
		return false;
	}
	if (point_1._x < 0 || point_1._y < 0 || point_1._x>1080 || point_1._y>720) {
		return false;
	}
	return true;
}
/*---------------------------------------------------------------------------------------------------*/

/*-----------------------MarkAsRed function-----------------------------------------------------------*/
void Rectangle::MarkAsRed(Windows& win) {
	rectangle(win.src_image, GetRect(), Scalar(0, 0, 255));
}

void Triangle::MarkAsRed(Windows& win) {
	triangle(win.src_image, GetPointSet(), Scalar(0, 0, 255));
}

void Circle::MarkAsRed(Windows& win) {
	circle(win.src_image, GetPoint(), GetRadius(), Scalar(0, 0, 255));
}

void Line::MarkAsRed(Windows& win) {
	line(win.src_image, GetPoint().point1, GetPoint().point2, Scalar(0, 0, 255));
}
/*----------------------------------------------------------------------------------------------------*/

/*---------------------------Save function-----------------------------------------------------------*/
void Rectangle::Save(Windows& win, ostream& os) {
	os << flag << " " << id << " [" << main_point._x << "," << main_point._y << "," << _height << "," << _width << "]" << endl;
}

void Triangle::Save(Windows& win, ostream& os) {
	os << flag << " " << id << " [" << main_point << " " << point_1 << " " << point_2 << "]" << endl;
}

void Circle::Save(Windows& win, ostream& os) {
	os << flag << " " << id << " [" << main_point << " " << _radius << "]" << endl;
}

void Line::Save(Windows& win, ostream& os) {
	os << flag << " " << id << " [" << main_point << " " << point_1 << "]" << endl;
}
/*----------------------------------------------------------------------------------------------------*/

/*------------------Useful functions------------------------------------------------------------------*/
string Graph::GetShape(){
	switch (flag){
	case 1:return "rectangle"; break;
	case 2:return "triangle"; break;
	case 3:return "circle"; break;
	case 4:return "line"; break;
	}
	return "";
}

void Windows::PrintEle(){
	if (root.size() == 0){
		cout << "No graphs ! \n";
		//cin.get();
		system("pause");
		return;
	}
	for (int i = 0; i < root.size(); i++)
		cout <<i+1<<". "<< root[i]->GetShape() << " " << root[i]->GetId() << endl;
}
void Windows::PrintElements() {
	if (root.size() == 0) {
		cout << "No graphs ! \n";
		//cin.get();
		system("pause");
		return;
	}
	for (int i = 0; i < root.size(); i++)
		cout << i << ". " << root[i]->GetShape() << " " << root[i]->GetId() << endl;
	system("pause");
}

void Windows::DrawAll(){
	for (int i = 0; i < root.size(); i++)
		root[i]->Draw(*this);
}

void Triangle::Refresh(){
	_point.point1 = main_point;
	_point.point2 = point_1;
	_point.point3 = point_2;
}

void Windows::Out() {
	for (int i = 0; i < root.size(); i++) {
		if (!(*this)[i]->IsOut()) {
			cout << "Graph " << (*this)[i]->GetShape() << " " << (*this)[i]->GetId() << " is out of the screen ! \n";
			(*this)[i]->MarkAsRed(*this);
			system("pause");
		}
	}
}

void Windows::SaveAll() {
	ofstream os("SaveData.txt");
	char choice;
	cout << "Save data or not ? y/n " << endl;
	cin >> choice;
	if (choice == 'n') {
		return;
	}
	for (int i = 0; i < root.size(); i++)
		root[i]->Save(*this, os);

	os.close();
}

void Windows::DeleteAll() {
	for (int i = 0; i < root.size(); i++)
		root[i]->remove(*this);
}

ostream& operator << (ostream& os, const mPoint& m) {
	cout << "< " << m._x << " , " << m._y << " >";
	return os;
}

/*-------------------------------------------------------------------------------------------------*/