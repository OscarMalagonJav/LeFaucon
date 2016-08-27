#include "Noise-BinomialBlur"
/*
std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int repetitions)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Number of repetitions: "<< repetitions <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}*/

ItkImageType::Pointer applyNoiseBinomialBlur(std::string inputImageName, int repetitions)
{

  ItkFileReaderType::Pointer reader = ItkFileReaderType::New();
  reader->SetFileName(inputImageName);
  smoothingFilterType::Pointer smoothingFilter = smoothingFilterType::New();
  smoothingFilter->SetInput( reader->GetOutput() );
  smoothingFilter->SetRepetitions( repetitions);
  smoothingFilter->Update();
  return smoothingFilter->GetOutput();
}
