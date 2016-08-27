#include "Thresholding.h"

int main(int argc, char * argv[])
{
  if( argc < 3 )
  {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension threshold" << std::endl;
    return EXIT_FAILURE;
  }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int threshold = atoi(argv[3]);
  std::string execute= "y";//showParametersInfo(inputImageName, outputImageName, threshold);
  if(execute=="y" || execute=="Y"){
    ItkImageType::Pointer thresholdedImage = thresholdImage(inputImageName, threshold);
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(thresholdedImage);
    writer->Update();
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
