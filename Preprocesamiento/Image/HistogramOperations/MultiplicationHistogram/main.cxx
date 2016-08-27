#include "MultiplicationHistogram.h"

int main(int argc, char * argv[])
{

  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension value" << std::endl;
    return EXIT_FAILURE;
    }

  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  float value = atof(argv[3]);
  std::string execute = "y";//showParametersInfo(inputImageName, outputImageName, value);
  if(execute=="y" || execute=="Y")
  {

      ItkImageType::Pointer multipliedImage = applyMultiplicationHistogram(inputImageName, value);
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(multipliedImage);
      writer->Update();
      return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
