#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkBinaryThresholdImageFilter.h"

typedef itk::Image< unsigned char, 2 >   ItkImageType;
typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
typedef itk::BinaryThresholdImageFilter <ItkImageType, ItkImageType> BinaryThresholdImageFilterType;

std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int lowerThreshold, int upperThreshold)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Lower Threshold.........: "<< lowerThreshold <<std::endl;
  std::cout<< "Upper Threshold.........: "<< upperThreshold <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}

int main(int argc, char * argv[])
{
  if( argc < 5 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension lowerThreshold upperThreshold" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int lowerThreshold = atoi(argv[3]);
  int upperThreshold = atoi(argv[4]);
  std::string execute = showParametersInfo(inputImageName, outputImageName,lowerThreshold, upperThreshold);
  if(execute=="y" || execute=="Y")
  {


      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName.c_str() );
      reader->Update();
      ItkImageType::Pointer itkInputImage = reader->GetOutput();

      BinaryThresholdImageFilterType::Pointer thresholdFilter = BinaryThresholdImageFilterType::New();
      thresholdFilter->SetInput(itkInputImage);
      thresholdFilter->SetLowerThreshold(lowerThreshold);
      thresholdFilter->SetUpperThreshold(upperThreshold);
      thresholdFilter->SetInsideValue(255);
      thresholdFilter->SetOutsideValue(0);

      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(thresholdFilter->GetOutput());
      writer->Update();
      return EXIT_SUCCESS;

  }else{

    return EXIT_FAILURE;

  }
}
