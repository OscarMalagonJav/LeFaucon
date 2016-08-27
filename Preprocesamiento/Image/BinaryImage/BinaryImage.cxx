#include "BinaryImage.h"

/*std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int lowerThreshold, int upperThreshold)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Lower Threshold.........: "<< lowerThreshold <<std::endl;
  std::cout<< "Upper Threshold.........: "<< upperThreshold <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}*/

ItkImageType::Pointer createBinayImage(std::string inputImageName,int lowerThreshold, int upperThreshold)
{
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName( inputImageName );
  reader->Update();
  ItkImageType::Pointer itkInputImage = reader->GetOutput();
  BinaryThresholdImageFilterType::Pointer thresholdFilter = BinaryThresholdImageFilterType::New();
  thresholdFilter->SetInput(itkInputImage);
  thresholdFilter->SetLowerThreshold(lowerThreshold);
  thresholdFilter->SetUpperThreshold(upperThreshold);
  thresholdFilter->SetInsideValue(255);
  thresholdFilter->SetOutsideValue(0);
  thresholdFilter->Update();
  return thresholdFilter->GetOutput();

}
