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

	//create a network
	auto n = Network();

	n.ImportFile();
	//only train on the first 5 digits
	n.Validate<0>(10000, true, nullptr, 0, true);

	for(int i = 0; i < 10; ++i)
		n.Validate<0>();

	getchar();
	return 0;
}