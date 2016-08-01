#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkMedianImageFilter.h"

std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int radius)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name.: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Radius...........: "<< radius <<std::endl
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
  typedef itk::MedianImageFilter<ItkImageType, ItkImageType > MedianFilterType;
  
  if( argc < 2 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImage outputImage.extension radius" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int radius = atoi(argv[3]);
  
  std::string execute= showParametersInfo(inputImageName, outputImageName,radius);
  if(execute=="y" || execute=="Y"){

    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputImageName);
    MedianFilterType::Pointer medianFilter = MedianFilterType::New();
    MedianFilterType::InputSizeType RadiusType;
    RadiusType.Fill(radius);
    medianFilter->SetRadius(RadiusType);
    medianFilter->SetInput( reader->GetOutput() );

    ItkImageType::Pointer medianFilterResult = medianFilter->GetOutput();
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(medianFilterResult);
    writer->Update();
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}