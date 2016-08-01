#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkDiscreteGaussianImageFilter.h"

std::string showParametersInfo(std::string inputImageName,std::string outputImageName, double variance)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl;
  std::cout<< "Variance.........: "<< variance <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}

int main(int argc, char * argv[])
{
  
  typedef itk::Image<unsigned char, 2 > ItkImageType;
  //typedef itk::Image<float, 2 > ItkImageTypeFloat;    
  typedef itk::ImageFileReader<ItkImageType> ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;//Change the output image by ItkImageTypeFloat
  typedef itk::DiscreteGaussianImageFilter<ItkImageType, ItkImageType> discreteGaussianFilterType; //Change the output image by ItkImageTypeFloat

  if( argc < 2 )
  {
    std::cerr << "Usage:" << std::endl;
    std::cerr << argv[0] << " inputImage outputImage.extension variance" << std::endl;
    return EXIT_FAILURE;
  }

  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  double variance = atof(argv[3]);
  std::string execute = showParametersInfo(inputImageName, outputImageName, variance);
  if(execute=="y" || execute=="Y"){
    //According to Itk documentation it is better to have an ITK image float as the output of the filter
    //In this case it has been left as an int image to be able to visualize the result as a PNG image
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputImageName);
    discreteGaussianFilterType::Pointer discreteGaussian = discreteGaussianFilterType::New();
    discreteGaussian->SetInput( reader->GetOutput() );
    discreteGaussian->SetVariance(variance);
    ItkImageType::Pointer discreteGaussianFilterResult = discreteGaussian->GetOutput();
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(discreteGaussianFilterResult);
    writer->Update();
    
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}


