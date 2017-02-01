#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "No input" << endl;
		return -1;
	}

	Mat image, CroppedImage;
	ofstream out("Averaged_Values.txt");
	ostringstream name;
	int Width = 400, Height = 400;
	long Avg_blue = 0, Avg_red = 0, Avg_green = 0, A_Blue, A_Red, A_Green, blueCount=0, redCount=0, greenCount=0;


	for (int num = 1; num < argc; num++) {
		image = imread(argv[num], IMREAD_COLOR); // Read the file

		if (image.empty())                      // Check for invalid input
		{
			cout << "Could not open or find the image" << std::endl;
			return -1;
		}

		Rect crop(((image.cols / 2) - 200), ((image.rows / 2) - 200), Width, Height);
		//Rect crop(500, 150, 100, 100);
		CroppedImage = image(crop);
		name << "Cropped_" << num << ".jpg";
		imwrite(name.str(), CroppedImage);
		name.str("");

		Vec3b intensity;
		for (int x = 0; x < CroppedImage.rows; x++) {
			for (int y = 0; y < CroppedImage.cols; y++) {
				intensity = image.at<Vec3b>(x, y);
				uchar blue = intensity.val[0];
				uchar green = intensity.val[1];
				uchar red = intensity.val[2];
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
				//cout << "Blue = " << (int)blue << "Green = " << (int)green << "Red = " << (int)red << endl;
			}
		}


		/*A_Blue = Avg_blue / (CroppedImage.rows*CroppedImage.cols);
		A_Red = Avg_red / (CroppedImage.rows*CroppedImage.cols);
		A_Green = Avg_green / (CroppedImage.rows*CroppedImage.cols);*/
		if (blueCount != 0 && redCount != 0 && greenCount != 0) {
			A_Blue = Avg_blue / (blueCount);
			A_Red = Avg_red / (redCount);
			A_Green = Avg_green / (greenCount);
		}
		else {
			cout << "Saturated Image" << endl;
			continue;
		}

		cout << "Image " << num << endl;
		cout << "AverageBlue = " << Avg_blue << " AverageRed = " << Avg_red << " AverageGreen = " << Avg_green << endl;
		/*cout << endl;
		cout << blueCount << " " << redCount << " " << greenCount << endl;
		cout << endl;*/
		cout << "Average Blue = " << A_Blue << " Average Red = " << A_Red << " Average Green = " << A_Green << endl;

		out << "Image " << num << endl;
		out << "Average Blue Values, " << A_Blue << endl;
		out << "Average Red Values, " << A_Red << endl;
		out << "Average Green Values, " << A_Green << endl;
		out << endl;

		Avg_blue = 0;
		Avg_red = 0;
		Avg_green = 0;
		blueCount = 0;
		redCount = 0;
		greenCount = 0;

	}
	//	namedWindow("CroppedImage", CV_WINDOW_AUTOSIZE);
		//imshow("image", CroppedImage);
		//waitKey();
	out.close();
	return 0;
}
