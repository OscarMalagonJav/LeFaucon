#include "Thresholding.h"

/*std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int threshold)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Threshold.........: "<< threshold <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}*/

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
