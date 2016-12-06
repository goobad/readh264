//#include "stdafx.h"
//#include <opencv2/core/core.hpp> 
//#include <opencv2/highgui/highgui.hpp> 
//#include <opencv2/imgproc/imgproc.hpp>
//#include <cv.h>
#include <stdio.h>
#include "cv.h"
#include "objdetect/objdetect.hpp"
#include "highgui/highgui.hpp"
#include "imgproc/imgproc.hpp"
#include <cctype>
#include <iterator>
#include <iostream>
#include <omp.h>

#include <iostream> 
using namespace std;
using namespace cv;

//Mat blue(1080, 1920, CV_8UC1),green(1080, 1920, CV_8UC1),red(1080, 1920, CV_8UC1);



int shu(int a1, int n)
{
	if (a1 < 0)
		a1 = n + a1 + 1;
	else
		a1 = a1;
	return a1;

}
int range(int a1, int  m, int n)
{
	if (a1 >= m)
	{
		a1 = a1 - n;
	}
	return a1;
}
void image8(Mat  *pblue, Mat *pgreen, Mat *pred, Mat srcImage8);
void image7(Mat  *pblue, Mat *pgreen, Mat *pred, Mat srcImage7);
void image6(Mat  *pblue, Mat *pgreen, Mat *pred, Mat srcImage6);
void image5(Mat  *pblue, Mat *pgreen, Mat *pred, Mat srcImage5);
void image4(Mat  *pblue, Mat *pgreen, Mat *pred, Mat srcImage4);
void image3(Mat  *pblue, Mat *pgreen, Mat *pred, Mat srcImage3);
void image2(Mat  *pblue, Mat *pgreen, Mat *pred, Mat srcImage2);
void image1(Mat  *pblue, Mat *pgreen, Mat *pred, Mat srcImage1);


