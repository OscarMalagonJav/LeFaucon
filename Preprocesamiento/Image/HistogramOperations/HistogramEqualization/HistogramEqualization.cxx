#include "HistogramEqualization.h"

/*std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int radius)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Radius: "<< radius <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}*/

ItkImageType::Pointer applyHistogramEqualization(std::string inputImageName, int radius)
{
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName( inputImageName );
  reader->Update();
  AdaptiveHistogramEqualizationImageFilterType::Pointer adaptiveHistogramEqualizationImageFilter = AdaptiveHistogramEqualizationImageFilterType::New();
  adaptiveHistogramEqualizationImageFilter->SetInput(reader->GetOutput());
  adaptiveHistogramEqualizationImageFilter->SetRadius(radius);
  adaptiveHistogramEqualizationImageFilter->Update();

  RescaleFilterType::Pointer rescaleFilter = RescaleFilterType::New();
  rescaleFilter->SetInput(adaptiveHistogramEqualizationImageFilter->GetOutput());
  rescaleFilter->SetOutputMinimum(0);
  rescaleFilter->SetOutputMaximum(255);
  rescaleFilter->Update();

  return rescaleFilter->GetOutput();
}
