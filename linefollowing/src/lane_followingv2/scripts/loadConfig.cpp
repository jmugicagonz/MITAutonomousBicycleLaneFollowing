#include <iostream>
#include <fstream>
#include <string>


#include <opencv2/opencv.hpp>
#include "utils/common.h"
#include "utils/Helper.h"
#include "utils/HelperXML.h"


#define NUM_PARTICLES 400
#define HOUGH_ONLY false
#define USAR_ALTURA true
#define IMG_QUALITY 1

using namespace std;
using namespace cv;

ConfigXML *config;


int exit(string message = "", int retorno = EXIT_FAILURE);



//int main(int argc, char * argv[]) {
int main(){

	string dataset_name = "sample.xml";

	// set global config
	config = new ConfigXML();
	config->numParticles = NUM_PARTICLES;
	string path_xml_configurations = "./utils/config.xml";
	cout << path_xml_configurations << endl;

	// load dataset specific config file
	if (!loadDatasetConfig(path_xml_configurations, *config)) return exit("Error loading dataset config file!");



	// inicializa o XML de sa�da
	Size frameSize = Size(config->camera.FrameSize.width, config->camera.FrameSize.height);
	OutputXML xml = createOutputXML(frameSize);
	vector<int> saida_y = {
		config->roi.y,
		config->roi.y + (int)ceil((float)config->roi.height / 4.0),
		config->roi.y + (int)ceil((float)config->roi.height / 2.0),
		config->roi.y + config->roi.height - 1
		};
		
}

int exit(string message, int retorno) {
	cout << endl << message << endl;
	cout << "Exiting..." << endl << endl;
	return retorno;
}


