#include "BooleanMap.h"
#include "AttentionMap.h"

int main(int argc, char * argv[])
{
    int numberOfThresholds = atoi(argv[2]);
    std::list<int> lst = calculateListOfThresholds(numberOfThresholds);
    
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(argv[1]);
    reader->Update();

    std::list<UnsignedCharImageType::Pointer> lst2 = generateBooleanMaps(numberOfThresholds, reader->GetOutput());
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    int i=i;
    std::list<UnsignedCharImageType::Pointer> attList = AttentionMapsList(lst2);
    for(std::list<UnsignedCharImageType::Pointer>::iterator it = attList.begin(); it != attList.end() ; it++)
    {
        writer->SetFileName(std::to_string(i) +".png");
        writer->SetInput( *it );
        writer->Update();
        i++;
    }
}