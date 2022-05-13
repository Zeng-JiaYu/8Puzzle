#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include "ImgPuzzles.h"

using namespace std;
using namespace cv;

//����ͼƬ·��
String file = "example.jpg";

int main(int argc, char** argv) {

	try
	{
		Mat src = imread(file);

		if (src.empty()) {
			cout << "ͼ�����ʧ��" << endl;
			waitKey(0);
			return -1;
		}

		//����ͼ�����ŵ�500*500
		Mat tmpsrc;
		resize(src, tmpsrc, Size(500, 500));

		//��ȡͼ��ָ��ļ���
		ImgPuzzles::SplitMats(tmpsrc);

		//����ͼ��
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