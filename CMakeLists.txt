cmake_minimum_required(VERSION 3.0)

project(CPP-DESIGN-PATTERNS VERSION 0.0.1)

find_package(Boost REQUIRED serialization)

# SOLID
add_executable(SingleResponsibilityPrinciple ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/1-S-ingleResponsibilityPrinciple/SRP.cpp)
target_compile_features(SingleResponsibilityPrinciple PUBLIC cxx_std_14)

add_executable(OpenClosedPrinciple ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/2-O-penClosedPrinciple/OCP.cpp)
target_compile_features(OpenClosedPrinciple PUBLIC cxx_std_14)

add_executable(LiskovSubstitutionPrinciple ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/3-L-iskovSubstitutionPrinciple/LSP.cpp)
target_compile_features(LiskovSubstitutionPrinciple PUBLIC cxx_std_14)

add_executable(InterfaceSegregationPrinciple ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/4-I-nterfaceSegregationPrinciple/ISP.cpp)
target_compile_features(InterfaceSegregationPrinciple PUBLIC cxx_std_14)

add_executable(DependencyInjection ${CMAKE_SOURCE_DIR}/1-Creational/1-Design-Principles/1-SOLID/5-D-ependencyInjection/BoostDI.cpp)
target_compile_features(DependencyInjection PUBLIC cxx_std_14)

# Builder
add_executable(LifeWithoutBuilder ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/1-LifeWithoutBuilder/LifeWithoutBuilder.cpp)
target_compile_features(LifeWithoutBuilder PUBLIC cxx_std_14)

add_executable(Builder ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/2-Builder/Builder.cpp)
target_compile_features(Builder PUBLIC cxx_std_14)

add_executable(FluentBuilder ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/3-FluentBuilder/FluentBuilder.cpp)
target_compile_features(FluentBuilder PUBLIC cxx_std_14)

add_executable(GroovyBuilder ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/4-GroovyStyleBuilder/GroovyStyle.cpp)
target_compile_features(GroovyBuilder PUBLIC cxx_std_14)

add_executable(BuilderFacets
  ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/5-BuilderFacets/Facets.cpp
  ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/5-BuilderFacets/PersonBuilder.cpp
  ${CMAKE_SOURCE_DIR}/1-Creational/2_Builder/5-BuilderFacets/Person.cpp
)
target_compile_features(BuilderFacets PUBLIC cxx_std_14)

# Factories

add_executable(PointExample ${CMAKE_SOURCE_DIR}/1-Creational/3_Factories/1-PointExample/PointExample.cpp)
target_compile_features(PointExample PUBLIC cxx_std_14)

add_executable(FactoryMethod ${CMAKE_SOURCE_DIR}/1-Creational/3_Factories/2-FactoryMethod/FactoryMethod.cpp)
target_compile_features(FactoryMethod PUBLIC cxx_std_14)

add_executable(Factory ${CMAKE_SOURCE_DIR}/1-Creational/3_Factories/3-Factory/Factory.cpp)
target_compile_features(Factory PUBLIC cxx_std_14)

add_executable(InnerFactory ${CMAKE_SOURCE_DIR}/1-Creational/3_Factories/4-InnerFactory/InnerFactory.cpp)
target_compile_features(InnerFactory PUBLIC cxx_std_14)

add_executable(AbstractFactory ${CMAKE_SOURCE_DIR}/1-Creational/3_Factories/5-AbstractFactory/AbstractFactory.cpp)
target_compile_features(AbstractFactory PUBLIC cxx_std_14)

add_executable(FunctionalFactory ${CMAKE_SOURCE_DIR}/1-Creational/3_Factories/6-FunctionalFactory/FunctionalFactory.cpp)
target_compile_features(FunctionalFactory PUBLIC cxx_std_14)

# Prototypes

add_executable(PrototypeFactory ${CMAKE_SOURCE_DIR}/1-Creational/4-Prototype/1-PrototypeFactory/Prototype.cpp)
target_compile_features(PrototypeFactory PUBLIC cxx_std_14)

add_executable(PrototypeSerialization ${CMAKE_SOURCE_DIR}/1-Creational/4-Prototype/2-BoostSerialization/Serialization.cpp)
target_include_directories(PrototypeSerialization PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(PrototypeSerialization ${Boost_LIBRARIES})
target_compile_features(PrototypeSerialization PUBLIC cxx_std_14)

# Singleton
add_executable(SingletonDatabase ${CMAKE_SOURCE_DIR}/1-Creational/5-Singleton/1-SingletonDatabase/SingletonDatabase.cpp)
target_include_directories(SingletonDatabase PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(SingletonDatabase PUBLIC cxx_std_14)

add_custom_target(compile_commands ALL)

add_custom_command(
  TARGET compile_commands POST_BUILD
  COMMAND touch ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
  COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}
  COMMAND cp ${CMAKE_SOURCE_DIR}/1-Creational/5-Singleton/1-SingletonDatabase/capitals.txt ${CMAKE_CURRENT_BINARY_DIR})

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  "${CMAKE_CURRENT_BINARY_DIR}/journal.txt"
  "${CMAKE_CURRENT_BINARY_DIR}/capitals.txt")