int main()
{
	//Mat srcImage1, srcImage2, srcImage3, srcImage4, srcImage5, srcImage6, srcImage7, srcImage8;
	Mat blue(1080, 1920, CV_8UC1), green(1080, 1920, CV_8UC1), red(1080, 1920, CV_8UC1);
	Size dsize = Size(720, 360);
	const std::string videoStreamAddress1 = "rtsp://admin:a1234567@192.168.1.64:554/h264/ch1/main/av_stream";
	const std::string videoStreamAddress2 = "rtsp://SCU:SCU-DM8168@192.168.1.65:554/h264/ch1/main/av_stream";

	Mat *pblue = &blue; Mat *pgreen = &green; Mat *pred = &red;
	vector<Mat>channels;
	//const string source = "2.avi";
	VideoCapture inputVideo1;//const string source = "2.avi";
	VideoCapture inputVideo2;//const string source = "2.avi";
	VideoCapture inputVideo3;//const string source = "2.avi";
	VideoCapture inputVideo4;//const string source = "2.avi";
	VideoCapture inputVideo5;//const string source = "2.avi";
	VideoCapture inputVideo6;//const string source = "2.avi";
	VideoCapture inputVideo7;//const string source = "2.avi";
	VideoCapture inputVideo8;


	if (!inputVideo1.open(videoStreamAddress1)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}
	if (!inputVideo2.open(videoStreamAddress2)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -2;
	}
	if (!inputVideo3.open(videoStreamAddress1)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}
	if (!inputVideo4.open(videoStreamAddress2)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -2;
	}
	if (!inputVideo5.open(videoStreamAddress1)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}
	if (!inputVideo6.open(videoStreamAddress2)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -2;
	}
	if (!inputVideo7.open(videoStreamAddress1)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}
	if (!inputVideo8.open(videoStreamAddress2)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -2;
	}


	//int totalFrameNumber = inputVideo1.get(CV_CAP_PROP_FRAME_COUNT);
	int ex = static_cast<int>(inputVideo1.get(CV_CAP_PROP_FOURCC));
	//VideoWriter outputVideo;
	//Size S = Size(1920, 1080);
	//outputVideo.open("mixtrue.avi", ex, inputVideo1.get(CV_CAP_PROP_FPS), S, true);
	int framecount = 0;
	bool stop = false;
	Mat src1;
	Mat src2;
	while (!stop)
	{
#pragma omp parallel sections
		{
#pragma omp section
			{
				
				Mat srcImage8(dsize, CV_8UC3);
				if (!inputVideo8.read(src1))
					src1 = src2;
				//	inputVideo8.set(CV_CAP_PROP_POS_FRAMES, framecount);
				//	inputVideo8 >> src;              
				//if (srcImage8.empty()) break;
				resize(src1, srcImage8, dsize);
				//srcImage8 = imread("cola_008.bmp");
				image8(pblue, pgreen, pred, srcImage8);


			}
#pragma omp section
			{
				
				Mat srcImage7(dsize, CV_8UC3);
				//inputVideo7.set(CV_CAP_PROP_POS_FRAMES, framecount);
				//inputVideo7 >> src;
				//if (srcImage7.empty()) break;
				if (!inputVideo7.read(src2))
					src2 = src1;
				resize(src2, srcImage7, dsize);
				//srcImage7 = imread("cola_007.bmp");
				image7(pblue, pgreen, pred, srcImage7);
			}
#pragma omp section
			{
				
				Mat srcImage6(dsize, CV_8UC3);
				//inputVideo6.set(CV_CAP_PROP_POS_FRAMES, framecount);
				//inputVideo6 >> src;
				//if (srcImage6.empty()) break;
				if(!inputVideo6.read(src1))
					src1 = src2;
				resize(src1, srcImage6, dsize);
				//srcImage6 = imread("cola_006.bmp");
				image6(pblue, pgreen, pred, srcImage6);
			}
#pragma omp section
			{
				
				Mat srcImage5(dsize, CV_8UC3);
				//inputVideo5.set(CV_CAP_PROP_POS_FRAMES, framecount);
				//inputVideo5 >> src;
				//if (srcImage5.empty()) break;
				if(!inputVideo5.read(src2))
					src2 = src1;
				resize(src2, srcImage5, dsize);
				//srcImage5 = imread("cola_005.bmp");
				image5(pblue, pgreen, pred, srcImage5);
			}
#pragma omp section
			{
				
				Mat srcImage4(dsize, CV_8UC3);
				//inputVideo4.set(CV_CAP_PROP_POS_FRAMES, framecount);
				//inputVideo4 >> src;
				//if (srcImage4.empty()) break;
				if(!inputVideo4.read(src1))
					src1 = src2;
				resize(src1, srcImage4, dsize);
				//srcImage4 = imread("cola_004.bmp");
				image4(pblue, pgreen, pred, srcImage4);
			}
#pragma omp section
			{
				
				Mat srcImage3(dsize, CV_8UC3);
				//inputVideo3.set(CV_CAP_PROP_POS_FRAMES, framecount);
				//inputVideo3 >> src;
				if(!inputVideo3.read(src2))
					src2 = src1;
				//if (srcImage3.empty()) break;
				resize(src2, srcImage3, dsize);
				//srcImage3 = imread("cola_003.bmp");
				image3(pblue, pgreen, pred, srcImage3);
			}
#pragma omp section
			{
				
				Mat srcImage2(dsize, CV_8UC3);
				//inputVideo2.set(CV_CAP_PROP_POS_FRAMES, framecount);
				//inputVideo2>> src;
				//if (srcImage2.empty()) break;
				if(!inputVideo2.read(src1))
					src1 = src2;
				resize(src1, srcImage2, dsize);
				//srcImage2 = imread("cola_002.bmp");
				image2(pblue, pgreen, pred, srcImage2);
			}
#pragma omp section
			{
				
				Mat srcImage1(dsize, CV_8UC3);
				//inputVideo1.set(CV_CAP_PROP_POS_FRAMES, framecount);
				//inputVideo1 >> src;
				//if (srcImage1.empty()) break;
				if(!inputVideo1.read(src2))
					src2 = src1;
				resize(src2, srcImage1, dsize);
				//srcImage1 = imread("cola_001.bmp");
				image1(pblue, pgreen, pred, srcImage1);
			}

		}
		Mat mixture(1080, 1920, CV_8UC3);
		split(mixture, channels);
		for (int i = 0; i < channels[0].rows; i++)
		{
			uchar*data = channels[0].ptr<uchar>(i);//b
			uchar*data1 = channels[1].ptr<uchar>(i);//g
			uchar*data2 = channels[2].ptr<uchar>(i);//r
			uchar*data3 = blue.ptr<uchar>(i);
			uchar*data4 = green.ptr<uchar>(i);
			uchar*data5 = red.ptr<uchar>(i);
			for (int j = 0; j < channels[0].cols; j++)
			{
				data[j] = data3[j];
				data1[j] = data4[j];
				data2[j] = data5[j];

			}
		}
		merge(channels, mixture);
		//imshow(mixture);

		//	namedWindow("wisemore cam preview", 0);
		//	cvResizeWindow("wisemore cam preview", 640, 480);
		imshow("Video2", mixture);
		char c = cvWaitKey(33);
			if (c == 27)break;
		//outputVideo.write(mixture);
		//outputVideo << mixture;

		//imwrite("mixture9.bmp", mixture);
		framecount = framecount + 100;
	}
	return 0;

}


