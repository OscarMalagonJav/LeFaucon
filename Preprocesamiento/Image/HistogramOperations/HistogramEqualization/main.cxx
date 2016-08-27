#include "HistogramEqualization.h"

int main(int argc, char * argv[])
{
  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension radius" << std::endl;
    return EXIT_FAILURE;
    }

  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int radius = atoi(argv[3]);

  std::string execute = "y";//showParametersInfo(inputImageName, outputImageName, radius);
  if(execute=="y" || execute=="Y")
  {
      ItkImageType::Pointer ItkResultImage = applyHistogramEqualization( inputImageName, radius);
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS;

  }else{

    return EXIT_FAILURE;

  }
}
