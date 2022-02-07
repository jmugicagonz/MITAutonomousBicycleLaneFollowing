#ifndef __PRE_PROCESSING_H
#define __PRE_PROCESSING_H

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "lane_followingv2/IPM.h"

using namespace std;
using namespace cv;


class PreProcessing {

	public:
		//PreProcessing(const Rect &_regiaoDeInteresse, IPM *_ipm, bool _verbose = false, bool _display = false);
		//Instance creation redefined without IPM. To change later!
		PreProcessing(const Rect &_regiaoDeInteresse, bool _verbose = false, bool _display = false);
		Mat1b executar(const Mat3b &colorFrame, Mat1b &outGrayFrameRoi, IPM *_ipm = nullptr);
		Mat1b executar(const Mat3b &colorFrame, IPM *_ipm = nullptr);
		double getTime() { return tempoExecutando; };
		vector<Point> getVerticesIPM();
		Mat1b getMascaraIPM(int _dilateSize = 0);

	private:
		void view(const Mat3b &entrada, const Mat1b &saida);
		Rect regiaoDeInteresse;
		IPM *ipm;
		double tempoExecutando;
		bool display;
		bool verbose;
};

#endif // __PRE_PROCESSING_H

