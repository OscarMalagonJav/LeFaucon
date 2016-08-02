#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkInvertIntensityImageFilter.h"

std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int maximum)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Maximum: "<< maximum <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}

int main(int argc, char * argv[])
{
  typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
  typedef itk::InvertIntensityImageFilter <ItkImageType> InvertIntensityImageFilterType;
  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension maximum" << std::endl;
    return EXIT_FAILURE;
    }

  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int maximum = atoi(argv[3]);
  std::string execute = showParametersInfo(inputImageName, outputImageName, maximum);
  if(execute=="y" || execute=="Y")
  {
      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName.c_str() );
      reader->Update();
      ItkImageType::Pointer itkInputImage = reader->GetOutput();
      InvertIntensityImageFilterType::Pointer negativeFilter = InvertIntensityImageFilterType::New();
      negativeFilter->SetInput(itkInputImage);
      negativeFilter->SetMaximum(maximum);
      ItkImageType::Pointer ItkResultImage = negativeFilter->GetOutput();
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS;

  }else{
    
    return EXIT_FAILURE;
  
  }
}