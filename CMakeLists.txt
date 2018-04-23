cmake_minimum_required(VERSION 3.0)

project(CPP-DESIGN-PATTERNS VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")

find_package(Boost REQUIRED serialization system)
find_package(glfw3)
find_package(Freetype)
find_package(OpenGL)
find_package(GLEW)
find_package(Threads)
find_package(CppREST REQUIRED)
find_package(OpenSSL)

# message(STATUS "GLFW: ${GLFW_INCLUDE_DIRS}")
# get_cmake_property(_variableNames VARIABLES)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

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

# Creational Design Patterns
# ==========================

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

# Structural Design Patterns
# ==========================

# Adapter
add_executable(StackAdapter ${CMAKE_SOURCE_DIR}/2-Structural/1-Adapter/1-Stack/StructuralStack.cpp)
target_compile_features(StackAdapter PUBLIC cxx_std_14)

add_executable(StringAdapter ${CMAKE_SOURCE_DIR}/2-Structural/1-Adapter/2-String/StructuralString.cpp)
target_include_directories(StringAdapter PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(StringAdapter PUBLIC cxx_std_14)

# Bridge

add_executable(PersonPIMPL
  ${CMAKE_SOURCE_DIR}/2-Structural/2-Bridge/1-PimplIdiom/Person.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/2-Bridge/1-PimplIdiom/main.cpp)
target_compile_features(PersonPIMPL PUBLIC cxx_std_14)

add_executable(ShapeSizing ${CMAKE_SOURCE_DIR}/2-Structural/2-Bridge/2-ShapeSizing/ShapeSizing.cpp)
target_compile_features(ShapeSizing PUBLIC cxx_std_14)

# Composite

add_executable(Composite ${CMAKE_SOURCE_DIR}/2-Structural/3-Composite/1-ObjectCompositionAndIteration/composite.cpp)
target_compile_features(Composite PUBLIC cxx_std_14)

add_executable(CompositeGraphics ${CMAKE_SOURCE_DIR}/2-Structural/3-Composite/2-GeometricShapes/graphics.cpp)
target_compile_features(CompositeGraphics PUBLIC cxx_std_14)

# add_executable(Neurons ${CMAKE_SOURCE_DIR}/2-Structural/3-Composite/3-NeuralNetworks/neurons.cpp)
# target_compile_features(Neurons PUBLIC cxx_std_14)

add_executable(FunctionDecorator ${CMAKE_SOURCE_DIR}/2-Structural/4-Decorator/1-FunctionDecorator/functionDecorator.cpp)
target_compile_features(FunctionDecorator PUBLIC cxx_std_14)

add_executable(WrapperDecorator ${CMAKE_SOURCE_DIR}/2-Structural/4-Decorator/2-WrappingDecorator/wrappingDecorator.cpp)
target_compile_features(WrapperDecorator PUBLIC cxx_std_14)

add_executable(MixinDecorator ${CMAKE_SOURCE_DIR}/2-Structural/4-Decorator/3-MixinInheritance/mixinDecorator.cpp)
target_compile_features(MixinDecorator PUBLIC cxx_std_14)

add_executable(ImprovedMixinDecorator ${CMAKE_SOURCE_DIR}/2-Structural/4-Decorator/4-UsabilityImprovements/improvedDecorator.cpp)
target_compile_features(ImprovedMixinDecorator PUBLIC cxx_std_14)

# Façade

add_executable(BloomTerminal
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/Area.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/Bloom.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/MenuBar.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/ShaderUtils.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/TextBuffer.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/TextRenderer.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/TextureManager.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/Util.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/Viewport.cpp
  ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/Window.cpp)
target_include_directories(BloomTerminal PUBLIC ${FREETYPE_INCLUDE_DIR_ft2build} ${FREETYPE_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})
target_link_libraries(BloomTerminal glfw ${FREETYPE_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})
target_compile_features(BloomTerminal PUBLIC cxx_std_14)

# Flyweight

add_executable(Flyweight ${CMAKE_SOURCE_DIR}/2-Structural/6-Flyweight/flyweight.cpp)
target_include_directories(Flyweight PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(Flyweight ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(Flyweight PUBLIC cxx_std_14)

# Null Object
add_executable(NullObject ${CMAKE_SOURCE_DIR}/2-Structural/7-NullObject/nullobject.cpp)
target_include_directories(NullObject PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(NullObject PUBLIC cxx_std_14)

# Proxy

add_executable(SmartPointerProxy ${CMAKE_SOURCE_DIR}/2-Structural/8-Proxy/1-SmartPointerProxy/smartPointerProxy.cpp)
target_compile_features(SmartPointerProxy PUBLIC cxx_std_14)

add_executable(VirtualProxy ${CMAKE_SOURCE_DIR}/2-Structural/8-Proxy/2-VirtualProxy/virtualProxy.cpp)
target_compile_features(VirtualProxy PUBLIC cxx_std_14)

add_executable(CommunicationProxy ${CMAKE_SOURCE_DIR}/2-Structural/8-Proxy/3-CommunicationProxy/communicationProxy.cpp)
target_include_directories(CommunicationProxy PUBLIC ${CPP_REST_INCLUDE_DIR} ${OPENSSL_INCLUDE_DIR})
target_link_libraries(CommunicationProxy ${CPP_REST_LIBRARY} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})
target_compile_features(CommunicationProxy PUBLIC cxx_std_14)

# Behavioral Design Patterns
# ==========================

# Chain of Responsibilty

add_executable(CorPointer ${CMAKE_SOURCE_DIR}/3-Behavioral/01-ChainOfResponsibility/1-PointerChain/cor_pointer.cpp)
target_compile_features(CorPointer PUBLIC cxx_std_14)

add_executable(CorBroker ${CMAKE_SOURCE_DIR}/3-Behavioral/01-ChainOfResponsibility/2-BrokerChain/cor_broker.cpp)
target_include_directories(CorBroker PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(CorBroker PUBLIC cxx_std_14)

# Command

add_executable(Command ${CMAKE_SOURCE_DIR}/3-Behavioral/02-Command/command.cpp)
target_compile_features(Command PUBLIC cxx_std_14)

# Interpreter

add_executable(Interpreter ${CMAKE_SOURCE_DIR}/3-Behavioral/03-Interpreter/interpreter.cpp)
target_include_directories(Interpreter PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(Interpreter PUBLIC cxx_std_14)

# Iterator

add_executable(IteratorSTL ${CMAKE_SOURCE_DIR}/3-Behavioral/04-Iterator/1-IteratorSTL/iteratorSTL.cpp)
target_compile_features(IteratorSTL PUBLIC cxx_std_14)

add_executable(BinaryTreeIterator ${CMAKE_SOURCE_DIR}/3-Behavioral/04-Iterator/2-BinaryTreeIterator/binaryTreeIterator.cpp)
target_compile_features(BinaryTreeIterator PUBLIC cxx_std_14)

add_executable(IteratorFacade ${CMAKE_SOURCE_DIR}/3-Behavioral/04-Iterator/3-BoostIteratorFacade/facade.cpp)
target_include_directories(IteratorFacade PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(IteratorFacade PUBLIC cxx_std_14)

# Mediator

add_executable(Chatroom
  ${CMAKE_SOURCE_DIR}/3-Behavioral/05-Mediator/1-ChatRoom/chat.cpp
  ${CMAKE_SOURCE_DIR}/3-Behavioral/05-Mediator/1-ChatRoom/ChatRoom.cpp
  ${CMAKE_SOURCE_DIR}/3-Behavioral/05-Mediator/1-ChatRoom/Person.cpp)
target_compile_features(Chatroom PUBLIC cxx_std_14)

add_executable(EventBroker ${CMAKE_SOURCE_DIR}/3-Behavioral/05-Mediator/2-EventBroker/mediator.cpp)
target_include_directories(EventBroker PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(EventBroker PUBLIC cxx_std_14)

# Memento

add_executable(Memento ${CMAKE_SOURCE_DIR}/3-Behavioral/06-Memento/memento.cpp)
target_compile_features(Memento PUBLIC cxx_std_14)

# Observer

add_executable(Observer ${CMAKE_SOURCE_DIR}/3-Behavioral/07-Observer/1-BoostSignal2Observer/observer.cpp)
target_compile_features(Observer PUBLIC cxx_std_14)

add_executable(ObserverThreads ${CMAKE_SOURCE_DIR}/3-Behavioral/07-Observer/2-ThreadSafetyObserver/observer2.cpp)
target_include_directories(ObserverThreads PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(ObserverThreads PUBLIC cxx_std_14)

# State

add_executable(State ${CMAKE_SOURCE_DIR}/3-Behavioral/08-State/1-HandwrittenStateMachine/basic.cpp)
target_compile_features(State PUBLIC cxx_std_14)

add_executable(StateBoostMSM ${CMAKE_SOURCE_DIR}/3-Behavioral/08-State/2-BoostStateMachine/msm.cpp)
target_include_directories(StateBoostMSM PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(StateBoostMSM PUBLIC cxx_std_14)

# Strategy (Policy)

add_executable(StrategyStatic ${CMAKE_SOURCE_DIR}/3-Behavioral/09-Strategy/1-StaticStrategy/strategy_static.cpp)
target_compile_features(StrategyStatic PUBLIC cxx_std_14)

add_executable(StrategyDynamic ${CMAKE_SOURCE_DIR}/3-Behavioral/09-Strategy/2-DynamicStrategy/strategy_dynamic.cpp)
target_compile_features(StrategyDynamic PUBLIC cxx_std_14)

# Create compile database
add_custom_target(compile_commands ALL)

add_custom_command(
  TARGET compile_commands POST_BUILD
  COMMAND touch ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
  COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}
  COMMAND cp ${CMAKE_SOURCE_DIR}/1-Creational/5-Singleton/1-SingletonDatabase/capitals.txt ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND cp ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/consola.ttf ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND cp ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/text.f.glsl ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND cp ${CMAKE_SOURCE_DIR}/2-Structural/5-Façade/1-Bloom/text.v.glsl ${CMAKE_CURRENT_BINARY_DIR})

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  "${CMAKE_CURRENT_BINARY_DIR}/journal.txt"
  "${CMAKE_CURRENT_BINARY_DIR}/capitals.txt"
  "${CMAKE_CURRENT_BINARY_DIR}/consola.ttf"
  "${CMAKE_CURRENT_BINARY_DIR}/text.f.glsl"
  "${CMAKE_CURRENT_BINARY_DIR}/text.v.glsl")



