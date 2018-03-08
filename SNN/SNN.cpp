#include "stdafx.h"
#include "Network.h"
#include "Utils.h"
#include <Windows.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	vector<vector<double>> arr = vector<vector<double>>(20);

	LARGE_INTEGER beginTime;
	QueryPerformanceCounter(&beginTime);
	auto n = Network();
	//n.Train(10, 60000);
	n.ImportData();

	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);
	LARGE_INTEGER timerFreq;
	QueryPerformanceFrequency(&timerFreq);
	double freq = 1.0f / timerFreq.QuadPart;

	double timeSeconds = (endTime.QuadPart - beginTime.QuadPart) * freq;
	cout << "\n\nTraining time: " << timeSeconds << endl;

	auto d = Utils::GetTestData(1000);
	
	int correct = 0;
	for (int i = 0; i < 1000; ++i) 
	{
		auto res = n.Run(d[i].first);
		cout << "Predicted: " << (int)res << "\tWas: " << (int)d[i].second << endl;
		if (((int)res) == ((int)d[i].second))
			correct++;
	}

	cout << "\n" << correct << "/1000 images predicted correctly";

	QueryPerformanceCounter(&endTime);
	QueryPerformanceFrequency(&timerFreq);
	freq = 1.0f / timerFreq.QuadPart;
	timeSeconds = (endTime.QuadPart - beginTime.QuadPart) * freq;
	cout << "\n\nended: " << timeSeconds << endl;
	getchar();
	return 0;
}