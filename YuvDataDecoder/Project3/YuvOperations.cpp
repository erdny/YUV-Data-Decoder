#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include "YuvOperations.h"

using namespace std;
using namespace yops;
using namespace cv;

formats yops::setFormats(std::string value)
{
	if (value.compare("444") == 0)
		return format_444;
	else if (value.compare("422") == 0)
		return format_422;
	else if (value.compare("420") == 0)
		return format_420;
}


YuvOps::YuvOps(string directory, string fileName, string format, int width, int height)
{
	this->directory = directory;
	this->fileName = fileName;
	this->format = format;
	this->width = width;
	this->heigth = height;
	setFile();
	setFrameLimit();
	delay = 30;

}

void YuvOps::setSaveDirectory(string saveDirectory)
{
	this->saveDirectory = saveDirectory + "\\";
}
void YuvOps::setFormat(string format)
{
	this->format = format;
}
void YuvOps::setFileName(string fileName)
{
	this->fileName = fileName;
}
void YuvOps::saveStatus(bool status)
{
	saveFlag = status;

}
void YuvOps::setDirectory(string directory)
{
	this->directory = directory;

}
void YuvOps::setFrameLimit()
{
	switch (setFormats(format))
	{
	case format_444:
		frameLimit = width * heigth;
		break;
	case format_422:
		frameLimit = width * heigth / 2;
		break;
	case format_420:
		frameLimit = width * heigth / 4;
		break;
	}
}
void YuvOps::setFile()
{
	string str = directory + fileName;
	file = fopen(str.c_str(), "rb");
}
void YuvOps::start()
{
	const int resolution = width * heigth;

	if (saveFlag)
	{
		for (int frameCounter = 0; !feof(file); frameCounter++)
		{
			IplImage *py = cvCreateImage(cvSize(width, heigth), IPL_DEPTH_8U, 1);

			for (int i = 0; i < resolution; i++)
			{

				int temp = fgetc(file);
				py->imageData[i] = (unsigned char)temp;

			}
			for (int j = 0; j < frameLimit; j++)
			{
				int temp = fgetc(file);
			}
			for (int j = 0; j < frameLimit; j++)
			{
				int temp = fgetc(file);
			}

			cvShowImage("YUV_Player", py);

			stringstream str;

			str << frameCounter;

			const string image = saveDirectory + "frame" + str.str() + ".bmp";

			imwrite(image, cvarrToMat(py));

			

			if (cvWaitKey(delay) >= 0)
				break;
			cvReleaseImage(&py);

			if (!exitFlag) {
				cvDestroyAllWindows();
				break;
			}

			if(!pauseFlag){
				if (continueFlag) {
					pauseFlag = true;
				}
				else {
					cvWaitKey(0);
				}
			}
			
		}
	}
	else
	{
		for (int frameCounter = 0; !feof(file); frameCounter++)
		{
			IplImage *py = cvCreateImage(cvSize(width, heigth), IPL_DEPTH_8U, 1);

			for (int i = 0; i < resolution; i++)
			{

				int temp = fgetc(file);
				py->imageData[i] = (unsigned char)temp;

			}
			for (int j = 0; j < frameLimit; j++)
			{
				int temp = fgetc(file);
			}
			for (int j = 0; j < frameLimit; j++)
			{
				int temp = fgetc(file);
			}
			cvShowImage("YUV_Player", py);

			if (cvWaitKey(delay) >= 0)
				break;

			cvReleaseImage(&py);
		}
	}

}
void YuvOps::setDelay(int delay)
{
	this->delay = delay;
}
bool YuvOps::exitFlag = true;
bool YuvOps::pauseFlag = true;
bool YuvOps::continueFlag = false;

