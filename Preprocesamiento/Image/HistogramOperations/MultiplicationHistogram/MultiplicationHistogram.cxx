#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImageRegionConstIterator.h"
#include "itkRescaleIntensityImageFilter.h"
std::string showParametersInfo(std::string inputImageName,std::string outputImageName, float value)
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
}

int main(int argc, char * argv[])
{
  typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;

  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension value" << std::endl;
    return EXIT_FAILURE;
    }

  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  float value = atof(argv[3]);
  std::string execute = showParametersInfo(inputImageName, outputImageName, value);
  if(execute=="y" || execute=="Y")
  {

      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName.c_str() );
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
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS;

  }else{

    return EXIT_FAILURE;

  }
}
