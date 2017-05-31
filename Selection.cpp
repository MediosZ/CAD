#include "Core.h"

void helpk() {
	cout << "the screen is 1080 * 720 \n"
		<< "parameters should be like (100,100,100,100) \n";
}

void triangle(Mat image, Point_set point, Scalar sca);

void Selection (Windows& win) {
	/*--------------------------------------------------------------------*/
	int operation(0), shape(0);
	string name("");
	int para[6] = {};
	int i = 0;
	char t_char = 0;
	/*------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------*/
	cout << "choose one option , input the number in front of it. \n"
		<< "1.create. \n"
		<< "2.move. \n"
		<< "3.set. \n"
		<< "4.delete. \n"
		<< "5.help. \n"
		<< "6.show. \n"
		<< "7.exit. \n";
	cin >> operation;

	if (operation == 5) {
		helpk();
		//cout << "help" << endl;
		system("pause");
		return;
	}
	if (operation == 6) {
		win.PrintElements();
		return;
	}
	if (operation == 7) {
		exit(0);
	}
	if (operation == 4) {
		cout << "choose one graph \n";
		win.PrintEle();
		if (win.size() == 0) {
			return;
		}
		cin >> shape;
		win[i]->remove(win);
		return;
	}
	if (operation == 2) {
		cout << "choose one graph \n";
		win.PrintEle();
		if (win.size() == 0) {
			return;
		}
		cin >> shape;
		cout << "input parameters \n";
		cin >> t_char;
		while (t_char != ')') {
			if (cin.fail())
				break;
			cin >> para[i];
			cin >> t_char;
			i++;
		}
		win[shape]->Move(para[0],para[1],win);
		win.Out();
		win.DrawAll();
		return;
	}
	if (operation == 3) {
		cout << "choose one graph \n";
		win.PrintEle();
		if (win.size() == 0) {
			return;
		}
		cin >> shape;
		cout << "input parameters \n";
		cin >> t_char;
		while (t_char != ')') {
			if (cin.fail())
				break;
			cin >> para[i];
			cin >> t_char;
			i++;
		}
		win[shape]->Set(para, win);
		win.Out();
		win.DrawAll();
		return;
	}

	if (operation == 1) {
		cout << "choose one shape \n"
			<< "1.Rectangle  2.Triangle  3.Circle  4.Line \n";
		cin >> shape;
		cout << "input name : \n";
		cin >> name;
		cout << "input parameters \n";
		cin >> t_char;
		while (t_char != ')') {
			if (cin.fail())
				break;
			cin >> para[i];
			cin >> t_char;
			i++;
		}
		switch (shape) {
		case 1: {Graph* r = new Rectangle(name, para[2], para[3], para[0], para[1]);
			win.push_back(r);
			rectangle(win.src_image, Rect(para[0], para[1], para[2], para[3]), Scalar(0, 0, 0));
			break;
		}
		case 2: {Graph* t = new Triangle(name, para[2], para[3], para[4], para[5], para[0], para[1]);
			win.push_back(t);
			triangle(win.src_image, static_cast<Triangle*>(t)->GetPointSet(), Scalar(0, 0, 0));
			break;
		}
		case 3: {Graph* c = new Circle(name, para[2], para[0], para[1]);
			win.push_back(c);
			circle(win.src_image, Point(para[0], para[1]), para[2], Scalar(0, 0, 0));
			break;
		}
		case 4: {Graph* l = new Line(name, para[2], para[3], para[0], para[1]);
			win.push_back(l);
			line(win.src_image, Point(para[0], para[1]), Point(para[2], para[3]), Scalar(0, 0, 0));
			break;
		}
		default:break;
		}
		win.Out();
	}


	/*--------------------------------------------------------------------*/
}



