#include <cstdlib> 
#include <iostream> 
#include "highgui.h" 
#include "cv.h" 

using namespace std; 

int main(int argc, char *argv[]) 
{ 
    cvNamedWindow("Camera Capture",0); 
    cvNamedWindow("Capture Processed",0); 
    CvCapture* src = cvCreateCameraCapture(0); 
    IplImage* qry; 
    IplImage* qry2; 
    IplImage* hsv; 
    
    while(1){ 
             qry = cvQueryFrame(src); 
             if (!qry) break; 
             qry2 = cvCreateImage(cvGetSize(qry),8,3); 
            // cvCvtColor(qry2,hsv,CV_RGB2HSV); 
             cvShowImage("Camera Capture",qry); 
             cvShowImage("Capture Processed",hsv); 
             char c = cvWaitKey(33); 
             if (c==27) break; 
             } 
    
    cvReleaseCapture(&src); 
    cvReleaseImage(&qry); 
    cvReleaseImage(&qry2); 
    cvReleaseImage(&hsv); 
    cvDestroyWindow("Camera Capture"); 
    cvDestroyWindow("Capture Processed"); 
    
    system("PAUSE"); 
    return EXIT_SUCCESS; 
} 
