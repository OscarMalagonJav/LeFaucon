#include "AdditionHistogram.h"

int main(int argc, char * argv[])
{
  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension value" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int value = atoi(argv[3]);
  std::string execute =  "y";
  if(execute=="y" || execute=="Y")
  {
      ItkImageType::Pointer additionHistogram = applyAdditionHistogram(inputImageName, value);
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(additionHistogram);
      writer->Update();
      return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
