#include "BinaryImage.h"

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
