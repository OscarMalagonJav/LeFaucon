#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkCannyEdgeDetectionImageFilter.h"
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"

typedef itk::Image<float, 2> ItkFloatImageType;
typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::CastImageFilter< UnsignedCharImageType,ItkFloatImageType> CastToFloatFilterType;
typedef itk::CannyEdgeDetectionImageFilter< ItkFloatImageType, ItkFloatImageType > CannyFilterType;
typedef itk::RescaleIntensityImageFilter< ItkFloatImageType, UnsignedCharImageType >  RescaleFilterType;
typedef itk::ImageFileReader<UnsignedCharImageType>        ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;

  std::string showParametersInfo(char * argv[])
  {
    std::string execute= "";
    std::cout<<"Parameters"<<std::endl;
    std::cout<< "Input image name: "<< argv[1] <<std::endl;
    std::cout<< "Output image name: "<< argv[2] <<std::endl;
    std::cout<< "Variance: "<< argv[3] <<std::endl;
    std::cout<< "Upper threshold: "<< argv[4] <<std::endl;
    std::cout<< "Lower threshold: "<< argv[5] <<std::endl;
    std::cout<<"*********************************************"<<std::endl;
    std::cout<<"Continue?...(Y/N)"<<std::endl;
    std::cin>>execute;
    return execute;
  }

  int main(int argc, char * argv[])
  {
    // Verify command line arguments
    if( argc < 2 )
      {
      std::cerr << "Usage: ";
      std::cerr << argv[0] << "inputImage outputImage variance upperThreshold lowerThreshold" << std::endl;
      return EXIT_FAILURE;
      }

    std::string inputImageName =argv[1];
    std::string outputImageName =argv[2];
    float variance = atof(argv[3]);
    float upperThreshold = atof(argv[4]);
    float lowerThreshold = atof(argv[5]);

    std::string execute = showParametersInfo(argv);
    if(execute=="y" || execute=="Y"){

        ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
        ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
        CannyFilterType::Pointer cannyFilter = CannyFilterType::New();
        CastToFloatFilterType::Pointer castToFloat = CastToFloatFilterType::New();
        RescaleFilterType::Pointer rescale = RescaleFilterType::New();

        reader->SetFileName(inputImageName);
        writer->SetFileName(outputImageName);
        castToFloat->SetInput(reader->GetOutput());
        cannyFilter->SetInput(castToFloat->GetOutput());
        cannyFilter->SetVariance( variance );
        cannyFilter->SetUpperThreshold( upperThreshold );
        cannyFilter->SetLowerThreshold( lowerThreshold );
        rescale->SetInput(cannyFilter->GetOutput());
        writer->SetInput(rescale->GetOutput());
        writer->Update();
        return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
