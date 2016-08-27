#include "NegativeImage.h"

/*std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int maximum)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Maximum: "<< maximum <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}*/

ItkImageType::Pointer negativeImage(std::string inputImageName, int maximum)
{
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName( inputImageName.c_str() );
  reader->Update();
  ItkImageType::Pointer itkInputImage = reader->GetOutput();
  InvertIntensityImageFilterType::Pointer negativeFilter = InvertIntensityImageFilterType::New();
  negativeFilter->SetInput(itkInputImage);
  negativeFilter->SetMaximum(maximum);
  negativeFilter->Update();

  return negativeFilter->GetOutput();
}
