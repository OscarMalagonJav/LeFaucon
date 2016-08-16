#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkSobelEdgeDetectionImageFilter.h"
#include "itkCastImageFilter.h"

typedef itk::Image<unsigned char, 2 > ItkUnsignedCharImageType;
typedef itk::Image<float, 2 > ItkFloatImageType;
typedef itk::CastImageFilter< ItkFloatImageType, ItkUnsignedCharImageType > CastFilterType;    
typedef itk::ImageFileReader<ItkFloatImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<ItkUnsignedCharImageType> ImageFileWriterType;
typedef itk::SobelEdgeDetectionImageFilter<ItkFloatImageType, ItkFloatImageType> SobelFilterType;

std::string showParameters(std::string inputImage, std::string outputImage)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image: "<< inputImage <<std::endl;
  std::cout<< "Output image: "<< outputImage <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Execute?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}


int main(int argc, char * argv[])
{
  
  if( argc < 2 )
    {
    std::cerr << "Uso" << std::endl;
    std::cerr << argv[0] << " imagenEntrada nombreImagenSalida.extension " << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImage = argv[1];
  std::string outputImage = argv[2];
  std::string execute = showParameters(inputImage,outputImage);
  
  if(execute=="y" || execute=="Y"){
   
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputImage);

    SobelFilterType::Pointer SobelFilterType = SobelFilterType::New();
    SobelFilterType->SetInput( reader->GetOutput() );
    
    CastFilterType::Pointer castFilter = CastFilterType::New();
    castFilter->SetInput(SobelFilterType->GetOutput());	

    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImage);
    writer->SetInput(castFilter->GetOutput());
    writer->Update();

    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}
