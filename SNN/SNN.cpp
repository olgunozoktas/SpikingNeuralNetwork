#include "stdafx.h"
#include "Network.h"
#include "Utils.h"
#include <time.h>	
#include <opencv2/opencv.hpp>
#include "Random.h"

using namespace cv;
using namespace std;
/*! \file */

/**
This is where your program should be written
*/
int main(int argc, char** argv)
{
	srand(time(NULL));
	string tmp = "echo \"\" > " + BASE_NAME + "_results.csv";
	system(tmp.c_str());
	//Random::InitLFSR();

	//create a network
	auto n = Network();

	n.TrainVal(200, 1000, 1000, true);
	//n.ImportData("quantizationData.db");
	n.ExportFile();

	Utils::PrintLine("Done");
	getchar();
	return 0;
}