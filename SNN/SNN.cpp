#include "stdafx.h"
#include "Network.h"
#include "Utils.h"
#include <time.h>	
#include <opencv2/opencv.hpp>
#include "TrainingPool.h"

using namespace cv;
using namespace std;
/*! \file */

/**
This is where your program should be written
*/
int main(int argc, char** argv)
{
	srand(time(NULL));

	array<bool, 10> var = { 1,0,1,1,0,1,0,1,1,0	};
	array<int, 2> tap = { 9, 2 };

	auto result = Utils::LFSR(var, tap);

	/*//create a network
	auto n = Network();

	n.ImportFile();
	//n.ImportData("quantizationData.db");
	for(int i = 0; i < 10; ++i)
		n.Validate<0>();*/

	Utils::PrintLine("Done");
	getchar();
	return 0;
}