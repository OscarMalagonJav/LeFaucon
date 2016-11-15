//LOGARITHMICOPERATIONHISTOGRAM
//funcion de extension total
#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImage.h"
#include "itkBinomialBlurImageFilter.h"
#include "itkImageRegionConstIterator.h"
#include "itkLogImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"
#include <typeinfo>

  typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
  typedef itk::LogImageFilter<ItkImageType, ItkImageType> LogFilter;
  typedef itk::RescaleIntensityImageFilter< ItkImageType, ItkImageType > RescaleFilterType; 

	struct minMax
{
  int minimum;
  int maximum;
};

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

int main(int argc, char * argv[])
{
  
  
  //Argumentos ./Filtro imagenEntrada1 ImagenSalida.png
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
       
      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName.c_str() );
      reader->Update();
      ItkImageType::Pointer itkInputImage = reader->GetOutput();
      ItkImageType::Pointer ItkResultImage = itkInputImage;
      ItkImageType::RegionType RegionType = itkInputImage->GetLargestPossibleRegion();
	  minMax minmax= findMinAndMaxValues(reader->GetOutput());
      
	  std::cout<<minmax.maximum<<std::endl;	
   	  ItkImageType::SizeType regionSize = RegionType.GetSize();

      for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
      {
          for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
          {
              ItkImageType::IndexType pixelIndex;
              pixelIndex[0] = rowIndex;
              pixelIndex[1] = columnIndex;
                if((int)ItkResultImage->GetPixel(pixelIndex) > 255){
                  ItkResultImage->SetPixel(pixelIndex,255);
                }else{
                  ItkResultImage->SetPixel(pixelIndex, ((int)ItkResultImage->GetPixel(pixelIndex)));
				  				   
                }
          }
      }
	  LogFilter:: Pointer logaFilter = LogFilter::New();
	  logaFilter->SetInput(reader->GetOutput);
	  logaFilter->Update();
	  	  		
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(logaFilter->GetOutput());
	  //writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS;
  
}



