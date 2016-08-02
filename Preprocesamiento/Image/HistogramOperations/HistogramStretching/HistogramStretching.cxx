#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"

struct minMax
{
  int minimum;
  int maximum;
};
  typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;

std::string showParametersInfo(std::string inputImageName,std::string outputImageName)
{
  std::string execute= "";
  std::cout<<"Parameters"<<std::endl;
  std::cout<< "Input image name: "<< inputImageName <<std::endl;
  std::cout<< "Output image name: "<< outputImageName <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continue?...(Y/N)"<<std::endl;
  std::cin>>execute;
  return execute;
}

minMax findMinAndMaxValues(ItkImageType::Pointer img)
{
  ItkImageType::RegionType region = img->GetLargestPossibleRegion();
  ItkImageType::SizeType regionSize = region.GetSize();
  minMax minmax;
  minmax.minimum=255;
  minmax.maximum=0;
  for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
      {
          for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
          {
            ItkImageType::IndexType pixelIndex;
            pixelIndex[0] = rowIndex;
            pixelIndex[1] = columnIndex;
            if((int)img->GetPixel(pixelIndex) <minmax.minimum)
            {
              minmax.minimum = (int)img->GetPixel(pixelIndex);
            }
            if((int)img->GetPixel(pixelIndex) >minmax.maximum)
            {
              minmax.maximum = (int)img->GetPixel(pixelIndex);
            }
          }
      }
      return minmax;
}

ItkImageType::Pointer applyStretchingToTheImage(ItkImageType::Pointer img, minMax minmax){
  ItkImageType::RegionType region = img->GetLargestPossibleRegion();
  ItkImageType::SizeType regionSize = region.GetSize();
  int factor = 255 / (minmax.maximum - minmax.minimum); 
  ItkImageType::Pointer imgResult = ItkImageType::New();

  for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
      {
          for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
          {
            ItkImageType::IndexType pixelIndex;
            pixelIndex[0] = rowIndex;
            pixelIndex[1] = columnIndex;
            imgResult->SetPixel(pixelIndex,((int)itkInputImage->GetPixel(pixelIndex)-minmax.minimum) * factor);
          }
      }
      return imgResult;
}

int main(int argc, char * argv[])
{
  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension maximum" << std::endl;
    return EXIT_FAILURE;
    }

  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  std::string execute = showParametersInfo(inputImageName, outputImageName);
  if(execute=="y" || execute=="Y")
  {
      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName.c_str() );
      reader->Update();
      minMax minmax = findMinAndMaxValues(reader->GetOutput());
      ItkImageType::Pointer ItkResultImage;
      
      if(minmax.minimum ==0 && minmax.maximum==255)
      {
        std::cout<<"It is not possible to stretch the histogram because it is already stretched"<<std::endl;
        return EXIT_SUCCESS;
      }else{
        ItkResultImage = applyStretchingToTheImage(reader->GetOutput(), minmax);
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