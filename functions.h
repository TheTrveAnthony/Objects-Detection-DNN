#ifndef PLUS_H_INCLUDED
#define PLUS_H_INCLUDED


using namespace cv;
using namespace dnn;
using namespace std;



Net loadDaNetwork(string classesFile, string config, string weights, vector<string> &classes);
void postprocess(Mat& frame, const vector<Mat>& outs, float confThreshold, float nmsThreshold, vector<string> &classes);
void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame, vector<string> classes);
vector<String> getOutputsNames(const Net& net);



#endif