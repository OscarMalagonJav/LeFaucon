#include "DiscreteGaussianFilter.h"

int main(int argc, char * argv[])
{

  if( argc < 2 )
  {
    std::cerr << "Usage:" << std::endl;
    std::cerr << argv[0] << " inputImage outputImage.extension variance" << std::endl;
    return EXIT_FAILURE;
  }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  double variance = atof(argv[3]);
  std::string execute = "y";//showParametersInfo(inputImageName, outputImageName, variance);
  if(execute=="y" || execute=="Y"){
    ItkImageType::Pointer discreteGaussianFilterResult = applyDiscreteGaussianFilter(inputImageName, variance);
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(discreteGaussianFilterResult);
    writer->Update();
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}
