#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkBinomialBlurImageFilter.h"

std::string showParametersInfo(std::string inputImageName,std::string outputImageName, int repetitions)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Number of repetitions: "<< repetitions <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}

int main(int argc, char * argv[])
{
  typedef itk::Image<unsigned char, 2 > ItkImageType;    
  typedef itk::ImageFileReader<ItkImageType> ItkFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ItkFileWriterType;//Change the output image by ItkImageFloatType
  typedef itk::BinomialBlurImageFilter<ItkImageType, ItkImageType> smoothingFilterType; //Change the output image by ItkImageFloatType

  if( argc < 3 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension repetitions" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  int repetitions = atoi(argv[3]);

  std::string execute= showParametersInfo(inputImageName, outputImageName, repetitions);
  if(execute=="y" || execute=="Y"){
    
    ItkFileReaderType::Pointer reader = ItkFileReaderType::New();
    reader->SetFileName(inputImageName);
    smoothingFilterType::Pointer smoothingFilter = smoothingFilterType::New();
    smoothingFilter->SetInput( reader->GetOutput() );
    smoothingFilter->SetRepetitions( repetitions);
    
    ItkImageType::Pointer smoothingFilterResult = smoothingFilter->GetOutput();
    ItkFileWriterType::Pointer writer = ItkFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(smoothingFilterResult);
    writer->Update();

    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}