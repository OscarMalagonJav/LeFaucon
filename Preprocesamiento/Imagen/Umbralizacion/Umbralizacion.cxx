#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include <typeinfo>
int main(int argc, char * argv[])
{
  
  if( argc < 3 )
    {
    std::cerr << "Uso" << std::endl;
    std::cerr << argv[0] << " imagenEntrada nombreImagenSalida.extension umbral" << std::endl;
    return EXIT_FAILURE;
    }

  std::string nombreIEntrada = argv[1];
  std::string nombreISalida = argv[2];
  int umbral = atoi(argv[3]);

  std::string seguir= "";
  std::cout<<"Parámetros"<<std::endl;
  std::cout<< "Imagen de entrada: "<< nombreIEntrada <<std::endl;
  std::cout<< "Imagen de salida.: "<< nombreISalida <<std::endl;
  std::cout<< "Umbral: "<< umbral <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continuar?...(Y/N)"<<std::endl;
  std::cin>>seguir;
  if(seguir=="y" || seguir=="Y"){
    typedef itk::Image<unsigned char, 2 > imagenItk;    
    typedef itk::ImageFileReader<imagenItk> lector;
    typedef itk::ImageFileWriter<imagenItk> escritor;



    lector::Pointer l = lector::New();
    l->SetFileName(nombreIEntrada);
    l->Update();
    imagenItk::Pointer imagenEntrada = l->GetOutput();
    imagenItk::Pointer imagenSalida = imagenEntrada;
    imagenItk::RegionType region = imagenEntrada->GetLargestPossibleRegion();
    imagenItk::SizeType tam = region.GetSize();
    for(unsigned int r = 0; r < tam[0]; r++) //Itera sobre las filas
      {
          for(unsigned int c = 0; c < tam[1]; c++) //Itera sobre las columnas
          {
            imagenItk::IndexType pixelIndex;
            pixelIndex[0] = r;
            pixelIndex[1] = c;
            if((int)imagenEntrada->GetPixel(pixelIndex)>=umbral)
            {
              std::cout<< imagenEntrada->GetPixel(pixelIndex)<<std::endl;
              imagenSalida->SetPixel(pixelIndex,(int)imagenEntrada->GetPixel(pixelIndex));
            }else{
              imagenSalida->SetPixel(pixelIndex,0);
            }
          }
      }

    escritor::Pointer esc = escritor::New();
    esc->SetFileName(nombreISalida);
    esc->SetInput(imagenSalida);
    esc->Update();

    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}