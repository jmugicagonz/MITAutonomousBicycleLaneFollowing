#include "lane_followingv2/HelperXML.h"
#include "lane_followingv2/tinyxml2.h"

using namespace std;

bool loadDatasetConfig(const string &filepath, ConfigXML &outConfigXML) {

	cout << "Charging ConfigXML... \n";
	
	// If problems are found opening the file, it returns false
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError error = doc.LoadFile(filepath.c_str());
	if (error != tinyxml2::XML_NO_ERROR) {
		cout << "ERROR!" << endl;
		return false;
	}

	// paste method configs
	tinyxml2::XMLElement* configTag = doc.FirstChildElement("config");
	outConfigXML.verbose = (strcmp(configTag->FirstChildElement("verbose")->GetText(), "true") == 0);
	outConfigXML.display = (strcmp(configTag->FirstChildElement("display_images")->GetText(), "true") == 0);
	outConfigXML.numParticles = configTag->FirstChildElement("particle_filter")->IntAttribute("num");

	// paste rest of configs (camera)
	tinyxml2::XMLElement* camera = doc.FirstChildElement()->FirstChildElement("camera");
	outConfigXML.camera.name = camera->Attribute("name");
	outConfigXML.camera.FrameSize.width = camera->FirstChildElement("frame_size")->IntAttribute("width");
	outConfigXML.camera.FrameSize.height = camera->FirstChildElement("frame_size")->IntAttribute("height");
	outConfigXML.camera._ROI.x = camera->FirstChildElement("region_of_interest")->IntAttribute("x");
	outConfigXML.camera._ROI.y = camera->FirstChildElement("region_of_interest")->IntAttribute("y");
	outConfigXML.camera._ROI.width = camera->FirstChildElement("region_of_interest")->IntAttribute("width");
	outConfigXML.camera._ROI.height = camera->FirstChildElement("region_of_interest")->IntAttribute("height");
	outConfigXML.camera._IPM.tr = camera->FirstChildElement("ipm_points")->IntAttribute("top_right");
	outConfigXML.camera._IPM.tl = camera->FirstChildElement("ipm_points")->IntAttribute("top_left");
	outConfigXML.camera._IPM.br = camera->FirstChildElement("ipm_points")->IntAttribute("bottom_right");
	outConfigXML.camera._IPM.bl = camera->FirstChildElement("ipm_points")->IntAttribute("bottom_left");

	// Construction of IPM and ROI
	//setROI(outConfigXML);
	//setIPM(outConfigXML);

	cout << "LOADED!" << endl;

	return true;
}



void setIPM(ConfigXML &_config) {

	// The 4 points of the origin image
	vector<Point2f> origPoints;
	origPoints.push_back(Point2f(static_cast<float>(_config.camera._IPM.tl), 0));
	origPoints.push_back(Point2f(static_cast<float>(_config.camera._IPM.tr), 0));
	origPoints.push_back(Point2f(static_cast<float>(_config.camera._IPM.br), static_cast<float>(_config.camera._ROI.height)));
	origPoints.push_back(Point2f(static_cast<float>(_config.camera._IPM.bl), static_cast<float>(_config.camera._ROI.height)));

	// The 4 points of the destiny image
	vector<Point2f> dstPoints;
	dstPoints.push_back(Point2f(static_cast<float>(_config.camera._IPM.tl), 0));
	dstPoints.push_back(Point2f(static_cast<float>(_config.camera._IPM.tr), 0));
	dstPoints.push_back(Point2f(static_cast<float>(_config.camera._IPM.tr), static_cast<float>(_config.camera._ROI.height)));
	dstPoints.push_back(Point2f(static_cast<float>(_config.camera._IPM.tl), static_cast<float>(_config.camera._ROI.height)));

	// calcula o vp
	Point2f tl, tr, br, bl;
	tl = Point2f(static_cast<float>(_config.camera._IPM.tl), static_cast<float>(_config.camera._ROI.y));
	tr = Point2f(static_cast<float>(_config.camera._IPM.tr), static_cast<float>(_config.camera._ROI.y));
	br = Point2f(static_cast<float>(_config.camera._IPM.br), static_cast<float>(_config.camera._ROI.y + _config.camera._ROI.height));
	bl = Point2f(static_cast<float>(_config.camera._IPM.bl), static_cast<float>(_config.camera._ROI.y + _config.camera._ROI.height));
	lineIntersection(bl, tl, br, tr, _config.camera._IPM.vp);

	// objeto IPM -FALTA PONERLO BIEN-
	//_config.ipm = new IPM(Size(_config.roi.size().width, _config.roi.size().height), Size(_config.roi.size().width, _config.roi.size().height), origPoints, dstPoints);
}

