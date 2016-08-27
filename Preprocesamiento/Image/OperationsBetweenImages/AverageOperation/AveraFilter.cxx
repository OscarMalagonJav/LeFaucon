#include "AverageFilter.h"

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

ItkImageType::Pointer applyAverageImage(int argc, char * argv[])
{
	unsigned int numberOfElementsOfTheArray = argc -2;
	std::string argvAux[argc];
	ImageType::Pointer image [argc]= ImageType::New();
	ImageType::Pointer image2 = ImageType::New();
	ImageType::Pointer average = ImageType::New();	
	ReaderType::Pointer lector = ReaderType::New();
	WriterType::Pointer escritor = WriterType::New();
	

	for(unsigned int rowIndex=2; rowIndex < (unsigned int) argc;rowIndex++)
	{
		lector->SetFileName(argv[rowIndex]);
		lector->Update();
		image[rowIndex-2]= lector->GetOutput();
		lector = ReaderType::New();
	}
	//Getting the size of the region	
	ImageType::Pointer imageAux = image[0];
	ImageType::RegionType region = imageAux->GetLargestPossibleRegion();
	ImageType::SizeType regionSize = region.GetSize();	

	//Normalization of the first image
	for(unsigned int rowIndex=0; rowIndex< regionSize[0]; rowIndex++){
			for(unsigned int columnIndex=0; columnIndex< regionSize[1]; columnIndex++){
				ImageType::IndexType pixelIndex;
            	pixelIndex[0] = rowIndex;
            	pixelIndex[1] = columnIndex;
				imageAux->SetPixel(pixelIndex, (int) imageAux->GetPixel(pixelIndex) / numberOfElementsOfTheArray);
			}	
		}	

	for(unsigned int imageIndex; imageIndex<numberOfElementsOfTheArray; imageIndex++){
		for(unsigned int rowIndex=0; rowIndex< regionSize[0]; rowIndex++){
			for(unsigned int columnIndex=0; columnIndex< regionSize[1]; columnIndex++){
				ImageType::IndexType pixelIndex;
            	pixelIndex[0] = rowIndex;
            	pixelIndex[1] = columnIndex;
				imageAux->SetPixel(pixelIndex,(int) imageAux->GetPixel(pixelIndex) + (image[imageIndex]->GetPixel(pixelIndex)/ numberOfElementsOfTheArray));
			}	
		}
	}
	
	RescaleFilterType::Pointer rescaleFilter = RescaleFilterType::New();
	rescaleFilter->SetInput(imageAux);
	rescaleFilter->SetOutputMinimum(0);
  	rescaleFilter->SetOutputMaximum(255);
	rescaleFilter->Update();

	return rescaleFilter->GetOutput();
}