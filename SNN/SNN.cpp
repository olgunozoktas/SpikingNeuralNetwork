#include "stdafx.h"
#include "Network.h"
#include "Utils.h"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	auto n = Network();
	n.Run(Utils::GetTrainingData(1)[0].first);

	return 0;
}