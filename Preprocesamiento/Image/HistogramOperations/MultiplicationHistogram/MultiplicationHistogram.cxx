#include "MultiplicationHistogram.h"

/*std::string showParametersInfo(std::string inputImageName,std::string outputImageName, float value)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Value.........: "<< value <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}*/
ItkImageType::Pointer applyMultiplicationHistogram(std::string inputImageName, float value)
{
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName( inputImageName );
  reader->Update();
  ItkImageType::Pointer itkInputImage = reader->GetOutput();
  ItkImageType::Pointer ItkResultImage = itkInputImage;
  ItkImageType::RegionType RegionType = itkInputImage->GetLargestPossibleRegion();
  ItkImageType::SizeType regionSize = RegionType.GetSize();

  for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++) //Itera sobre las filas
  {
      for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++) //Itera sobre las columnas
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
