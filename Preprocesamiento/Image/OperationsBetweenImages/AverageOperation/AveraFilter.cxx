#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImage.h"
#include "itkAddImageFilter.h"

typedef itk::Image<unsigned char, 2>  ImageType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::AddImageFilter <ImageType, ImageType, ImageType> AddImageFilterType;
struct minMax
{
  int minimum;
  int maximum;
};

minMax findMinAndMaxValues(ImageType::Pointer img)
{
  ImageType::RegionType region = img->GetLargestPossibleRegion();
  ImageType::SizeType regionSize = region.GetSize();
  minMax minmax;
  minmax.minimum=255;
  minmax.maximum=0;
  for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
      {
          for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
          {
            ImageType::IndexType pixelIndex;
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
//Uso: ./Filtro nombreSalida.extension  imgEntrada1 imgEntrada2 ... imgEntradaN \0
	unsigned int numberOfElementsOfTheArray = argc -2;
	std::string argvAux[argc];
	ImageType::Pointer image [argc]= ImageType::New();
	ImageType::Pointer average = ImageType::New();	
	ReaderType::Pointer lector = ReaderType::New();
	WriterType::Pointer escritor = WriterType::New();
	std::string outputImageName = argv[1];

	for(unsigned int rowIndex=2; rowIndex < (unsigned int) argc;rowIndex++)
	{
		lector->SetFileName(argv[rowIndex]);
		lector->Update();
		image[rowIndex-2]= lector->GetOutput();
	}
	//Getting the size of the region	
	ImageType::Pointer imageAux = ImageType::New();//image[0];
	ImageType::RegionType region = image[0]->GetLargestPossibleRegion();
	ImageType::SizeType regionSize = region.GetSize();	

	//Normalization of the first image
	/*for(unsigned int rowIndex=0; rowIndex< regionSize[0]; rowIndex++){
			for(unsigned int columnIndex=0; columnIndex< regionSize[1]; columnIndex++){
				ImageType::IndexType pixelIndex;
            	pixelIndex[0] = rowIndex;
            	pixelIndex[1] = columnIndex;
		imageAux->SetPixel(pixelIndex, (int) imageAux->GetPixel(pixelIndex) / numberOfElementsOfTheArray);
			}	
		}	
*/
	for(unsigned int imageIndex=0; imageIndex<numberOfElementsOfTheArray; imageIndex++){
		for(unsigned int rowIndex=0; rowIndex< regionSize[0]; rowIndex++){
			for(unsigned int columnIndex=0; columnIndex< regionSize[1]; columnIndex++){
		ImageType::IndexType pixelIndex;
            	pixelIndex[0] = rowIndex;
            	pixelIndex[1] = columnIndex;
		imageAux->SetPixel(pixelIndex,(int) imageAux->GetPixel(pixelIndex) + (image[imageIndex]->GetPixel(pixelIndex)/ numberOfElementsOfTheArray));
		std::cout<<"Image pixel value  " <<imageAux->GetPixel(pixelIndex) <<std::endl;
			}	
		}
	}
	
	minMax mm =  findMinAndMaxValues(imageAux);
	std::cout<<mm.minimum<< "  " <<mm.maximum;

	WriterType::Pointer writer = WriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(imageAux);
    writer->Update();
}
