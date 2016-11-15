#include "AdditionHistogram.h"

ItkImageType::Pointer applyAdditionHistogram(std::string inputImageName, int value)
{
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName( inputImageName );
  reader->Update();
  ItkImageType::Pointer itkInputImage = reader->GetOutput();
  ItkImageType::Pointer ItkResultImage = itkInputImage;
  ItkImageType::RegionType RegionType = itkInputImage->GetLargestPossibleRegion();
  ItkImageType::SizeType regionSize = RegionType.GetSize();

  for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
  {
      for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
      {
          ItkImageType::IndexType pixelIndex;
          pixelIndex[0] = rowIndex;
          pixelIndex[1] = columnIndex;
            if((int)ItkResultImage->GetPixel(pixelIndex) + value > 255){
              ItkResultImage->SetPixel(pixelIndex,255);
            }else{
              ItkResultImage->SetPixel(pixelIndex, ((int)ItkResultImage->GetPixel(pixelIndex) + value));
            }
      }
  }

  RescaleFilterType::Pointer rescaleFilter = RescaleFilterType::New();
  rescaleFilter->SetInput(ItkResultImage);
  rescaleFilter->SetOutputMinimum(0);
  rescaleFilter->SetOutputMaximum(255);
  rescaleFilter->Update();
  return rescaleFilter->GetOutput();
}
