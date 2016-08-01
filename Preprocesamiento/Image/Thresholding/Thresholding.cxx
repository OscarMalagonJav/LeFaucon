#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"

std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int threshold)
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
}

int main(int argc, char * argv[])
{
  typedef itk::Image<unsigned char, 2 > ItkImageType;    
  typedef itk::ImageFileReader<ItkImageType> ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;  
  if( argc < 3 )
  {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension threshold" << std::endl;
    return EXIT_FAILURE;
  }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int threshold = atoi(argv[3]);
  std::string execute= showParametersInfo(inputImageName, outputImageName, threshold);
  if(execute=="y" || execute=="Y"){

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

    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(itkOutputImage);
    writer->Update();

    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}