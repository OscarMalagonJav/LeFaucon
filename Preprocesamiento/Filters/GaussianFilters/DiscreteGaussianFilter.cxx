#include "DiscreteGaussianFilter.h"
/*
std::string showParametersInfo(std::string inputImageName,std::string outputImageName, double variance)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Variance.........: "<< variance <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}*/

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
