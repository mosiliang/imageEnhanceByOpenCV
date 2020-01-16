#pragma once
#include <cv.h>
#include <core\core.hpp>
#include <highgui.h>
#include <opencv2\opencv.hpp>
using namespace cv;

class openCv
{
public:
	openCv() {};
	~openCv() {};
	Mat transLookup(Mat img, int threshold);
	Mat bilateral(Mat img);
	Mat laplacianSharpen(Mat img);
	Mat medianFilter(Mat img);
	Mat enhanceContrast(Mat img);
};


Mat openCv::bilateral(Mat img)
{
	Mat FilterOut;
	bilateralFilter(img, FilterOut, 10, 10 * 2, 100);
	return FilterOut;
}

Mat openCv::laplacianSharpen(Mat img)
{
	Mat laplacianFilter, imgChannel[3];
	split(img, imgChannel);
	for (int i = 0; i < 3; ++i)
	{
		Laplacian(imgChannel[i], imgChannel[i], 8, 1, 10);
	}
	merge(imgChannel, 3, laplacianFilter);
	return img - laplacianFilter;
}

Mat openCv::medianFilter(Mat img)
{
	Mat medianOut;
	medianBlur(img, medianOut, 3);
	return medianOut;
}

inline Mat openCv::enhanceContrast(Mat img)
{
	Mat contrastOut;
	Mat kernal = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(img, contrastOut, img.depth(), kernal);
	return contrastOut;
}

Mat openCv::transLookup(Mat img, int threshold)
{
	//��һ�� ����Ҷ�ͼ���ֱ��ͼ
	const int channels[1] = { 0 };
	const int histSize[1] = { 256 };
	float hranges[2] = { 0, 255 };
	const float *ranges[1] = { hranges };
	MatND hist;
	calcHist(&img, 1, channels, Mat(), hist,
		1, histSize, ranges);
	//�ڶ��� ����Ԥ�����ͳ�ƻҶȼ��任
	//�ɵ͵��߽��в���
	int iLow = 0;
	for (; iLow < histSize[0]; iLow++)
	{
		if (hist.at<float>(iLow)>threshold)
			break;
	}
	//�ɸߵ��׽��в���
	int iHigh = histSize[0] - 1;
	for (; iHigh >= 0; iHigh--)
	{
		if (hist.at<float>(iHigh) > threshold)
			break;
	}
	//������ �������ұ�
	Mat lookUpTable(Size(1, 256), CV_8U);
	for (int i = 0; i < 256; i++)
	{
		if (i < iLow)
		{
			lookUpTable.at<uchar>(i) = 0;
		}
		else if (i>iHigh)
		{
			lookUpTable.at<uchar>(i) = 255;
		}
		else
		{
			lookUpTable.at<uchar>(i) = static_cast<uchar>(
				255.0*(i - iLow) / (iHigh - iLow + 0.5));
		}
	}

	//���Ĳ���ͨ�����ұ����ӳ��任
	Mat histTransResult;
	LUT(img, lookUpTable, histTransResult);

	return histTransResult;
}

