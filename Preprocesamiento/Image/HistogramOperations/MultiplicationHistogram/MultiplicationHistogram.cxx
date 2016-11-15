#include "MultiplicationHistogram.h"

ItkImageType::Pointer applyMultiplicationHistogram(std::string inputImageName, float value)
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
          if((int)itkInputImage->GetPixel(pixelIndex)*value >=255)
          {
            ItkResultImage->SetPixel(pixelIndex, (int)255);
          }else{
            ItkResultImage->SetPixel(pixelIndex, ((int)itkInputImage->GetPixel(pixelIndex) * value));
          }
      }
  }
  ItkResultImage->Update();
  return ItkResultImage->GetOutput();
}
