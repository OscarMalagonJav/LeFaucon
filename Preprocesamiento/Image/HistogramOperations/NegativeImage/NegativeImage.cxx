#include "NegativeImage.h"

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
