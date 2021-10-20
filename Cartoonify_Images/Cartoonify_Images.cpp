// Cartoonify_Images.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/photo.hpp>

using namespace cv;
using namespace std;

int main()
{
	vector<string> filenames;
	string filepath = "E:/Android_Data/images/res/*.jpg";
	Mat image, dst, grey, dst1, blur, edges, color_image, cartoon, out, dst_grey;
	string name;
	glob(filepath, filenames);
	cout << "Total files" << filenames.size() << endl;
	
	for (int i = 0; i < filenames.size(); i++) {
		name = "E:/Android_Data/res/Image_" + to_string(i) + ".jpg";

		image = imread(filenames[i]);
		//cvtColor(image, grey, COLOR_BGR2GRAY);
		/*cvtColor(image, grey, COLOR_BGR2GRAY);
		medianBlur(grey, blur, 7);
		adaptiveThreshold(blur, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, 7);
		bilateralFilter(edges, color_image, 9, 250,250);
		bitwise_and(color_image, edges, cartoon);*/
		//edgePreservingFilter(image, dst, 1,60,0.4);
		//detailEnhance(dst, dst1, 10, 0.15);
		//pencilSketch(image, dst_grey, color_image, 60 , 0.07, 0.02);
		stylization(image, dst, 60, 0.45f);
	
		imwrite(name, dst);

		cout << "Image number " << i + 1 << " saved \n";
	}
	//Mat image = imread("E:\Android_Data\images");
	
	//imshow("Display Window", image);
	waitKey(0);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
