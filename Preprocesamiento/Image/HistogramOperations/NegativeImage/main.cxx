#include "NegativeImage.h"

int main(int argc, char * argv[])
{

  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension maximum" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int maximum = atoi(argv[3]);
  std::string execute = "y";
  if(execute=="y" || execute=="Y")
  {

      ItkImageType::Pointer ItkResultImage = negativeImage(inputImageName, maximum);
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS;

  }else{

    return EXIT_FAILURE;

  }
}
