#include "DiscreteGaussianFilter.h"

ItkImageType::Pointer applyDiscreteGaussianFilter(std::string inputImageName,double variance)
{
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName(inputImageName);
  discreteGaussianFilterType::Pointer discreteGaussian = discreteGaussianFilterType::New();
  discreteGaussian->SetInput( reader->GetOutput() );
  discreteGaussian->SetVariance(variance);
  CastFilterType::Pointer castfilter = CastFilterType::New();
  castfilter->SetInput(discreteGaussian->GetOutput());
  castfilter->Update();
  return castfilter->GetOutput();
}
