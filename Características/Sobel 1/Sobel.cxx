#include "Sobel.h"

ItkUnsignedCharImageType::Pointer applySobel(std::string inputImage)
{
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputImage);

    SobelFilterType::Pointer SobelFilterType = SobelFilterType::New();
    SobelFilterType->SetInput( reader->GetOutput() );
    
    CastFilterType::Pointer castFilter = CastFilterType::New();
    castFilter->SetInput(SobelFilterType->GetOutput());	
    castFilter->Update();
    return castFilter->GetOutput();
}
