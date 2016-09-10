#include "GaussianPyramids.h"

int main(int argc, char * argv[])
{
    if(argc<4){
        std::cerr<<"Usage: "<<std::endl
        <<argv[0]<<" inputImage outputImage numberOfLevels"<<std::endl;
        return EXIT_FAILURE;
    }

    std::string inputImageName = argv[1];
    std::string outputImageName = argv[2];
    int level = atoi(argv[3]);
    UnsignedCharImageType::Pointer pyramid = gaussianPyramid(inputImageName, level);
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(pyramid);
    writer->Update();
    std::cout<< pyramid;
}