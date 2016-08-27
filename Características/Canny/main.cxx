#include "CannyEdgeDetector.h"

int main(int argc, char * argv[])
  {
    // Verify command line arguments
    if( argc < 2 )
      {
      std::cerr << "Usage: ";
      std::cerr << argv[0] << "inputImage outputImage variance upperThreshold lowerThreshold" << std::endl;
      return EXIT_FAILURE;
      }

    std::string inputImageName =argv[1];
    std::string outputImageName =argv[2];
    float variance = atof(argv[3]);
    float upperThreshold = atof(argv[4]);
    float lowerThreshold = atof(argv[5]);

    std::string execute = "y";//showParametersInfo(argv);
    if(execute=="y" || execute=="Y"){
        UnsignedCharImageType::Pointer canny =applyCannyEdgeDetector(inputImageName, variance, upperThreshold,lowerThreshold);
        ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
        writer->SetFileName(outputImageName);
        writer->SetInput(canny);
        writer->Update();
        return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}