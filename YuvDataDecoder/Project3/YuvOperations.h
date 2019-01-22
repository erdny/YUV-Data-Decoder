#pragma once
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <msclr\marshal_cppstd.h>

#ifndef YuvOperations_H
using namespace std;
namespace yops
{
	enum formats
	{
		format_444,
		format_422,
		format_420
	};

	formats setFormats(std::string  value);

	class YuvOps
	{
	private:
		string directory;
		string fileName;
		FILE* file;
		bool saveFlag = false;
		string format;
		string saveDirectory;
		int width;
		int heigth;
		int delay;
		int frameLimit;
		void setFrameLimit();
		void setFile();
	public:
		static bool exitFlag;
		static bool pauseFlag;
		static bool continueFlag;
		void saveStatus(bool status);
		void setDirectory(string directory);
		void setFileName(string fileName);
		void setFormat(string format);
		void setSaveDirectory(string saveDirectory);
		YuvOps(string directory, string fileName, string format, int w, int h);
		void start();
		void setDelay(int delay);
	};

}

#endif // !YuvOperations_H


