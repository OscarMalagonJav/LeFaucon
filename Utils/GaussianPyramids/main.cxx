#include "GaussianPyramids.h"

int main(int argc, char * argv[])
{
    if(argc<5){
        std::cerr<<"Usage: "<<std::endl
        <<argv[0]<<" inputImage outputImage numberOfLevels maximumError (between 0.0 and 1.0)"<<std::endl;
        return EXIT_FAILURE;
    }

    std::string inputImageName = argv[1];
    std::string outputImageName = argv[2];
    int numberOfLevels = atoi(argv[3]);
    float maximumError = atof(argv[4]);

    std::list<UnsignedCharImageType::Pointer> levels = gaussianPyramid(inputImageName, numberOfLevels, maximumError);
    int i=0;
    for(std::list<UnsignedCharImageType::Pointer>::iterator it= levels.begin(); it != levels.end(); it++)
    {
        ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
        std::stringstream ss;
        ss << "pyramid_" << i << ".png";
        std::cout << "Writing " << ss.str() << std::endl;
        writer->SetFileName(ss.str());
        writer->SetInput(*it);
        writer->Update();
        i++;
    }
}