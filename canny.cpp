#include <cv.h>
#include <highgui.h>
 
 
int main(int argc, char *argv[])
{

    cvNamedWindow( "example-input" );
    cvNamedWindow( "example-output" );
    CvCapture *cap=cvCreateCameraCapture(0);

    IplImage *img=NULL;//= cvLoadImage( "my3.jpg", 0);
     IplImage *out=NULL;
     IplImage *img2=NULL;

	while(1)
	{

		img2=cvQueryFrame(cap);
            img = cvCreateImage( cvSize(img2->width,img2->height), 8, 1);		
	
	 cvCvtColor(img2,img,CV_RGB2GRAY);
 
	    // Show the original image
	    cvShowImage("example-input", img);
 
	    // Make sure image is divisible by 2
    	assert( img->width%2 == 0 && img->height%2 == 0);
 
	    // Create an image for the output
	    out = cvCreateImage( cvSize(img->width/2,img->height/2), img->depth, img->nChannels);
 
	    // Reduce the image by 2
	    cvPyrDown( img, out );
 
	    // Perform canny edge detection
	    if(out!=NULL)
		cvCanny(out,out,10,100,3);
 
	    // Show the processed image
	    cvShowImage("example-output", out);
 
	    if(cvWaitKey(5)>10)
	    	break;
//	    cvReleaseImage( &out );
	}
 	   cvReleaseImage( &img );
	    cvReleaseImage( &out );
	  
    cvDestroyWindow( "example-input" );
    cvDestroyWindow( "example-output" );
 
    return 0;
 
}
