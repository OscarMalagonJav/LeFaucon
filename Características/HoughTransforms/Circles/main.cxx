#include "HoughCircles.h"
int main(int argc, char * argv[])
  {
    // Verify command line arguments
    if( argc < 11 )
      {
      std::cerr << "Usage: ";
	  std::cout<<"If you want to use the default values, you have to insert them manually"<<std::endl;
      std::cerr << argv[0] << " inputImage "<<
	  						   "outputImage "<<
							   "numberOfCircles (default=1) "<< 
							   "radiusMin (default=0) "<<
							   "radiusMax (default=10) "<<
							   "sigmaGradient (default=1) "<<
							   "threshold (default=0) "<<
							   "discRadiusRatio (default=1) "<< 
							   "variance (default=10) "<<
							   "[sweepAngle (default =0) "
							   <<std::endl;
		return EXIT_FAILURE;
      }

    std::string inputImageName =argv[1];
    std::string outputImageName =argv[2];
	int numberOfCircles = atoi(argv[3]);
	float radiusMin = atof(argv[4]);
	float radiusMax = atof(argv[5]);
	float sigmaGradient = atof(argv[6]);
	float threshold = atof(argv[7]);
	float discRadiusRatio = atof(argv[8]);
	float variance = atof(argv[9]);
	float sweepAngle = atof(argv[10]);
	std::string execute = "y";
    if(execute=="y" || execute=="Y"){
		ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
        UnsignedCharImageType::Pointer  houghCirclesSearching = 
				applyHoughTransformForCircles(inputImageName,numberOfCircles, radiusMin,radiusMax,
								 sigmaGradient,threshold, discRadiusRatio, variance, sweepAngle );
		writer->SetFileName(outputImageName);
        writer->SetInput(houghCirclesSearching);
        writer->Update();
		return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
