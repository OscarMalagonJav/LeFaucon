#include "HoughLines.h"
int main(int argc, char * argv[])
  {
    // Verify command line arguments
    if( argc < 8 )
      {
      std::cerr << "Usage: ";
	  std::cout<<"If you want to use the default values, you have to insert them manually"<<std::endl;
      std::cerr << argv[0] << " inputImage "<<
	  						   "outputImage "<<
							   "numberOfLines (default=1) "<<
							   "threshold (default=0) "<<
							   "discRadius (default=10) "<< 
							   "variance (default=5) "<<
							   "angleResolution (default =500) "
							   <<std::endl;
		return EXIT_FAILURE;
      }

    std::string inputImageName =argv[1];
    std::string outputImageName =argv[2];
	int numberOfLines = atoi(argv[3]);
	float threshold = atof(argv[4]);
	float discRadius = atof(argv[5]);
	float variance = atof(argv[6]);
	float angleResolution = atof(argv[7]);
	std::string execute = "y";//showParametersInfo(argv);
    if(execute=="y" || execute=="Y"){
		ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
        UnsignedCharImageType::Pointer  houghLinesSearching = 
				applyHoughTransformForLines(inputImageName,numberOfLines,threshold,
                                            discRadius, variance, angleResolution);
		writer->SetFileName(outputImageName);
        writer->SetInput(houghLinesSearching);
        writer->Update();
		return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}//end main