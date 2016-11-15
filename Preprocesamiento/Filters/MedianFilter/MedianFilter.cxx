#include "MedianFilter.h"

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
