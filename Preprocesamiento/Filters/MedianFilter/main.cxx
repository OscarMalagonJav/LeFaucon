#include "MedianFilter.h"

int main(int argc, char * argv[])
{

  if( argc < 2 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImage outputImage.extension radius" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int radius = atoi(argv[3]);

  std::string execute= "y";//showParametersInfo(inputImageName, outputImageName,radius);
  if(execute=="y" || execute=="Y"){

    ItkImageType::Pointer medianFilterResult = applyMedianFilter(inputImageName, radius);
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(medianFilterResult);
    writer->Update();
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