// Finds the intersection of two lines, or returns false.
// The lines are defined by (o1, p1) and (o2, p2).
//http://stackoverflow.com/a/7448287/4228275
bool lineIntersection(Point2f o1, Point2f p1, Point2f o2, Point2f p2, Point2f &r) {
	Point2f x = o2 - o1;
	Point2f d1 = p1 - o1;
	Point2f d2 = p2 - o2;

	float cross = d1.x*d2.y - d1.y*d2.x;
	if (abs(cross) < /*EPS*/1e-8) return false;

	double t1 = (x.x * d2.y - x.y * d2.x) / cross;
	r = o1 + d1 * t1;
	return true;
}

void setROI(ConfigXML &_config) {
	_config.roi = Rect(_config.camera._ROI.x, _config.camera._ROI.y, _config.camera._ROI.width, _config.camera._ROI.height);
}

/*IPM * AtualizaIPMLivre(ConfigXML &_config, Point2f vp, bool verbose) {

	double tempoInicio = static_cast<double>(getTickCount());

	// calcula equa��o da reta da faixa da esquerda
	Point2f bottom_left = Point2f(static_cast<float>(_config.dataset._IPM.bl), static_cast<float>(_config.dataset._ROI.y + _config.dataset._ROI.height));
	float esquerda_delta_x = vp.x - bottom_left.x;
	float esquerda_delta_y = vp.y - bottom_left.y;
	float esquerda_slope = esquerda_delta_y / esquerda_delta_x;
	float esquerda_intercept = bottom_left.y - esquerda_slope * bottom_left.x;

	// calcula equa��o da reta da faixa da esquerda
	Point2f bottom_right = Point2f(static_cast<float>(_config.dataset._IPM.br), static_cast<float>(_config.dataset._ROI.y + _config.dataset._ROI.height));
	float direita_delta_x = vp.x - bottom_right.x;
	float direita_delta_y = vp.y - bottom_right.y;
	float direita_slope = direita_delta_y / direita_delta_x;
	float direita_intercept = bottom_right.y - direita_slope * bottom_right.x;

	// calcula os novos pontos superiores
	float novo_tl = (_config.dataset._ROI.y - esquerda_intercept) / esquerda_slope;
	float novo_tr = (_config.dataset._ROI.y - direita_intercept) / direita_slope;

	// os 4 pontos da imagem de origem
	vector<Point2f> origPoints;
	origPoints.push_back(Point2f(static_cast<float>(novo_tl), 0));
	origPoints.push_back(Point2f(static_cast<float>(novo_tr), 0));
	origPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.br), static_cast<float>(_config.dataset._ROI.height)));
	origPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.bl), static_cast<float>(_config.dataset._ROI.height)));

	// os 4 pontos da imagem de destino
	vector<Point2f> dstPoints;
	dstPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.tl), 0));
	dstPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.tr), 0));
	dstPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.tr), static_cast<float>(_config.dataset._ROI.height)));
	dstPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.tl), static_cast<float>(_config.dataset._ROI.height)));

	// calcula o tempo de execu��o
	double tempoFim = static_cast<double>(getTickCount());
	double tempoExecutando = ((tempoFim - tempoInicio) / getTickFrequency()) * 1000;

	// exibe as sa�das definidas (texto e/ou imagem)
	if (verbose) cout << "- atualiza ipm livre: " << tempoExecutando << " ms" << endl;

	// objeto IPM
	return new IPM(Size(_config.roi.size().width, _config.roi.size().height), Size(_config.roi.size().width, _config.roi.size().height), origPoints, dstPoints);
}*/

