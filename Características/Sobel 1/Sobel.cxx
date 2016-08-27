#include "Sobel.h"

/*
std::string showParameters(std::string inputImage, std::string outputImage)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image: "<< inputImage <<std::endl;
  std::cout<< "Output image: "<< outputImage <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Execute?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}
*/
ItkUnsignedCharImageType::Pointer applySobel(std::string inputImage)
{
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputImage);

    SobelFilterType::Pointer SobelFilterType = SobelFilterType::New();
    SobelFilterType->SetInput( reader->GetOutput() );
    
    CastFilterType::Pointer castFilter = CastFilterType::New();
    castFilter->SetInput(SobelFilterType->GetOutput());	
    castFilter->Update();
    return castFilter->GetOutput();
}
