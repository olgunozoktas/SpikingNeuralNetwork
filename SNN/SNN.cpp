#include "stdafx.h"
#include "Network.h"
#include "Utils.h"
#include <Windows.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	LARGE_INTEGER beginTime;
	QueryPerformanceCounter(&beginTime);
	auto n = Network();
	auto d = Utils::GetTrainingData(10000);
	
	int correct = 0;
	for (int i = 0; i < 10000; ++i) 
	{
		auto res = n.Run(d[i].first);
		//cout << "Predicted: " << (int)res << "\tWas: " << (int)d[i].second << endl;
		if (((int)res) == ((int)d[i].second))
			correct++;
	}

	cout << "\n" << correct << "/100 images predicted correctly";

	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);
	LARGE_INTEGER timerFreq;
	QueryPerformanceFrequency(&timerFreq);
	const double freq = 1.0f / timerFreq.QuadPart;

	const double timeSeconds = (endTime.QuadPart - beginTime.QuadPart) * freq;
	cout << "ended: " << timeSeconds << endl;
	getchar();
	return 0;
}