#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include "ImgPuzzles.h"

using namespace std;
using namespace cv;

//设置图片路径
String file = "example.jpg";

int main(int argc, char** argv) {

	try
	{
		Mat src = imread(file);

		if (src.empty()) {
			cout << "图像加载失败" << endl;
			waitKey(0);
			return -1;
		}

		//设置图像缩放到500*500
		Mat tmpsrc;
		resize(src, tmpsrc, Size(500, 500));

		//获取图像分割后的集合
		ImgPuzzles::SplitMats(tmpsrc);

		//绘制图像
		ImgPuzzles::CreatePuzzleMat();

		cv::waitKey(0);
		return 0;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cv::waitKey(0);
		return -1;
	}
}