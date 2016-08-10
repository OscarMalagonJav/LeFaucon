#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkAdaptiveHistogramEqualizationImageFilter.h"
#include <itkRescaleIntensityImageFilter.h>

  typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
  typedef  itk::AdaptiveHistogramEqualizationImageFilter< ItkImageType > AdaptiveHistogramEqualizationImageFilterType;
  typedef itk::RescaleIntensityImageFilter< ItkImageType, ItkImageType > RescaleFilterType;

std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int radius)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Radius: "<< radius <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}

int main(int argc, char * argv[])
{
  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension radius" << std::endl;
    return EXIT_FAILURE;
    }

  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int radius = atoi(argv[3]);

  std::string execute = showParametersInfo(inputImageName, outputImageName, radius);
  if(execute=="y" || execute=="Y")
  {
      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName.c_str() );
      reader->Update();
      ItkImageType::Pointer ItkResultImage= ItkImageType::New();
      AdaptiveHistogramEqualizationImageFilterType::Pointer adaptiveHistogramEqualizationImageFilter = AdaptiveHistogramEqualizationImageFilterType::New();
      adaptiveHistogramEqualizationImageFilter->SetInput(reader->GetOutput());
      adaptiveHistogramEqualizationImageFilter->SetRadius(radius);
      adaptiveHistogramEqualizationImageFilter->Update();

      RescaleFilterType::Pointer rescaleFilter = RescaleFilterType::New();
      rescaleFilter->SetInput(adaptiveHistogramEqualizationImageFilter->GetOutput());
      rescaleFilter->SetOutputMinimum(0);
      rescaleFilter->SetOutputMaximum(255);

      ItkResultImage = rescaleFilter->GetOutput();

      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS;

  }else{

    return EXIT_FAILURE;

  }
}
