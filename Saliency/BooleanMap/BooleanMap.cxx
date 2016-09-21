#include "BooleanMap.h"
#include "booleanMapTypes.h"

std::list<UnsignedCharImageType::Pointer> generateBooleanMaps(std::list<std::string> listOfFeatureImagesPath, std::list<int> listOfThreshold)
{
    std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps;
    std::list<UnsignedCharImageType::Pointer> listOfFeatureImages = loadFeatureImages(listOfFeatureImagesPath);
    
    std::list<UnsignedCharImageType::Pointer>::iterator itFeatures = listOfFeatureImages.begin();
    std::list<std::string>::iterator itThreshold = listOfThreshold.begin();

    //The region assumes that the size of all the region's images is the same
    UnsignedCharImageType::RegionType region = *itFeatures->GetLargestPossibleRegion(); 
    UnsignedCharImageType::SizeType regionSize = region.GetSize();

    for(itThreshold; itThreshold != listOfThreshold.end(); itThreshold++)
    {
        for(itFeatures; itFeatures != listOfFeatureImages.end(); itFeatures++)
        {
            UnsignedCharImageType::Pointer temporalImage = UnsignedCharImageType::New();
            for(unsigned int rowIndex = 0; rowIndex< regionSize[0]; rowIndex++)
            {
                for(unsigned int columnIndex =0; columnIndex  < regionSize[1]; columnIndex++)
                {
                    UnsignedCharImageType::IndexType pixelIndex;
                    pixelIndex[0] = rowIndex;
                    pixelIndex[1] = columnIndex;
                    if((int) *itFeatures->GetPixel(pixelIndex)>= *itThreshold )
                    {
                        temporalImage->SetPixel(pixelIndex,255);
                    }else{
                        temporalImage->SetPixel(pixelIndex,0);
                    }
                }
            }
            temporalImage->Update();
            listOfBooleanMaps.insert(temporalImage->GetOutput());
        }
    }
    return listOfBooleanMaps;
}


std::list<UnsignedCharImageType::Pointer> loadFeatureImages(std::list<std::string> listOfFeatureImagesPath)
{
    std::list<UnsignedCharImageType::Pointer> listOfImages;
    std::list<std::string>::iterator itImagesPath = listOfFeatureImagesPath.begin();   
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    for(itImagesPath; itImagesPath != listOfFeatureImagesPath.end() ; itImagesPath++ )
    {
        reader->SetFileName(*itImagesPath);
        reader->Update();
        listOfImages.insert(reader->GetOutput());
    }
    return listOfImages;
}