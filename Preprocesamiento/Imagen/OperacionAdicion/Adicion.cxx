#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImage.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkAddImageFilter.h"
#include <typeinfo>

typedef itk::Image<unsigned char, 2>  ImageType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::AddImageFilter <ImageType, ImageType, ImageType > AddImageFilterType;


int main(int argc, char * argv[])
{
	//Uso: ./Filtro nombreSalida.extension imgEntrada1 imgEntrada2 ... imgEntradaN
	ImageType::Pointer image1 = ImageType::New();
	ImageType::Pointer image2 = ImageType::New();
  	ReaderType::Pointer lector = ReaderType::New();
  	WriterType::Pointer escritor = WriterType::New();

	std::string img1 = argv[2];
	std::string img2 = argv[3];
	std::string imgSalida = argv[1];

	lector->SetFileName(img1.c_str());
	lector->Update();
	image1 = lector->GetOutput();
	lector->SetFileName(img2.c_str());
	lector->Update();
	image2 = lector->GetOutput();

	
	AddImageFilterType::Pointer addFilter = AddImageFilterType::New ();
  	addFilter->SetInput1(image1);
  	addFilter->SetInput2(image2);
  	addFilter->Update();

	escritor->SetFileName(imgSalida);
	escritor->SetInput(addFilter->GetOutput());
	escritor->Update();

	
	return EXIT_SUCCESS;  
}

