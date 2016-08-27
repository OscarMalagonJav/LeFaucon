#include "Noise-BinomialBlur"

int main(int argc, char * argv[])
{

  if( argc < 3 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension repetitions" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int repetitions = atoi(argv[3]);

  std::string execute= "y";//showParametersInfo(inputImageName, outputImageName, repetitions);
  if(execute=="y" || execute=="Y"){

    ItkImageType::Pointer smoothingFilterResult = applyNoiseBinomialBlur(inputImageName, repetitions);
    ItkFileWriterType::Pointer writer = ItkFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(smoothingFilterResult);
    writer->Update();

    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}
