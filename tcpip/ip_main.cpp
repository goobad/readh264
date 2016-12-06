
//#include "stdafx.h"
#include <stdio.h>
//#include "opencv2/imgproc/imgproc_c.h"
//#include "opencv2/videoio/videoio_c.h"
//#include "opencv2/highgui/highgui_c.h"
//#include "opencv2/core/utility.hpp"
//#include <opencv2/opencv.hpp>
#include "cv.h"
#include "objdetect/objdetect.hpp"
#include "highgui/highgui.hpp"
#include "imgproc/imgproc.hpp"
#include <cctype>
#include<Windows.h>
#include <iterator>
#include <iostream>
//#include <vector>
using namespace std;
using namespace cv;

int main(int argc, const char* argv[])
{
//	const std::string videoStreamAddress = "rtsp://192.168.1.111:554/stream1.h264";
	const std::string videoStreamAddress = "rtsp://admin:a1234567@192.168.1.64:554/h264/ch1/main/av_stream";
//	const std::string videoStreamAddress2 = "rtsp://SCU:SCU-DM8168@192.168.1.65:554/h264/ch1/main/av_stream";
//	const std::string videoStreamAddress = "rtsp://admin:a1234567@192.168.1.66";
//	const std::string videoStreamAddress = "rtsp://192.168.1.110/stream1.h264";
	String filename;
	std::cout << "正在检测摄像头..." << std::endl;
	VideoCapture cap;
	cv::Mat image;
	//if(!cap.isOpened())
	//	std::cout << "无法检测到摄像头1" << std::endl;
	//else
	//	std::cout << "摄像头1运行正常" << std::endl;
	//while (1);
	if (!cap.open(videoStreamAddress)) {
		std::cout << "无法检测到摄像头1" << std::endl;
		system("Pause");
		return -1;
	}
	else 
		std::cout << "摄像头1运行正常" << std::endl;

	cv::namedWindow("Output Window");

	/*
	for (;;) {
		if (!cap.read(image)) {
			std::cout << "No frame" << std::endl;
			cv::waitKey();
		}
		cv::imshow("Output Window", image);
		if (cv::waitKey(1) >= 0) break;
	}
*/
	IplImage  img;
	int cnt = 0, cnt2 = 0;;
	for (;;) {
		if (!cap.read(image)) {
			std::cout << "No frame" << std::endl;
			//cv::waitKey();
			continue;
		}
		cnt++;
		cv::imshow("Output Window", image);
		if ((cnt % 5) == 0)
		{
				
			img = image;
			cnt2++;
			filename = "D:/left/thrD";
			filename += '0' + cnt2 % 1000 / 100;
			filename += '0' + (cnt2 / 10 % 10);
			filename += '0' + (cnt2 % 10);
			filename += ".jpg";
			cout << filename << endl;
			cvSaveImage(filename.c_str(),&img);
		}
		if (cv::waitKey(1) >= 0) break;
		//cv::imshow("Output", image);
		
		
	}
	return 0;
}