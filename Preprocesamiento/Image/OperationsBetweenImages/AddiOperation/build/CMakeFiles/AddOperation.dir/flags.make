# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# compile CXX with /usr/bin/c++
CXX_FLAGS =  -Wall -std=gnu++0x   

CXX_DEFINES = -DITK_IO_FACTORY_REGISTER_MANAGER

CXX_INCLUDES = -I/home/andres/Escritorio/LeFaucon/LeFaucon/Preprocesamiento/Image/OperationsBetweenImages/AddiOperation/build/ITKIOFactoryRegistration -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Remote/ParabolicMorphology/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Video/IO/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Video/Filtering/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Video/Core/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/TestKernel/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Nonunit/Review/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/Watersheds/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/Voronoi/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Bridge/VTK/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/SpatialFunction/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Registration/RegistrationMethodsv4/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/RegionGrowing/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/QuadEdgeMeshFiltering/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/OpenJPEG/src/openjpeg -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/OpenJPEG/src/openjpeg -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Numerics/NeuralNetworks/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Registration/Metricsv4/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Numerics/Optimizersv4/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/MarkovRandomFieldsClassifiers/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/LevelSetsv4/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/LabelVoting/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/KLMRegionGrowing/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageNoise/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageFusion/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/VTK/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/TransformMatlab/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/TransformInsightLegacy/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/TransformHDF5/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/TransformBase/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/Stimulate/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/Siemens/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/RAW/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/PNG/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/PNG/src -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/PNG/src -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/NRRD/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/NrrdIO/src/NrrdIO -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/NrrdIO/src/NrrdIO -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/NIFTI/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/Meta/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/Mesh/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/MRC/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/LSM/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/TIFF/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/TIFF/src -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/TIFF/src/itktiff -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/TIFF/src -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/JPEG/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/JPEG/src -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/JPEG/src -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/HDF5/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/GIPL/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/GE/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/IPL/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/GDCM/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/CSV/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/BioRad/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/BMP/include -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/HDF5/src -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/HDF5/src -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/GPUThresholding/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/GPUSmoothing/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Registration/GPUPDEDeformable/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Registration/GPUCommon/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/GPUImageFilterBase/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/GPUAnisotropicSmoothing/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/GPUFiniteDifference/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/GPUCommon/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/GIFTI/src/gifticlib -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/NIFTI/src/nifti/znzlib -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/NIFTI/src/nifti/niftilib -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/GDCM/src/gdcm/Source/Common -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/GDCM/src/gdcm/Source/DataDictionary -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MediaStorageAndFileFormat -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/GDCM/src/gdcm/Source/Common -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/GDCM -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Registration/FEM/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Registration/PDEDeformable/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Numerics/FEM/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Registration/Common/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/SpatialObjects/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/XML/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/Expat/src/expat -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/Expat/src/expat -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Numerics/Eigen/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/DisplacementField/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/DiffusionTensorImage/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/Denoising/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/DeformableMesh/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/Deconvolution/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/DICOMParser/src/DICOMParser -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/DICOMParser/src/DICOMParser -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/Convolution/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/FFT/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/Colormap/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/Classifiers/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/BioCell/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/BiasCorrection/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Numerics/Polynomials/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/AntiAlias/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/LevelSets/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/SignedDistanceFunction/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Numerics/Optimizers/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageFeature/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageSources/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageGradient/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/Smoothing/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageCompare/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/IO/ImageBase/include -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/IO/ImageBase -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/FastMarching/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/QuadEdgeMesh/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/DistanceMap/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Numerics/NarrowBand/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageLabel/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/BinaryMathematicalMorphology/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/MathematicalMorphology/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Segmentation/ConnectedComponents/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/Thresholding/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageIntensity/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/Path/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageStatistics/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/SpatialObjects/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/MetaIO/src/MetaIO/src -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/MetaIO/src/MetaIO/src -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/ZLIB/src -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/ZLIB/src -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/Mesh/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageCompose/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/LabelMap/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/AnisotropicSmoothing/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageGrid/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/ImageFunction/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/Transform/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Numerics/Statistics/include -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/Netlib -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/ImageAdaptors/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/CurvatureFlow/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Filtering/ImageFilterBase/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/FiniteDifference/include -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/Core/Common/include -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/Core/Common -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/VNLInstantiation/include -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/VNL/src/vxl/core -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/VNL/src/vxl/vcl -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/VNL/src/vxl/v3p/netlib -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/VNL/src/vxl/core -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/VNL/src/vxl/vcl -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/VNL/src/vxl/v3p/netlib -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/KWSys/src -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/KWIML/src -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/KWIML/src -I/home/andres/Escritorio/InsightToolkit-4.9.1-build/Modules/ThirdParty/DoubleConversion/src/double-conversion -I/home/andres/Escritorio/InsightToolkit-4.9.1/Modules/ThirdParty/DoubleConversion/src/double-conversion 

