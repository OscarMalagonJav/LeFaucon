#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImagePCAShapeModelEstimator.h"

  typedef itk::Image< unsigned char, 2 >   ImageType;
  typedef itk::ImageFileReader< ImageType >  ReaderType;
  typedef itk::ImageFileWriter<ImageType> WriterType;
  typedef itk::ImagePCAShapeModelEstimator<ImageType,ImageType > my_Estimatortype;

int main(int argc, char * argv[])
{
  
  
  //Argumentos
  //filtro imgsalida imgEntrada1 imgEntrada2...imgEntradaN
  unsigned int numberOfElementsOfTheArray = argc -2;
  ImageType::Pointer image [argc]= ImageType::New();
  ImageType::Pointer image2 = ImageType::New();
  ImageType::Pointer average = ImageType::New();	
  ReaderType::Pointer lector = ReaderType::New();
  WriterType::Pointer escritor = WriterType::New();
  std::string outputImageName = argv[1];
 
  for(unsigned int rowIndex=2; rowIndex < (unsigned int) argc;rowIndex++)
	{
		lector->SetFileName(argv[rowIndex]);
		lector->Update();
		image[rowIndex-2]= lector->GetOutput();
		lector = ReaderType::New();
		
	} 
   

   my_Estimatortype::Pointer filter = my_Estimatortype::New();
   filter->SetNumberOfTrainingImages(numberOfElementsOfTheArray);
   filter->SetNumberOfPrincipalComponentsRequired(2);

   for ( unsigned int k = 0; k < numberOfElementsOfTheArray; k++ )
    {
    filter->SetInput(k, image[k] );
    }
  filter->Update(); 
  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(outputImageName);
  writer->SetInput(filter->GetOutput());
  //writer->SetInput(ItkResultImage);
  writer->Update();
  return EXIT_SUCCESS;


}

