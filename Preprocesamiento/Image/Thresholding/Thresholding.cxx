#include "Thresholding.h"

ItkImageType::Pointer thresholdImage(std::string inputImageName, int threshold){
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName(inputImageName);
  reader->Update();
  ItkImageType::Pointer itkInputImage = reader->GetOutput();
  ItkImageType::Pointer itkOutputImage = itkInputImage;
  ItkImageType::RegionType region = itkInputImage->GetLargestPossibleRegion();
  ItkImageType::SizeType regionSize = region.GetSize();
  for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
    {
        for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
        {
          ItkImageType::IndexType pixelIndex;
          pixelIndex[0] = rowIndex;
          pixelIndex[1] = columnIndex;
          if((int)itkInputImage->GetPixel(pixelIndex)>=threshold)
          {
            itkOutputImage->SetPixel(pixelIndex,(int)itkInputImage->GetPixel(pixelIndex));
          }else{
            itkOutputImage->SetPixel(pixelIndex,0);
          }
        }
    }
  itkOutputImage->Update();
  return itkOutputImage->GetOutput();
}
