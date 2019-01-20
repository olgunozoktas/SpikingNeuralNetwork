#include "stdafx.h"
#include "Network.h"
#include "Utils.h"
#include <time.h>	
#include <opencv2/opencv.hpp>
#include "TrainingPool.h"
#include "Random.h"

using namespace cv;
using namespace std;
/*! \file */

/**
This is where your program should be written
*/
int main(int argc, char** argv)
{
	Random::InitLFSR();
	srand(time(NULL));

	//create a network
	/*auto n = Network();
	n.Train<0>(5, 60000);
	n.ExportFile();*/
	auto n = Network();
	n.ImportFile();
	for(auto i = 0; i< 10; ++i)
	n.Validate<0>();

	getchar();
	return 0;
}