void image8(Mat *pblue, Mat *pgreen, Mat *pred, Mat srcImage8)
{
	//Mat b8(1, 3, CV_8UC1);
	vector<Mat> channels8;
	split(srcImage8, channels8);
	Mat a = channels8[0];
	int j = 0, j1 = 0, j3 = 1, j5 = 1;
	int i1 = 0, i2 = 1, i3 = 2;
	int m = a.rows;
	int n = a.cols - 1;
	int n1 = ((n + 1) / 3 * 8) - 1;
	int n2 = n1;
	int n3 = n2;
	int n4 = n2;
	//uchar*data8 = (*pblue).ptr<uchar>(0);
	//uchar*data81 = a8.ptr<uchar>(0);uchar*data82 = a8.ptr<uchar>(1);uchar*data83 = a8.ptr<uchar>(2);
	//cout << a8 << endl;
#pragma omp parallel sections
	{
#pragma omp section
		{
			Mat b8(1, 3, CV_8UC1);
			Mat a8 = channels8[0];
			uchar*data8 = (*pblue).ptr<uchar>(0);
			uchar*data81 = a8.ptr<uchar>(0); uchar*data82 = a8.ptr<uchar>(1); uchar*data83 = a8.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data81 = a8.ptr<uchar>(j); data82 = a8.ptr<uchar>(j + 1); data83 = a8.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b8.row(0).setTo((data81[n - i], data82[n - i], data83[shu(n - 1 - i, n)]));
					if (j5 % 3 == 1)
					{
						data8 = (*pblue).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data8[shu(n1 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pblue).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data8[shu(n1 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pblue).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data8[shu(n1 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 2)
					{
						data8 = (*pblue).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data8[shu(n4 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pblue).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data8[shu(n4 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pblue).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data8[shu(n4 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 0)
					{
						data8 = (*pblue).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data8[shu(n3 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pblue).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data8[shu(n3 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pblue).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data8[shu(n3 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 0) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b8(1, 3, CV_8UC1);
			Mat a8 = channels8[1];
			uchar*data8 = (*pgreen).ptr<uchar>(0);
			uchar*data81 = a8.ptr<uchar>(0); uchar*data82 = a8.ptr<uchar>(1); uchar*data83 = a8.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data81 = a8.ptr<uchar>(j); data82 = a8.ptr<uchar>(j + 1); data83 = a8.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{

					b8.row(0).setTo((data81[n - i], data82[n - i], data83[n - i]));
					if (j5 % 3 == 2)
					{
						data8 = (*pgreen).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data8[shu(n1 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pgreen).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data8[shu(n1 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pgreen).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data8[shu(n1 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 0)
					{
						data8 = (*pgreen).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data8[shu(n4 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pgreen).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data8[shu(n4 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pgreen).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data8[shu(n4 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 1)
					{
						data8 = (*pgreen).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data8[shu(n3 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pgreen).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data8[shu(n3 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pgreen).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data8[shu(n3 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 0) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b8(1, 3, CV_8UC1);
			Mat a8 = channels8[2];
			uchar*data8 = (*pred).ptr<uchar>(0);
			uchar*data81 = a8.ptr<uchar>(0); uchar*data82 = a8.ptr<uchar>(1); uchar*data83 = a8.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data81 = a8.ptr<uchar>(j); data82 = a8.ptr<uchar>(j + 1); data83 = a8.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b8.row(0).setTo((data81[n - i], data82[n - i], data83[n - i]));
					if (j5 % 3 == 0)
					{
						data8 = (*pred).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data8[shu(n1 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pred).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data8[shu(n1 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pred).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data8[shu(n1 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 1)
					{
						data8 = (*pred).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data8[shu(n4 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pred).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data8[shu(n4 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pred).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data8[shu(n4 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 2)
					{
						data8 = (*pred).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data8[shu(n3 + 1 - j3, n2)] = b8.at<uchar>(0, 0);
						data8 = (*pred).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data8[shu(n3 - j3, n2)] = b8.at<uchar>(0, 1);
						data8 = (*pred).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data8[shu(n3 - 1 - j3, n2)] = b8.at<uchar>(0, 2);

						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 1) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
	}//return (*pblue), (*pgreen), (*pred);
}
void image7(Mat *pblue, Mat *pgreen, Mat *pred, Mat srcImage7)
{
	//Mat b7(1, 3, CV_8UC1);
	vector<Mat> channels7;
	split(srcImage7, channels7);
	Mat a = channels7[0];
	int j = 0, j1 = 0, j3 = 1, j5 = 1;
	int i1 = 0, i2 = 1, i3 = 2;
	int m = a.rows;
	int n = a.cols - 1;
	int n1 = ((n + 1) / 3 * 8) - 1;
	int n2 = n1;
	int n3 = n2;
	int n4 = n2;
	//uchar*data7 = (*pblue).ptr<uchar>(0);
	//cout << srcImage7 << endl;
	//uchar*data71 = a7.ptr<uchar>(0);uchar*data72 = a7.ptr<uchar>(1);uchar*data73 = a7.ptr<uchar>(2);
#pragma omp parallel sections
	{
#pragma omp section
		{
			Mat b7(1, 3, CV_8UC1);
			Mat a7 = channels7[0];
			uchar*data7 = (*pblue).ptr<uchar>(0);
			uchar*data71 = a7.ptr<uchar>(0); uchar*data72 = a7.ptr<uchar>(1); uchar*data73 = a7.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data71 = a7.ptr<uchar>(j); data72 = a7.ptr<uchar>(j + 1); data73 = a7.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b7.row(0).setTo((data71[n - i], data72[n - i], data73[shu(n - 1 - i, n)]));

					if (j5 % 3 == 1)
					{
						data7 = (*pblue).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data7[shu(n4 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pblue).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data7[shu(n4 - 1 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pblue).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data7[shu(n4 - 2 - j3, n2)] = b7.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 2)
					{
						data7 = (*pblue).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data7[shu(n3 + 1 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pblue).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data7[shu(n3 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pblue).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data7[shu(n3 - 1 - j3, n2)] = b7.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 0)
					{
						data7 = (*pblue).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data7[shu(n1 + 1 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pblue).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data7[shu(n1 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pblue).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data7[shu(n1 - 1 - j3, n2)] = b7.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 0) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b7(1, 3, CV_8UC1);
			uchar*data7 = (*pgreen).ptr<uchar>(0);
			Mat a7 = channels7[1];
			uchar*data71 = a7.ptr<uchar>(0); uchar*data72 = a7.ptr<uchar>(1); uchar*data73 = a7.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data71 = a7.ptr<uchar>(j); data72 = a7.ptr<uchar>(j + 1); data73 = a7.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b7.row(0).setTo((data71[n - i], data72[n - i], data73[shu(n - 1 - i, n)]));

					if (j5 % 3 == 2)
					{
						data7 = (*pgreen).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data7[shu(n4 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pgreen).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data7[shu(n4 - 1 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pgreen).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data7[shu(n4 - 2 - j3, n2)] = b7.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 0)
					{
						data7 = (*pgreen).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data7[shu(n3 + 1 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pgreen).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data7[shu(n3 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pgreen).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data7[shu(n3 - 1 - j3, n2)] = b7.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 1)
					{
						data7 = (*pgreen).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data7[shu(n1 + 1 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pgreen).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data7[shu(n1 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pgreen).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data7[shu(n1 - 1 - j3, n2)] = b7.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 0) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b7(1, 3, CV_8UC1);
			uchar*data7 = (*pred).ptr<uchar>(0);
			Mat a7 = channels7[2];
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			uchar*data71 = a7.ptr<uchar>(0); uchar*data72 = a7.ptr<uchar>(1); uchar*data73 = a7.ptr<uchar>(2);
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data71 = a7.ptr<uchar>(j); data72 = a7.ptr<uchar>(j + 1); data73 = a7.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b7.row(0).setTo((data71[n - i], data72[n - i], data73[n - i]));

					if (j5 % 3 == 0)
					{
						data7 = (*pred).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data7[shu(n4 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pred).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data7[shu(n4 - 1 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pred).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data7[shu(n4 - 2 - j3, n2)] = b7.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 1)
					{
						data7 = (*pred).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data7[shu(n3 + 1 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pred).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data7[shu(n3 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pred).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data7[shu(n3 - 1 - j3, n2)] = b7.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 2)
					{
						data7 = (*pred).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data7[shu(n1 + 1 - j3, n2)] = b7.at<uchar>(0, 0);
						data7 = (*pred).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data7[shu(n1 - j3, n2)] = b7.at<uchar>(0, 1);
						data7 = (*pred).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data7[shu(n1 - 1 - j3, n2)] = b7.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 1) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
	}
	//return blue, red, green;
}
void image6(Mat *pblue, Mat *pgreen, Mat *pred, Mat srcImage6)
{
	//Mat b6(1, 3, CV_8UC1);
	vector<Mat> channels6;
	split(srcImage6, channels6);
	Mat a = channels6[0];
	int j = 0, j1 = 0, j3 = 1, j5 = 1;
	int i1 = 0, i2 = 1, i3 = 2;
	int m = a.rows;
	int n = a.cols - 1;
	int n1 = ((n + 1) / 3 * 8) - 1;
	int n2 = n1;
	int n3 = n2;
	int n4 = n2;
	//cout << srcImage6 << endl;
	//uchar*datac = (*pblue).ptr<uchar>(0);
	//uchar*data61 = a6.ptr<uchar>(0);uchar*data62 = a6.ptr<uchar>(1);uchar*data63 = a6.ptr<uchar>(2);
#pragma omp parallel sections
	{
#pragma omp section
		{
			Mat b6(1, 3, CV_8UC1);
			Mat a6 = channels6[0];
			uchar*datac = (*pblue).ptr<uchar>(0);
			uchar*data61 = a6.ptr<uchar>(0); uchar*data62 = a6.ptr<uchar>(1); uchar*data63 = a6.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data61 = a6.ptr<uchar>(j); data62 = a6.ptr<uchar>(j + 1); data63 = a6.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b6.row(0).setTo((data61[n - i], data62[n - i], data63[shu(n - 1 - i, n)]));
					if (j5 % 3 == 1)
					{
						datac = (*pblue).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b6.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
					if (j5 % 3 == 2)
					{
						datac = (*pblue).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 + 1 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b6.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}

					if (j5 % 3 == 0)
					{

						datac = (*pblue).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b6.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
				}
				if ((j5 % 3 == 0) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b6(1, 3, CV_8UC1);
			uchar*datac = (*pgreen).ptr<uchar>(0);
			Mat a6 = channels6[1];
			uchar*data61 = a6.ptr<uchar>(0); uchar*data62 = a6.ptr<uchar>(1); uchar*data63 = a6.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data61 = a6.ptr<uchar>(j); data62 = a6.ptr<uchar>(j + 1); data63 = a6.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b6.row(0).setTo((data61[n - i], data62[n - i], data63[shu(n - 1 - i, n)]));
					if (j5 % 3 == 2)
					{
						datac = (*pgreen).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b6.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
					if (j5 % 3 == 0)
					{
						datac = (*pgreen).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 + 1 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b6.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}

					if (j5 % 3 == 1)
					{

						datac = (*pgreen).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b6.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}

				}
				if ((j5 % 3 == 0) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b6(1, 3, CV_8UC1);
			uchar*datac = (*pred).ptr<uchar>(0);
			Mat a6 = channels6[2];
			uchar*data61 = a6.ptr<uchar>(0); uchar*data62 = a6.ptr<uchar>(1); uchar*data63 = a6.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data61 = a6.ptr<uchar>(j); data62 = a6.ptr<uchar>(j + 1); data63 = a6.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b6.row(0).setTo((data61[n - i], data62[n - i], data63[shu(n - 1 - i, n)]));
					if (j5 % 3 == 0)
					{
						datac = (*pred).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b6.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
					if (j5 % 3 == 1)
					{
						datac = (*pred).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 + 1 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b6.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}

					if (j5 % 3 == 2)
					{

						datac = (*pred).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - j3, n2)] = b6.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b6.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b6.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}

				}
				if ((j5 % 3 == 2) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
	}
	//return blue, red, green;
}
void image5(Mat *pblue, Mat *pgreen, Mat *pred, Mat srcImage5)
{
	//Mat b5(1, 3, CV_8UC1);
	vector<Mat> channels5;
	split(srcImage5, channels5);
	Mat a = channels5[0];
	int j = 0, j1 = 0, j3 = 1, j5 = 1;
	int i1 = 0, i2 = 1, i3 = 2;
	int m = a.rows;
	int n = a.cols - 1;
	int n1 = ((n + 1) / 3 * 8) - 1;
	int n2 = n1;
	int n3 = n2;
	int n4 = n2;
	//cout << srcImage5 << endl;
	//uchar*datac = (*pblue).ptr<uchar>(0);
	//uchar*data51 = a5.ptr<uchar>(0);uchar*data52 = a5.ptr<uchar>(1);uchar*data53 = a5.ptr<uchar>(2);
#pragma omp parallel sections
	{
#pragma omp section
		{
			Mat b5(1, 3, CV_8UC1);
			Mat a5 = channels5[0];
			uchar*datac = (*pblue).ptr<uchar>(0);
			uchar*data51 = a5.ptr<uchar>(0); uchar*data52 = a5.ptr<uchar>(1); uchar*data53 = a5.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data51 = a5.ptr<uchar>(j); data52 = a5.ptr<uchar>(j + 1); data53 = a5.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b5.row(0).setTo((data51[n - i], data52[shu(n - 1 - i, n)], data53[shu(n - 1 - i, n)]));
					if (j5 % 3 == 1)
					{
						datac = (*pblue).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b5.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 2)
					{
						datac = (*pblue).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b5.at<uchar>(0, 2);

						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 0)
					{
						datac = (*pblue).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b5.at<uchar>(0, 2);

						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 0) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b5(1, 3, CV_8UC1);
			uchar*datac = (*pgreen).ptr<uchar>(0);
			Mat a5 = channels5[1];
			uchar*data51 = a5.ptr<uchar>(0); uchar*data52 = a5.ptr<uchar>(1); uchar*data53 = a5.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			//cout << a5 << endl;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data51 = a5.ptr<uchar>(j); data52 = a5.ptr<uchar>(j + 1); data53 = a5.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{

					b5.row(0).setTo((data51[n - i], data52[n - i], data53[shu(n - 1 - i, n)]));
					if (j5 % 3 == 2)
					{
						datac = (*pgreen).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b5.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 0)
					{
						datac = (*pgreen).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b5.at<uchar>(0, 2);

						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 1)
					{
						datac = (*pgreen).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b5.at<uchar>(0, 2);

						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 0) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b5(1, 3, CV_8UC1);
			uchar*datac = (*pred).ptr<uchar>(0);
			Mat a5 = channels5[2];
			uchar*data51 = a5.ptr<uchar>(0); uchar*data52 = a5.ptr<uchar>(1); uchar*data53 = a5.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data51 = a5.ptr<uchar>(j); data52 = a5.ptr<uchar>(j + 1); data53 = a5.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b5.row(0).setTo((data51[n - i], data52[n - i], data53[shu(n - 1 - i, n)]));
					if (j5 % 3 == 0)
					{
						datac = (*pred).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b5.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 1)
					{
						datac = (*pred).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b5.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 2)
					{
						datac = (*pred).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b5.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b5.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b5.at<uchar>(0, 2);

						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 1) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
	}
	//return blue, red, green;
}
void image4(Mat *pblue, Mat *pgreen, Mat *pred, Mat srcImage4)
{
	//Mat b4(1, 3, CV_8UC1);
	vector<Mat> channels4;
	split(srcImage4, channels4);
	Mat a = channels4[0];
	int j = 0, j1 = 0, j3 = 1, j5 = 1;
	int i1 = 0, i2 = 1, i3 = 2;
	int m = a.rows;
	int n = a.cols - 1;
	int n1 = ((n + 1) / 3 * 8) - 1;
	int n2 = n1;
	int n3 = n2;
	int n4 = n2;
	//uchar*datac = (*pblue).ptr<uchar>(0);
	//uchar*data41 = a4.ptr<uchar>(0);uchar*data42 = a4.ptr<uchar>(1);uchar*data43 = a4.ptr<uchar>(2);
#pragma omp parallel sections
	{
#pragma omp section
		{

			Mat b4(1, 3, CV_8UC1);
			Mat a4 = channels4[0];
			uchar*datac = (*pblue).ptr<uchar>(0);
			uchar*data41 = a4.ptr<uchar>(0); uchar*data42 = a4.ptr<uchar>(1); uchar*data43 = a4.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data41 = a4.ptr<uchar>(j); data42 = a4.ptr<uchar>(j + 1); data43 = a4.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b4.row(0).setTo((data41[n - i], data42[shu(n - 1 - i, n)], data43[shu(n - 1 - i, n)]));

					if (j5 % 3 == 1)
					{
						datac = (*pblue).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 3 - j3, n2)] = b4.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 2)
					{
						datac = (*pblue).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b4.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 0)
					{
						datac = (*pblue).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b4.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 0) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b4(1, 3, CV_8UC1);
			uchar*datac = (*pgreen).ptr<uchar>(0);
			Mat a4 = channels4[1];
			uchar*data41 = a4.ptr<uchar>(0); uchar*data42 = a4.ptr<uchar>(1); uchar*data43 = a4.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data41 = a4.ptr<uchar>(j); data42 = a4.ptr<uchar>(j + 1); data43 = a4.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b4.row(0).setTo((data41[n - i], data42[shu(n - 1 - i, n)], data43[shu(n - 1 - i, n)]));

					if (j5 % 3 == 2)
					{
						datac = (*pgreen).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 3 - j3, n2)] = b4.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 0)
					{
						datac = (*pgreen).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b4.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 1)
					{
						datac = (*pgreen).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b4.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 0) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b4(1, 3, CV_8UC1);
			uchar*datac = (*pred).ptr<uchar>(0);
			Mat a4 = channels4[2];
			uchar*data41 = a4.ptr<uchar>(0); uchar*data42 = a4.ptr<uchar>(1); uchar*data43 = a4.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data41 = a4.ptr<uchar>(j); data42 = a4.ptr<uchar>(j + 1); data43 = a4.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b4.row(0).setTo((data41[n - i], data42[n - i], data43[shu(n - 1 - i, n)]));

					if (j5 % 3 == 0)
					{
						datac = (*pred).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 3 - j3, n2)] = b4.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 1)
					{
						datac = (*pred).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b4.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 2)
					{
						datac = (*pred).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b4.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b4.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b4.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 1) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
	}
	//return blue, red, green;
}
void image3(Mat *pblue, Mat *pgreen, Mat *pred, Mat srcImage3)
{
	//Mat b3(1, 3, CV_8UC1);
	vector<Mat> channels3;
	split(srcImage3, channels3);
	Mat a = channels3[0];
	int j = 0, j1 = 0, j3 = 1, j5 = 1;
	int i1 = 0, i2 = 1, i3 = 2;
	int m = a.rows;
	int n = a.cols - 1;
	int n1 = ((n + 1) / 3 * 8) - 1;
	int n2 = n1;
	int n3 = n2;
	int n4 = n2;
	//uchar*datac = (*pblue).ptr<uchar>(0);
	//uchar*data31 = a3.ptr<uchar>(0);uchar*data32 = a3.ptr<uchar>(1);uchar*data33 = a3.ptr<uchar>(2);
#pragma omp parallel sections
	{
#pragma omp section
		{
			Mat b3(1, 3, CV_8UC1);
			Mat a3 = channels3[0];
			uchar*datac = (*pblue).ptr<uchar>(0);
			uchar*data31 = a3.ptr<uchar>(0); uchar*data32 = a3.ptr<uchar>(1); uchar*data33 = a3.ptr<uchar>(2);
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data31 = a3.ptr<uchar>(j); data32 = a3.ptr<uchar>(j + 1); data33 = a3.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b3.row(0).setTo((data31[n - i], data32[shu(n - 1 - i, n)], data33[shu(n - 1 - i, n)]));
					if (j5 % 3 == 1)
					{
						datac = (*pblue).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 3 - j3, n2)] = b3.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
					if (j5 % 3 == 2)
					{
						datac = (*pblue).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b3.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}

					if (j5 % 3 == 0)
					{

						datac = (*pblue).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pblue).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pblue).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 3 - j3, n2)] = b3.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
				}
				if ((j5 % 3 == 0) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b3(1, 3, CV_8UC1);
			uchar*datac = (*pgreen).ptr<uchar>(0);
			Mat a3 = channels3[1];
			uchar*data31 = a3.ptr<uchar>(0); uchar*data32 = a3.ptr<uchar>(1); uchar*data33 = a3.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data31 = a3.ptr<uchar>(j); data32 = a3.ptr<uchar>(j + 1); data33 = a3.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b3.row(0).setTo((data31[n - i], data32[shu(n - 1 - i, n)], data33[shu(n - 1 - i, n)]));
					if (j5 % 3 == 2)
					{
						datac = (*pgreen).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 3 - j3, n2)] = b3.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
					if (j5 % 3 == 0)
					{
						datac = (*pgreen).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b3.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}

					if (j5 % 3 == 1)
					{

						datac = (*pgreen).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pgreen).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pgreen).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 3 - j3, n2)] = b3.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}

				}
				if ((j5 % 3 == 0) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b3(1, 3, CV_8UC1);
			uchar*datac = (*pred).ptr<uchar>(0);
			Mat a3 = channels3[2];
			uchar*data31 = a3.ptr<uchar>(0); uchar*data32 = a3.ptr<uchar>(1); uchar*data33 = a3.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data31 = a3.ptr<uchar>(j); data32 = a3.ptr<uchar>(j + 1); data33 = a3.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b3.row(0).setTo((data31[n - i], data32[shu(n - 1 - i, n)], data33[shu(n - 1 - i, n)]));
					if (j5 % 3 == 0)
					{
						datac = (*pred).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						datac[shu(n3 - 1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						datac[shu(n3 - 2 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						datac[shu(n3 - 3 - j3, n2)] = b3.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
					if (j5 % 3 == 1)
					{
						datac = (*pred).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						datac[shu(n1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						datac[shu(n1 - 1 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						datac[shu(n1 - 2 - j3, n2)] = b3.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}

					if (j5 % 3 == 2)
					{

						datac = (*pred).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						datac[shu(n4 - 1 - j3, n2)] = b3.at<uchar>(0, 0);
						datac = (*pred).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						datac[shu(n4 - 2 - j3, n2)] = b3.at<uchar>(0, 1);
						datac = (*pred).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						datac[shu(n4 - 3 - j3, n2)] = b3.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}

				}
				if ((j5 % 3 == 2) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
	}
	//return blue, red, green;
}
void image2(Mat *pblue, Mat *pgreen, Mat *pred, Mat srcImage2)
{
	//Mat b2(1, 3, CV_8UC1);
	vector<Mat> channels2;
	split(srcImage2, channels2);
	Mat a = channels2[0];
	int j = 0, j1 = 0, j3 = 1, j5 = 1;
	int i1 = 0, i2 = 1, i3 = 2;
	int m = a.rows;
	int n = a.cols - 1;
	int n1 = ((n + 1) / 3 * 8) - 1;
	int n2 = n1;
	int n3 = n2;
	int n4 = n2;
	//uchar*data2 = (*pblue).ptr<uchar>(0);
	//uchar*data21 = a2.ptr<uchar>(0);uchar*data22 = a2.ptr<uchar>(1);uchar*data23 = a2.ptr<uchar>(2);
#pragma omp parallel sections
	{
#pragma omp section
		{
			Mat b2(1, 3, CV_8UC1);
			Mat a2 = channels2[0];
			uchar*data2 = (*pblue).ptr<uchar>(0);
			uchar*data21 = a2.ptr<uchar>(0); uchar*data22 = a2.ptr<uchar>(1); uchar*data23 = a2.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data21 = a2.ptr<uchar>(j); data22 = a2.ptr<uchar>(j + 1); data23 = a2.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b2.row(0).setTo((data21[shu(n - 1 - i, n)], data22[shu(n - 1 - i, n)], data23[shu(n - 1 - i, n)]));
					if (j5 % 3 == 1)
					{
						data2 = (*pblue).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data2[shu(n1 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pblue).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data2[shu(n1 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pblue).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data2[shu(n1 - 3 - j3, n2)] = b2.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 2)
					{
						data2 = (*pblue).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data2[shu(n4 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pblue).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data2[shu(n4 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pblue).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data2[shu(n4 - 3 - j3, n2)] = b2.at<uchar>(0, 2);

						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 0)
					{
						data2 = (*pblue).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data2[shu(n3 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pblue).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data2[shu(n3 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pblue).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data2[shu(n3 - 3 - j3, n2)] = b2.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 0) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b2(1, 3, CV_8UC1);
			uchar*data2 = (*pgreen).ptr<uchar>(0);
			Mat a2 = channels2[1];
			uchar*data21 = a2.ptr<uchar>(0); uchar*data22 = a2.ptr<uchar>(1); uchar*data23 = a2.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data21 = a2.ptr<uchar>(j); data22 = a2.ptr<uchar>(j + 1); data23 = a2.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{

					b2.row(0).setTo((data21[n - i], data22[shu(n - 1 - i, n)], data23[shu(n - 1 - i, n)]));
					if (j5 % 3 == 2)
					{
						data2 = (*pgreen).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data2[shu(n1 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pgreen).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data2[shu(n1 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pgreen).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data2[shu(n1 - 3 - j3, n2)] = b2.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 0)
					{
						data2 = (*pgreen).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data2[shu(n4 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pgreen).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data2[shu(n4 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pgreen).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data2[shu(n4 - 3 - j3, n2)] = b2.at<uchar>(0, 2);

						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 1)
					{
						data2 = (*pgreen).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data2[shu(n3 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pgreen).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data2[shu(n3 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pgreen).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data2[shu(n3 - 3 - j3, n2)] = b2.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 0) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b2(1, 3, CV_8UC1);
			uchar*data2 = (*pred).ptr<uchar>(0);
			Mat a2 = channels2[2];
			uchar*data21 = a2.ptr<uchar>(0); uchar*data22 = a2.ptr<uchar>(1); uchar*data23 = a2.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data21 = a2.ptr<uchar>(j); data22 = a2.ptr<uchar>(j + 1); data23 = a2.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b2.row(0).setTo((data21[n - i], data22[shu(n - 1 - i, n)], data23[shu(n - 1 - i, n)]));
					if (j5 % 3 == 0)
					{
						data2 = (*pred).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data2[shu(n1 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pred).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data2[shu(n1 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pred).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data2[shu(n1 - 3 - j3, n2)] = b2.at<uchar>(0, 2);

						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
					if (j5 % 3 == 1)
					{
						data2 = (*pred).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data2[shu(n4 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pred).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data2[shu(n4 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pred).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data2[shu(n4 - 3 - j3, n2)] = b2.at<uchar>(0, 2);

						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}

					}
					if (j5 % 3 == 2)
					{
						data2 = (*pred).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data2[shu(n3 - 1 - j3, n2)] = b2.at<uchar>(0, 0);
						data2 = (*pred).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data2[shu(n3 - 2 - j3, n2)] = b2.at<uchar>(0, 1);
						data2 = (*pred).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data2[shu(n3 - 3 - j3, n2)] = b2.at<uchar>(0, 2);

						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}
				}
				if ((j5 % 3 == 1) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
	}
	//return blue, red, green;
}
void image1(Mat *pblue, Mat *pgreen, Mat *pred, Mat srcImage1)
{
	//Mat b1(1, 3, CV_8UC1);
	vector<Mat> channels1;
	split(srcImage1, channels1);
	Mat a = channels1[0];
	int j = 0, j1 = 0, j3 = 1, j5 = 1;
	int i1 = 0, i2 = 1, i3 = 2;
	int m = a.rows;
	int n = a.cols - 1;
	int n1 = ((n + 1) / 3 * 8) - 1;
	int n2 = n1;
	int n3 = n2;
	int n4 = n2;
	//uchar*data1 = (*pblue).ptr<uchar>(0);
	//uchar*data11 = a1.ptr<uchar>(0);uchar*data12 = a1.ptr<uchar>(1);uchar*data13 = a1.ptr<uchar>(2);
#pragma omp parallel sections
	{
#pragma omp section
		{
			Mat b1(1, 3, CV_8UC1);
			Mat a1 = channels1[0];
			uchar*data1 = (*pblue).ptr<uchar>(0);
			uchar*data11 = a1.ptr<uchar>(0); uchar*data12 = a1.ptr<uchar>(1); uchar*data13 = a1.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data11 = a1.ptr<uchar>(j); data12 = a1.ptr<uchar>(j + 1); data13 = a1.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b1.row(0).setTo((data11[shu(n - 1 - i, n)], data12[shu(n - 1 - i, n)], data13[shu(n - 1 - i, n)]));

					if (j5 % 3 == 1)
					{
						data1 = (*pblue).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data1[shu(n4 - 2 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pblue).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data1[shu(n4 - 3 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pblue).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data1[shu(n4 - 4 - j3, n2)] = b1.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 2)
					{
						data1 = (*pblue).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data1[shu(n3 - 1 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pblue).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data1[shu(n3 - 2 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pblue).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data1[shu(n3 - 3 - j3, n2)] = b1.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 0)
					{
						data1 = (*pblue).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data1[shu(n1 - 1 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pblue).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data1[shu(n1 - 2 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pblue).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data1[shu(n1 - 3 - j3, n2)] = b1.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 0) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b1(1, 3, CV_8UC1);
			uchar*data1 = (*pgreen).ptr<uchar>(0);
			Mat a1 = channels1[1];
			uchar*data11 = a1.ptr<uchar>(0); uchar*data12 = a1.ptr<uchar>(1); uchar*data13 = a1.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data11 = a1.ptr<uchar>(j); data12 = a1.ptr<uchar>(j + 1); data13 = a1.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b1.row(0).setTo((data11[shu(n - 1 - i, n)], data12[shu(n - 1 - i, n)], data13[shu(n - 1 - i, n)]));

					if (j5 % 3 == 2)
					{
						data1 = (*pgreen).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data1[shu(n4 - 2 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pgreen).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data1[shu(n4 - 3 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pgreen).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data1[shu(n4 - 4 - j3, n2)] = b1.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 0)
					{
						data1 = (*pgreen).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data1[shu(n3 - 1 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pgreen).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data1[shu(n3 - 2 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pgreen).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data1[shu(n3 - 3 - j3, n2)] = b1.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 1)
					{
						data1 = (*pgreen).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data1[shu(n1 - 1 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pgreen).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data1[shu(n1 - 2 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pgreen).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data1[shu(n1 - 3 - j3, n2)] = b1.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 0) || (j5 % 3 == 1))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
#pragma omp section
		{
			Mat b1(1, 3, CV_8UC1);
			uchar*data1 = (*pred).ptr<uchar>(0);
			Mat a1 = channels1[2];
			uchar*data11 = a1.ptr<uchar>(0); uchar*data12 = a1.ptr<uchar>(1); uchar*data13 = a1.ptr<uchar>(2);
			j = 0, j1 = 0, j3 = 1, j5 = 1;
			for (int j2 = 0; (j2 + 3) <= m; j2 = j2 + 3)
			{
				data11 = a1.ptr<uchar>(j); data12 = a1.ptr<uchar>(j + 1); data13 = a1.ptr<uchar>(j + 2);
				for (int i = 0; i < (n + 1); i++)
				{
					b1.row(0).setTo((data11[n - i], data12[shu(n - 1 - i, n)], data13[shu(n - 1 - i, n)]));

					if (j5 % 3 == 0)
					{

						data1 = (*pred).ptr<uchar>(range(i3 + j1, 9 + j1, 9));
						data1[shu(n4 - 2 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pred).ptr<uchar>(range(i3 + 3 + j1, 9 + j1, 9));
						data1[shu(n4 - 3 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pred).ptr<uchar>(range(i3 + 6 + j1, 9 + j1, 9));
						data1[shu(n4 - 4 - j3, n2)] = b1.at<uchar>(0, 2);
						i3 = i3 + 1;
						n4 = n4 - 3;
						if (range(i3 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i3 = 0;
							n4 = n4 + 1;
						}
					}
					if (j5 % 3 == 1)
					{
						data1 = (*pred).ptr<uchar>(range(i2 + j1, 9 + j1, 9));
						data1[shu(n3 - 1 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pred).ptr<uchar>(range(i2 + 3 + j1, 9 + j1, 9));
						data1[shu(n3 - 2 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pred).ptr<uchar>(range(i2 + 6 + j1, 9 + j1, 9));
						data1[shu(n3 - 3 - j3, n2)] = b1.at<uchar>(0, 2);
						i2 = i2 + 1;
						n3 = n3 - 3;
						if (range(i2 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i2 = 0;
							n3 = n3 + 1;
						}
					}

					if (j5 % 3 == 2)
					{
						data1 = (*pred).ptr<uchar>(range(i1 + j1, 9 + j1, 9));
						data1[shu(n1 - 1 - j3, n2)] = b1.at<uchar>(0, 0);
						data1 = (*pred).ptr<uchar>(range(i1 + 3 + j1, 9 + j1, 9));
						data1[shu(n1 - 2 - j3, n2)] = b1.at<uchar>(0, 1);
						data1 = (*pred).ptr<uchar>(range(i1 + 6 + j1, 9 + j1, 9));
						data1[shu(n1 - 3 - j3, n2)] = b1.at<uchar>(0, 2);
						i1 = i1 + 1;
						n1 = n1 - 3;
						if (range(i1 + 5 + j1, 9 + j1, 9) == (8 + j1))
						{
							i1 = 0;
							n1 = n1 + 1;
						}
					}
				}

				if ((j5 % 3 == 1) || (j5 % 3 == 2))
				{
					j3 = j3 - 1;
				}
				j5 = j5 + 1;
				j = j + 3;
				j1 = j1 + 9;
				j3 = j3 + 1;
				i1 = 0; i2 = 1; i3 = 2;
				n3 = n2;
				n4 = n2;
				n1 = n2;
			}
		}
	}
	//return blue, red, green;
}