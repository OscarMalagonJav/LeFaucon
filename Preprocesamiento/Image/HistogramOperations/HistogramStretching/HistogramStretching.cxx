#include "HistogramStretching.h"

minMax findMinAndMaxValues(ItkImageType::Pointer img)
{
  ItkImageType::RegionType region = img->GetLargestPossibleRegion();
  ItkImageType::SizeType regionSize = region.GetSize();
  minMax minmax;
  minmax.minimum=255;
  minmax.maximum=0;
  for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
      {
          for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
          {
            ItkImageType::IndexType pixelIndex;
            pixelIndex[0] = rowIndex;
            pixelIndex[1] = columnIndex;
            if((int)img->GetPixel(pixelIndex) <minmax.minimum)
            {
              minmax.minimum = (int)img->GetPixel(pixelIndex);
            }
            if((int)img->GetPixel(pixelIndex) >minmax.maximum)
            {
              minmax.maximum = (int)img->GetPixel(pixelIndex);
            }
          }
      }
      return minmax;
}

ItkImageType::Pointer applyStretchingToTheImage(ItkImageType::Pointer img, minMax minmax){
  ItkImageType::RegionType region = img->GetLargestPossibleRegion();
  ItkImageType::SizeType regionSize = region.GetSize();
  int factor = 255 / (minmax.maximum - minmax.minimum);
  ItkImageType::Pointer imgResult = ItkImageType::New();
  for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
      {
          for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
          {
            ItkImageType::IndexType pixelIndex;
            pixelIndex[0] = rowIndex;
            pixelIndex[1] = columnIndex;
            imgResult->SetPixel(pixelIndex,((int)img->GetPixel(pixelIndex)-minmax.minimum) * factor);
          }
      }
      imgResult->Update();
      return imgResult->GetOutput();
}
