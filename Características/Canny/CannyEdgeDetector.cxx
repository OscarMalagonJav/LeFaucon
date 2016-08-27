#include "CannyEdgeDetector.h"

/*  std::string showParametersInfo(char * argv[])
  {
    std::string execute= "";
    std::cout<<"Parameters"<<std::endl;
    std::cout<< "Input image name: "<< argv[1] <<std::endl;
    std::cout<< "Output image name: "<< argv[2] <<std::endl;
    std::cout<< "Variance: "<< argv[3] <<std::endl;
    std::cout<< "Upper threshold: "<< argv[4] <<std::endl;
    std::cout<< "Lower threshold: "<< argv[5] <<std::endl;
    std::cout<<"*********************************************"<<std::endl;
    std::cout<<"Continue?...(Y/N)"<<std::endl;
    std::cin>>execute;
    return execute;
  }
*/

UnsignedCharImageType::Pointer applyCannyEdgeDetector(std::string inputImageName, float variance ,float upperThreshold ,float lowerThreshold){
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  CannyFilterType::Pointer cannyFilter = CannyFilterType::New();
  CastToFloatFilterType::Pointer castToFloat = CastToFloatFilterType::New();
  RescaleFilterType::Pointer rescale = RescaleFilterType::New();

  reader->SetFileName(inputImageName);
  castToFloat->SetInput(reader->GetOutput());
  cannyFilter->SetInput(castToFloat->GetOutput());
  cannyFilter->SetVariance( variance );
  cannyFilter->SetUpperThreshold( upperThreshold );
  cannyFilter->SetLowerThreshold( lowerThreshold );
  rescale->SetInput(cannyFilter->GetOutput());
  rescale->Update();

  return rescale->GetOutput();
}