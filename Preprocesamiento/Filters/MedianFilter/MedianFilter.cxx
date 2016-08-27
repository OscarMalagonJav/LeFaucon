#include "MedianFilter.h"
/*std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int radius)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name.: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Radius...........: "<< radius <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}*/

ItkImageType::Pointer applyMedianFilter(std::string inputImageName, int radius)
{
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName(inputImageName);
  MedianFilterType::Pointer medianFilter = MedianFilterType::New();
  MedianFilterType::InputSizeType RadiusType;
  RadiusType.Fill(radius);
  medianFilter->SetRadius(RadiusType);
  medianFilter->SetInput( reader->GetOutput());
  medianFilter->Update();
  return medianFilter->GetOutput();
}
