#include "itkImage.h"
#include "itkBinaryDilateImageFilter.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkGrayscaleDilateImageFilter.h"
#include "itkSubtractImageFilter.h"
//https://itk.org/Wiki/ITK/Examples/Morphology/BinaryMorphologicalOpeningImageFilter
/*  typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
  
  //typedef itk::RescaleIntensityImageFilter< ItkImageType, ItkImageType > RescaleFilterType; 
  typedef itk::BinaryBallStructuringElement<ItkImageType::PixelType,2>StructuringElementType;	
  typedef itk::BinaryDilateImageFilter <ItkImageType, ItkImageType, StructuringElementType>BinaryDilateImageFilterType; 	
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
  
  
  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
      
      unsigned int radius= 2; 
      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName.c_str() );
      reader->Update();
	  
	  StructuringElementType structuringElement;
	  structuringElement.SetRadius(radius);
	  structuringElement.CreateStructuringElement();
	  
      BinaryDilateImageFilterType::Pointer dilateFilter=BinaryDilateImageFilterType::New();
	  dilateFilter->SetInput(reader->GetOutput());
	  dilateFilter->SetKernel(structuringElement);

	  ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(dilateFilter->GetOutput());
	  //writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS; 	
	  	
}*/

typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
  
  //typedef itk::RescaleIntensityImageFilter< ItkImageType, ItkImageType > RescaleFilterType; 
  typedef itk::BinaryBallStructuringElement<ItkImageType::PixelType,2>StructuringElementType;	
  typedef itk::GrayscaleDilateImageFilter <ItkImageType, ItkImageType, StructuringElementType>GrayscaleDilateImageFilterType;
  typedef itk::SubtractImageFilter<ItkImageType>SubtractType; 	
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
  
  
  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
      
      unsigned int radius= 2; 
      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName.c_str() );
      reader->Update();
	  
	  StructuringElementType structuringElement;
	  structuringElement.SetRadius(radius);
	  structuringElement.CreateStructuringElement();
	  
      GrayscaleDilateImageFilterType::Pointer dilateFilter=GrayscaleDilateImageFilterType::New();
	  dilateFilter->SetInput(reader->GetOutput());
	  dilateFilter->SetKernel(structuringElement);

	  SubtractType::Pointer diff=SubtractType::New();
      diff->SetInput1(reader->GetOutput());
	  diff->SetInput2(dilateFilter->GetOutput());

      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(diff->GetOutput());
	  //writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS;    	
	  
}
