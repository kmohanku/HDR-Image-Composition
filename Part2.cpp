/*#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

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

	Mat image, B_hist, G_hist, R_hist;;
	const int histSize = 256;
	float Range[] = { 0, 256 };
	const float* ranges = { Range };
	vector<Mat> bgr_planes;
	int hist_width = 512; int hist_height = 400;
	int bin_width = cvRound((double)hist_width / histSize);
	ostringstream name;
	

	for (int num = 1; num < argc; num++) {

		image = imread(argv[num], IMREAD_COLOR); // Read the file
		split(image, bgr_planes);
		Mat hist_image(hist_height, hist_width, CV_8UC3, Scalar(0, 0, 0));

		calcHist(&bgr_planes[0], 1, 0, Mat(), B_hist, 1, &histSize, &ranges, true, false);
		calcHist(&bgr_planes[1], 1, 0, Mat(), G_hist, 1, &histSize, &ranges, true, false);
		calcHist(&bgr_planes[2], 1, 0, Mat(), R_hist, 1, &histSize, &ranges, true, false);

		normalize(B_hist, B_hist, 0, hist_image.rows, NORM_MINMAX, -1, Mat());
		normalize(G_hist, G_hist, 0, hist_image.rows, NORM_MINMAX, -1, Mat());
		normalize(R_hist, R_hist, 0, hist_image.rows, NORM_MINMAX, -1, Mat());

		/// Draw for each channel
		for (int i = 1; i < histSize; i++)
		{
			line(hist_image, Point(bin_width*(i - 1), hist_height - cvRound(B_hist.at<float>(i - 1))),
				Point(bin_width*(i), hist_height - cvRound(B_hist.at<float>(i))),
				Scalar(255, 0, 0), 2, 8, 0);
			line(hist_image, Point(bin_width*(i - 1), hist_height - cvRound(G_hist.at<float>(i - 1))),
				Point(bin_width*(i), hist_height - cvRound(G_hist.at<float>(i))),
				Scalar(0, 255, 0), 2, 8, 0);
			line(hist_image, Point(bin_width*(i - 1), hist_height - cvRound(R_hist.at<float>(i - 1))),
				Point(bin_width*(i), hist_height - cvRound(R_hist.at<float>(i))),
				Scalar(0, 0, 255), 2, 8, 0);
		}

		namedWindow("Histogram for Image", WINDOW_AUTOSIZE);
		imshow(argv[num], hist_image);
		name << "Hist_" << argv[num];
		imwrite(name.str(), hist_image);
		name.str("");

		waitKey(0);
		hist_image.release();
		
	}
	return 0;
}*/