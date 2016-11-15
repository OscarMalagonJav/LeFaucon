#include "CannyEdgeDetector.h"

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
