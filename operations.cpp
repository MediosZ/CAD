#include "Core.h"

void help() {
	cout << "the screen is 1080 * 720 \n"
		<< " create new graph: \n"
		<< " create shape name(parameters) \n"
		<< " create rectangle rec(200, 200, 200, 200) \n"
		<< " adjust a graph : \n"
		<< " set shape name(parameters) \n"
		<< " set rectangle rec(300, 300, 300, 300) \n"
		<< " move a graph : \n"
		<< " move shape name(parameters) \n"
		<< " move rectangle rec(100, 300) \n"
		<< " delete a graph : \n"
		<< " del shape name \n"
		<< " del rectangle rec \n";
}

void triangle(Mat image, Point_set point, Scalar sca){
	line(image, point.point1, point.point2, sca);
	line(image, point.point1, point.point3, sca);
	line(image, point.point3, point.point2, sca);
}

void Do(Windows& win){
	/*--------------------------------------------------------------------*/
	string operation(""), shape(""), name("");
	int para[6] = {};
	int i = 0;
	char t_char = 0;
	/*--------------------------------------------------------------------*/

	/*--------------------------------------------------------------------*/
	cin >> operation;
	if (operation == "help"){
		help();
		system("pause");
		return;
	}
	if (operation == "show"){
		win.PrintEle();
		system("pause");
		return;
	}
	if (operation == "exit"){
		win.SaveAll();
		win.DeleteAll();
		exit(0);
	}

	cin >> shape >> name;
	t_char = cin.get();
	if (cin.rdbuf()->in_avail() != 0){
		t_char = cin.get();
		if (!cin.fail()){
			while (t_char != ')'){
				if (cin.fail())
					break;
				cin >> para[i];
				cin >> t_char;
				i++;
			}
		}
	}
	/*---------------------------------------------------------------------*/

	/*---------------------------------------------------------------------*/
	if (operation == "create"){
		if (shape == "rectangle"){
			Graph* r = new Rectangle(name, para[2], para[3], para[0], para[1]);
			win.push_back(r);
			rectangle(win.src_image, Rect(para[0], para[1], para[2], para[3]), Scalar(0, 0, 0));
		} else if (shape == "triangle") {
			Graph* t = new Triangle(name, para[2], para[3], para[4], para[5], para[0], para[1]);
			win.push_back(t);
			triangle(win.src_image, static_cast<Triangle*>(t)->GetPointSet(), Scalar(0,0,0));
		} else if (shape == "line") {
			Graph* l = new Line(name, para[2], para[3], para[0], para[1]);
			win.push_back(l);
			line(win.src_image, Point(para[0], para[1]), Point(para[2], para[3]), Scalar(0, 0, 0));
		} else if (shape == "circle") {
			Graph* c = new Circle(name, para[2], para[0], para[1]);
			win.push_back(c);
			circle(win.src_image, Point(para[0], para[1]), para[2], Scalar(0, 0, 0));
		} else {
			cout << "Wrong shape !\n";
			system("pause");
			return;
		}
		win.Out();
	} else if (operation == "move") {
		if (shape == "rectangle") {
			for (int i = 0; i < win.size(); i++){
				if (win[i]->GetId() == name && win[i]->GetFlag() == 1){
					win[i]->Move(para[0], para[1], win);
				}
			}
		} else if (shape == "triangle") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 2) {
					win[i]->Move(para[0], para[1], win);
				}
			}
		} else if (shape == "line") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 4) {
					win[i]->Move(para[0], para[1], win);
				}
			}
		} else if (shape == "circle") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 3) {
					win[i]->Move(para[0], para[1], win);
				}
			}
		} else {
			cout << "Wrong shape !\n";
			system("pause");
			return;
		}

		/*----------------------------*/
		win.Out();
		win.DrawAll();
		/*----------------------------*/
	} else if (operation == "set") {
		if (shape == "rectangle") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 1) {
					win[i]->Set(para, win);
				}
			}
		} else if (shape == "triangle") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 2) {
					win[i]->Set(para, win);
				}
			}

		} else if (shape == "line")  {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 4) {
					win[i]->Set(para, win);
				}
			}
		} else if (shape == "circle")  {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 3) {
					win[i]->Set(para, win);
				}
			}
		} else {
			cout << "Wrong shape !\n";
			system("pause");
			return;
		}
		/*----------------------------*/
		win.Out();
		win.DrawAll();
		/*----------------------------*/
	} else if (operation == "del") {
		if (shape == "rectangle") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 1) {
					win[i]->remove(win);
				}
			}
		} else if (shape == "triangle") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 2) {
					win[i]->remove(win);
				}
			}
		} else if (shape == "line") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 4){
					win[i]->remove(win);
				}
			}
		} else if (shape == "circle") {
			for (int i = 0; i < win.size(); i++) {
				if (win[i]->GetId() == name && win[i]->GetFlag() == 3) {
					win[i]->remove(win);
				}
			}
		} else if (shape == "all") {
			win.DeleteAll();
		} else {
			cout << "Wrong shape !\n";
			system("pause");
			return;
		}
		/*----------------------------*/
		win.Out();
		win.DrawAll();
		/*----------------------------*/
	} else {
		cout << "error \n";
		system("pause");
	    return;
	}
	/*--------------------------------------------------------------------*/
}


