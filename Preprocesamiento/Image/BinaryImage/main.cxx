#include "BinaryImage.h"

int main(int argc, char * argv[])
{
  if( argc < 5 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension lowerThreshold upperThreshold" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int lowerThreshold = atoi(argv[3]);
  int upperThreshold = atoi(argv[4]);
  std::string execute = "y";
  if(execute=="y" || execute=="Y")
  {
      ItkImageType::Pointer binaryImage = createBinayImage(inputImageName,lowerThreshold,upperThreshold);
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(binaryImage);
      writer->Update();
      return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
