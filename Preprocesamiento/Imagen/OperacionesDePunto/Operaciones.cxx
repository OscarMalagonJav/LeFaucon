#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkBinomialBlurImageFilter.h"
#include "itkImageRegionConstIterator.h"
#include <typeinfo>
int main(int argc, char * argv[])
{
  
  if( argc < 4 )
    {
    std::cerr << "Uso" << std::endl;
    std::cerr << argv[0] << " imagenEntrada nombreImagenSalida.extension operador(+,-,prom) valor" << std::endl;
    return EXIT_FAILURE;
    }

  //Argumentos
  std::string nombreIEntrada = argv[1];
  std::string nombreISalida = argv[2];
  std::string operador = argv[3];
  int valor = atoi(argv[4]);
  std::string seguir= "";
  std::cout<<"Parámetros"<<std::endl;
  std::cout<< "Imagen de entrada: "<< nombreIEntrada <<std::endl;
  std::cout<< "Imagen de salida.: "<< nombreISalida <<std::endl;
  std::cout<< "Operador.........: "<< operador <<std::endl;
  std::cout<< "Valor............: "<< valor <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continuar?...(Y/N)"<<std::endl;
  std::cin>>seguir;
  if(seguir=="y" || seguir=="Y")
  {

      typedef itk::Image< unsigned char, 2 >   imagenITK;
      typedef itk::ImageFileReader< imagenITK >  lector;
      typedef itk::ImageFileWriter<imagenITK> escritor;

      lector::Pointer l = lector::New();
      l->SetFileName( nombreIEntrada.c_str() );
      l->Update();
      imagenITK::Pointer imagenEntrada = l->GetOutput();
      imagenITK::Pointer nuevaImagen = imagenEntrada;
      imagenITK::RegionType region = imagenEntrada->GetLargestPossibleRegion();
      imagenITK::SizeType tam = region.GetSize();

      for(unsigned int r = 0; r < tam[0]; r++) //Itera sobre las filas
      {
          for(unsigned int c = 0; c < tam[1]; c++) //Itera sobre las columnas
          {
              imagenITK::IndexType pixelIndex;
              pixelIndex[0] = r;
              pixelIndex[1] = c;
    //          std::cout<<"Valor..."<<(int)nuevaImagen->GetPixel(pixelIndex)<<std::endl;
                if(operador=="+"){
                  if((int)nuevaImagen->GetPixel(pixelIndex) + valor > 255){
                    nuevaImagen->SetPixel(pixelIndex,255);
                  }else{
                    nuevaImagen->SetPixel(pixelIndex, ((int)nuevaImagen->GetPixel(pixelIndex) + valor));    
                  }  
                }else if(operador=="-"){
                  if((int)nuevaImagen->GetPixel(pixelIndex) - valor < 0){
                    nuevaImagen->SetPixel(pixelIndex,0);
                  }else{
                    nuevaImagen->SetPixel(pixelIndex, ((int)nuevaImagen->GetPixel(pixelIndex) - valor));    
                  }
                }
    //   std::cout<<"Nuevo..."<<(int)nuevaImagen->GetPixel(pixelIndex)<<std::endl;
          }
      }
      escritor::Pointer writer = escritor::New();
      writer->SetFileName(nombreISalida);
      writer->SetInput(nuevaImagen);
      writer->Update();
      return EXIT_SUCCESS;

  }else{
    
    return EXIT_FAILURE;
  
  }
}