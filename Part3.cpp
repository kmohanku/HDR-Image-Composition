/*#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include<cmath>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "No input" << endl;
		return -1;
	}

	Mat image, image1, image2, image3, HDR2, HDR2_OP;
	//ofstream out("Averaged_Values.txt");
	ostringstream name;
	float GR = 2.0696982, GB = 1.984126984, GG = 2.066542674;
	float A_Blue, A_Red, A_Green, gamma, saturation, bias;
	int Width = 400, Height = 400;
	long Avg_blue = 0, Avg_red = 0, Avg_green = 0, blueCount = 0, redCount = 0, greenCount = 0;
	long blue, green, red;
	Vec3b intensity;
	double Lin_Blue, Lin_Red, Lin_Green;

	image = imread(argv[1], IMREAD_COLOR);
	image1 = imread(argv[1], IMREAD_COLOR); // Read the file
	image2 = imread(argv[2], IMREAD_COLOR); // Read the file
	image3 = imread(argv[3], IMREAD_COLOR); // Read the file

	Mat HDR(image.cols, image.rows, CV_8UC3, Scalar(0, 0, 0));

	for (int x = 0; x < image.rows; x++) {
		for (int y = 0; y < image.cols; y++) {

			
			if (image1.empty())                      // Check for invalid input
			{
				cout << "Could not open or find the image" << std::endl;
				continue;
			}

			intensity = image1.at<Vec3b>(x, y);
			blue = intensity.val[0];
			green = intensity.val[1];
			red = intensity.val[2];
			if (blue != 255) {
				Avg_blue += blue;
				blueCount++;
			}
			if (red != 255) {
				Avg_red += red;
				redCount++;
			}
			if (green != 255) {
				Avg_green += green;
				greenCount++;
			}

			
			if (image2.empty())                      // Check for invalid input
			{
				cout << "Could not open or find the image" << std::endl;
				continue;
			}

			intensity = image2.at<Vec3b>(x, y);
			blue = intensity.val[0];
			green = intensity.val[1];
			red = intensity.val[2];
			if (blue != 255) {
				Avg_blue += blue;
				blueCount++;
			}
			if (red != 255) {
				Avg_red += red;
				redCount++;
			}
			if (green != 255) {
				Avg_green += green;
				greenCount++;
			}

		
			if (image3.empty())                      // Check for invalid input
			{
				cout << "Could not open or find the image" << std::endl;
				continue;
			}

			intensity = image3.at<Vec3b>(x, y);
			blue = intensity.val[0];
			green = intensity.val[1];
			red = intensity.val[2];
			if (blue != 255) {
				Avg_blue += blue;
				blueCount++;
			}
			if (red != 255) {
				Avg_red += red;
				redCount++;
			}
			if (green != 255) {
				Avg_green += green;
				greenCount++;
			}


			if (blueCount != 0 && redCount != 0 && greenCount != 0) {
				A_Blue = Avg_blue / (blueCount);
				A_Red = Avg_red / (redCount);
				A_Green = Avg_green / (greenCount);
			}
			else {
				cout << "Saturated Image" << endl;
				continue;
			}

			Lin_Blue = powf(A_Blue, GB);
			Lin_Red = powf(A_Red, GR);
			Lin_Green = powf(A_Green, GG);

			//intensity = HDR2.at<Vec3b>(x, y);
			intensity.val[0] = Lin_Blue;
			intensity.val[1] = Lin_Red;
			intensity.val[2] = Lin_Green;
			HDR2.at<Vec3b>(x, y) = intensity;

			Avg_blue = 0;
			Avg_green = 0;
			Avg_red = 0;
			blueCount = 0;
			redCount = 0;
			greenCount = 0;
		}

	}

	Ptr<TonemapDrago> tonemap = createTonemapDrago(gamma = 1.0f, saturation = 1.0f, bias = 0.85f);
	//Ptr<TonemapDurand> tonemap = createTonemapDrago(gamma = 1.0f);
	tonemap -> process(HDR2, HDR2_OP);
	imwrite("HDR_2", HDR2_OP);

	return 0;
}*/

