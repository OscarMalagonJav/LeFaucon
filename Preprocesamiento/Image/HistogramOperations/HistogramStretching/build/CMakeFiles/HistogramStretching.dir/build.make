# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/build

# Include any dependencies generated for this target.
include CMakeFiles/HistogramStretching.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HistogramStretching.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HistogramStretching.dir/flags.make

CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o: CMakeFiles/HistogramStretching.dir/flags.make
CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o: ../HistogramStretching.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o -c /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/HistogramStretching.cxx

CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/HistogramStretching.cxx > CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.i

CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/HistogramStretching.cxx -o CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.s

CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o.requires:

.PHONY : CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o.requires

CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o.provides: CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o.requires
	$(MAKE) -f CMakeFiles/HistogramStretching.dir/build.make CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o.provides.build
.PHONY : CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o.provides

CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o.provides.build: CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o


# Object files for target HistogramStretching
HistogramStretching_OBJECTS = \
"CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o"

# External object files for target HistogramStretching
HistogramStretching_EXTERNAL_OBJECTS =

HistogramStretching: CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o
HistogramStretching: CMakeFiles/HistogramStretching.dir/build.make
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkdouble-conversion-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitksys-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkvnl_algo-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkvnl-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkv3p_netlib-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKCommon-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkNetlibSlatec-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKStatistics-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKTransform-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKLabelMap-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKMesh-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkzlib-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKMetaIO-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKSpatialObjects-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKPath-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKQuadEdgeMesh-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOImageBase-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKOptimizers-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKPolynomials-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKBiasCorrection-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKBioCell-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKDICOMParser-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKEXPAT-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOXML-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOSpatialObjects-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKFEM-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmDICT-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmMSFF-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKznz-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKniftiio-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKgiftiio-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkhdf5_cpp-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkhdf5-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOBMP-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOBioRad-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOCSV-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOGDCM-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOIPL-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOGE-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOGIPL-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOHDF5-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkjpeg-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOJPEG-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitktiff-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOTIFF-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOLSM-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOMRC-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOMesh-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOMeta-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIONIFTI-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKNrrdIO-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIONRRD-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkpng-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOPNG-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOSiemens-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOStimulate-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOTransformBase-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOTransformHDF5-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOTransformInsightLegacy-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOTransformMatlab-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOVTK-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKKLMRegionGrowing-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKOptimizersv4-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKVTK-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKVideoCore-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKVideoIO-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKWatersheds-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOXML-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmMSFF-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmDICT-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmIOD-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmDSED-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmCommon-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmjpeg8-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmjpeg12-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmjpeg16-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmopenjpeg-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmcharls-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkgdcmuuid-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOTIFF-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitktiff-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkjpeg-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKgiftiio-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKEXPAT-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKMetaIO-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKniftiio-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKznz-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKNrrdIO-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkpng-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOIPL-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkhdf5_cpp-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkhdf5-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkzlib-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOTransformBase-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKOptimizers-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKIOImageBase-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKVideoCore-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKStatistics-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkNetlibSlatec-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKSpatialObjects-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKMesh-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKTransform-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKPath-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKCommon-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkdouble-conversion-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitksys-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libITKVNLInstantiation-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkvnl_algo-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkv3p_lsqr-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkvnl-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkvcl-4.9.a
HistogramStretching: /home/oscarmalagon/Escritorio/ITK/lib/libitkv3p_netlib-4.9.a
HistogramStretching: CMakeFiles/HistogramStretching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HistogramStretching"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HistogramStretching.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HistogramStretching.dir/build: HistogramStretching

.PHONY : CMakeFiles/HistogramStretching.dir/build

CMakeFiles/HistogramStretching.dir/requires: CMakeFiles/HistogramStretching.dir/HistogramStretching.cxx.o.requires

.PHONY : CMakeFiles/HistogramStretching.dir/requires

CMakeFiles/HistogramStretching.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HistogramStretching.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HistogramStretching.dir/clean

CMakeFiles/HistogramStretching.dir/depend:
	cd /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/build /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/build /home/oscarmalagon/Escritorio/LeFaucon/Preprocesamiento/Image/HistogramOperations/HistogramStretching/build/CMakeFiles/HistogramStretching.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HistogramStretching.dir/depend
