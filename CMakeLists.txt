cmake_minimum_required(VERSION 3.0)

project(CPP-DESIGN-PATTERNS VERSION 0.0.1)

add_executable(SingleResponsibilityPrinciple ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/1-S-ingleResponsibilityPrinciple/SRP.cpp)
add_executable(OpenClosedPrinciple ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/2-O-penClosedPrinciple/OCP.cpp)
add_executable(LiskovSubstitutionPrinciple ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/3-L-iskovSubstitutionPrinciple/LSP.cpp)
add_executable(InterfaceSegregationPrinciple ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/4-I-nterfaceSegregationPrinciple/ISP.cpp)
add_executable(DependencyInjection ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/5-D-ependencyInjection/BoostDI.cpp)
add_executable(Builder ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/1-Builder/Builder.cpp)
target_compile_features(Builder PUBLIC cxx_std_14)
add_executable(FluentBuilder ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/2-FluentBuilder/FluentBuilder.cpp)
target_compile_features(FluentBuilder PUBLIC cxx_std_14)
add_executable(GroovyBuilder ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/3-GroovyStyleBuilder/GroovyStyle.cpp)
target_compile_features(GroovyBuilder PUBLIC cxx_std_14)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  "${CMAKE_CURRENT_BINARY_DIR}/journal.txt")
