#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/dnn.hpp>
#include "opencv2/imgproc/imgproc_c.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "functions.h"
 
using namespace std;
using namespace cv;


 
int main(int argc, char** argv)
{   

    // Let's start by loading our dnn

    string dir = "model/yolo/";
    string names = dir + "coco.names";
    string conf = dir + "yolov3.cfg";
    string weight = dir + "yolov3.weights";


    vector<string> classes;
    vector<string>  &refclass = classes;
    Net deepNet = loadDaNetwork(names, conf, weight, refclass);


    // Setup IP cam

    string ip ;
    
    ifstream get_ip("ip", ios::in);  // on ouvre en lecture

         if(get_ip)  // si l'ouverture a fonctionné
        {

                getline(get_ip, ip);  
                cout << ip << endl;  
                get_ip.close();

        } 
    //cout << "Please enter your cam IP" << endl << endl ;
    //cin >> ip;
    VideoCapture cam;
    cam.open(ip);

    if(!cam.isOpened()){

        cout << "the cam failed to open" << endl;
        return -1;
      }
     
   


    Mat frame, blob;
    
    // Read a frame
    for(;;)

    {
      
      cam >> frame ;

      // Create a 4D blob from a frame for yolo
      blobFromImage(frame, blob, 1/255.0, cvSize(416, 416), Scalar(0,0,0), true, false);
        
      //Sets the input to the network
      deepNet.setInput(blob);
        
      // Runs the forward pass to get output of the output layers
      vector<Mat> outs;
      deepNet.forward(outs, getOutputsNames(deepNet));
        
      // Remove the bounding boxes with low confidence
      postprocess(frame, outs, 0.5f, 0.4f, refclass);


      imshow("I see you", frame);


      if (waitKey(2) >= 0) break;
       
    }
    cam.release();
    return 0;
}