/*IPM * AtualizaIPMRestricaoGaussiana2D(ConfigXML &_config, Point2f vp, bool verbose) {

	double tempoInicio = static_cast<double>(getTickCount());

	float sigma_x = 0 / 3; // 0px na horizontal
	float sigma_y = 20 / 3; // 40px na vertical

	Point2f vetorPeso = Point2f(vp.x - _config.dataset._IPM.vp.x, vp.y - _config.dataset._IPM.vp.y);
	float xPeso = (sigma_x == 0) ? 0 : (float)getGaussianValue(vetorPeso.x, sigma_x);
	float yPeso = (sigma_y == 0) ? 0 : (float)getGaussianValue(vetorPeso.y, sigma_y);
	Point2f novoVP = Point2f(_config.dataset._IPM.vp.x + vetorPeso.x * xPeso, _config.dataset._IPM.vp.y + vetorPeso.y * yPeso);

	// calcula equa��o da reta da faiya da esquerda
	Point2f bottom_left = Point2f(static_cast<float>(_config.dataset._IPM.bl), static_cast<float>(_config.dataset._ROI.y + _config.dataset._ROI.height));
	float esquerda_delta_x = novoVP.x - bottom_left.x;
	float esquerda_delta_y = novoVP.y - bottom_left.y;
	float esquerda_slope = esquerda_delta_y / esquerda_delta_x;
	float esquerda_intercept = bottom_left.y - esquerda_slope * bottom_left.x;

	// calcula equa��o da reta da faixa da esquerda
	Point2f bottom_right = Point2f(static_cast<float>(_config.dataset._IPM.br), static_cast<float>(_config.dataset._ROI.y + _config.dataset._ROI.height));
	float direita_delta_x = novoVP.x - bottom_right.x;
	float direita_delta_y = novoVP.y - bottom_right.y;
	float direita_slope = direita_delta_y / direita_delta_x;
	float direita_intercept = bottom_right.y - direita_slope * bottom_right.x;

	// calcula os novos pontos superiores
	float novo_tl = (_config.dataset._ROI.y - esquerda_intercept) / esquerda_slope;
	float novo_tr = (_config.dataset._ROI.y - direita_intercept) / direita_slope;

	// os 4 pontos da imagem de origem
	vector<Point2f> origPoints;
	origPoints.push_back(Point2f(static_cast<float>(novo_tl), 0));
	origPoints.push_back(Point2f(static_cast<float>(novo_tr), 0));
	origPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.br), static_cast<float>(_config.dataset._ROI.height)));
	origPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.bl), static_cast<float>(_config.dataset._ROI.height)));

	// os 4 pontos da imagem de destino
	vector<Point2f> dstPoints;
	dstPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.tl), 0));
	dstPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.tr), 0));
	dstPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.tr), static_cast<float>(_config.dataset._ROI.height)));
	dstPoints.push_back(Point2f(static_cast<float>(_config.dataset._IPM.tl), static_cast<float>(_config.dataset._ROI.height)));

	// calcula o tempo de execu��o
	double tempoFim = static_cast<double>(getTickCount());
	double tempoExecutando = ((tempoFim - tempoInicio) / getTickFrequency()) * 1000;

	// exibe as sa�das definidas (texto e/ou imagem)
	if (verbose) cout << "- atualiza ipm restrito: " << tempoExecutando << " ms" << endl;

	// objeto IPM
	return new IPM(Size(_config.roi.size().width, _config.roi.size().height), Size(_config.roi.size().width, _config.roi.size().height), origPoints, dstPoints);
}*/

OutputXML createOutputXML(Size _frameSize) {
	OutputXML xml;
	xml.frameSize = _frameSize;
	return xml;
}

/*bool appendFrameData(OutputXML *xml, double laneCenter, vector<double> posLeft, vector<double> posRight, int multipleLeft, int multipleRight, LMT lmtLeft, LMT lmtRight, int laneChange, vector<int> &roadSigns, double time) {
	try {
		xml->laneCenter.push_back(laneCenter);
		xml->position.left.push_back(posLeft);
		xml->position.right.push_back(posRight);
		xml->multipleLanes.left.push_back(multipleLeft);
		xml->multipleLanes.right.push_back(multipleRight);
		xml->lmt.left.push_back(lmtLeft);
		xml->lmt.right.push_back(lmtRight);
		xml->laneChange.push_back(laneChange);
		xml->roadSigns.push_back(roadSigns);
		xml->time.push_back(time);
		return true;
	} catch (Exception e) {
		cout << e.what() << endl;
		return false;
	}
}*/


