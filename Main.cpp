#include"Core.h"

using namespace std;
using namespace cv;

void triangle(Mat image, Point_set point, Scalar sca);
void Do(Windows& win);
void Selection(Windows& win);

int main() {
	Windows win(WINDOW_NAME, "test.jpg");
	Mat temp_image;
	namedWindow(WINDOW_NAME, 0);

	// Main function
	cout << "input 1 for Selection Mode , input 2 for Command Mode \n";
	int num = 0;
	cin >> num;
	if (num == 1) {
		while (1) {
			// The welcome GUI
			cout << "*********************************************************************************** \n"
				<< "*******************  welcome to the CAD system  *********************************** \n"
				<< "*******************    <enter help for tips>    *********************************** \n"
				<< "*********************************************************************************** \n";
			//-------------------------------
			// Show the main window 
			win.src_image.copyTo(temp_image);
			imshow(WINDOW_NAME, temp_image);
			cvWaitKey(1);
			//-------------------------------
			Selection(win);
			system("cls");
			//-------------------------------
		}
	}
	else {
		while (1) {
			// The welcome GUI
			cout << "*********************************************************************************** \n"
				<< "*******************  welcome to the CAD system  *********************************** \n"
				<< "*******************    <enter help for tips>    *********************************** \n"
				<< "*********************************************************************************** \n";
			//-------------------------------
			// Show the main window 
			win.src_image.copyTo(temp_image);
			imshow(WINDOW_NAME, temp_image);
			cvWaitKey(1);
			//-------------------------------
		    Do(win);
			system("cls");
			//-------------------------------
		}
	}

	return 0;
}
