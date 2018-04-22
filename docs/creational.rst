Creational Design Patterns
==========================


Builder
^^^^^^^

When **piecewise** object construction is complicated, provide an API for doing it succinctly.

**Builder Example. Building a string:**

* Building a string out of substrings

  * e.g. web server page rendering

* Concatenate a single std::string

  * my_text += boost::lexical_cast<string>(my_int);

* printf("%s = %n", "meaning of life", 42);

* Boost.Format

  * format("%1%,x=%2% : %3%-th try") % "toto" % 40.23 % 50

* Represent as OO structure and implement operator<< on an object graph


Life without Builder
""""""""""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/1-LifeWithoutBuilder/LifeWithoutBuilder.cpp
   :language: cpp
   :caption: LifeWithoutBuilder.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code LifeWithoutBuilder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/1-LifeWithoutBuilder/LifeWithoutBuilder.cpp>`_


Builder
"""""""

A builder is a separate component with an API for building up a complex object. You can give the builder a public constructor or return it via a static function

.. literalinclude:: ../1-Creational/2_Builder/2-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/2-Builder/Builder.cpp>`_

Fluent Builder
""""""""""""""

To make a fluent builder, return *this* or *\*this*.

.. literalinclude:: ../1-Creational/2_Builder/3-FluentBuilder/FluentBuilder.cpp
   :language: cpp
   :caption: FluentBuilder.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code FluentBuilder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/3-FluentBuilder/FluentBuilder.cpp>`_

Groovy Style Builder
""""""""""""""""""""

Initializer lists let you implement Groovy-style builders with ease.

.. literalinclude:: ../1-Creational/2_Builder/4-GroovyStyleBuilder/GroovyStyle.cpp
   :language: cpp
   :caption: GroovyStyle.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code GroovyStyle.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/4-GroovyStyleBuilder/GroovyStyle.cpp>`_

Builder Facets
""""""""""""""

Different facets of an object can be built with different builders working in tandem.

.. literalinclude:: ../1-Creational/2_Builder/5-BuilderFacets/Facets.cpp
   :language: cpp
   :caption: Facets.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code Facets.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/5-BuilderFacets/Facets.cpp>`_

Factories
^^^^^^^^^

Definition Factory: A separate component responsible solely for the **wholesale** (**not piecewise**) creation of objects.

* Object creation logic becomes too convoluted
* Constructor is not descriptive

  * Name mandated by name of containing type
  * Cannot overload with same sets of arguments with different names
  * Can turn into ‘optional parameter hell’

* Object creation (**non-piecewise** unlike Builder) can be outsourced to

  * A separate function (**Factory Method**)
  * That may exist in a separate class (**Factory**)
  * You can even have a hierarchy of classes with **Abstract Factory**

* A factory method is a function that creates objects
* A factory can take care of object creation
* A factory can reside inside the object or be external
* Hierarchies of factories can be used to create related objects


Point Example
"""""""""""""

.. literalinclude:: ../1-Creational/3_Factories/1-PointExample/PointExample.cpp
   :language: cpp
   :caption: PointExample.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code PointExample.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/3_Factories/1-PointExample/PointExample.cpp>`_

Factory Method
""""""""""""""

A **function** that helps create objects. Like a constructor but more descriptive.

.. literalinclude:: ../1-Creational/3_Factories/2-FactoryMethod/FactoryMethod.cpp
   :language: cpp
   :caption: FactoryMethod.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code FactoryMethod.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/3_Factories/2-FactoryMethod/FactoryMethod.cpp>`_

Factory
"""""""

A **class** that helps create objects.

.. literalinclude:: ../1-Creational/3_Factories/3-Factory/Factory.cpp
   :language: cpp
   :caption: Factory.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code Factory.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/3_Factories/3-Factory/Factory.cpp>`_

Inner Factory
"""""""""""""

An **inner class** that helps create objects.

.. literalinclude:: ../1-Creational/3_Factories/4-InnerFactory/InnerFactory.cpp
   :language: cpp
   :caption: InnerFactory.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code InnerFactory.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/3_Factories/4-InnerFactory/InnerFactory.cpp>`_

Abstract Factory
""""""""""""""""
A factory construct used to construct object in hierarchies.

.. literalinclude:: ../1-Creational/3_Factories/5-AbstractFactory/AbstractFactory.cpp
   :language: cpp
   :caption: Builder.cpp AbstractFactory.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code AbstractFactory.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/3_Factories/5-AbstractFactory/AbstractFactory.cpp>`_

Functional Factory
""""""""""""""""""

Use of mappings from strings to factory functions.

.. literalinclude:: ../1-Creational/3_Factories/6-FunctionalFactory/FunctionalFactory.cpp
   :language: cpp
   :caption: FunctionalFactory.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code FunctionalFactory.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/3_Factories/6-FunctionalFactory/FunctionalFactory.cpp>`_

`See also definition of class DrinkWithVolumeFactory <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/3_Factories/6-FunctionalFactory/DrinkFactory.h>`_

Prototype
^^^^^^^^^

Definition of Prototype: A partially or fully initialized object that you copy/clone and make use of.

* Complicated objects (e.g. cars) aren’t designed from scratch

  * They reiterate existing designs

* An existing (partially constructed design) is a *Prototype*
* We make a copy/clone of the prototype and customize it

  * Requires ‘deep copy’ support
  * Painful without metadata!

* We make the cloning convenient (e.g. via a *Factory*)

* To implement a prototype, partially construct an object and store it somewhere
* Clone the prototype and then customize the instance
* Ensure deep copying! (Be careful of shallow copies esp. with respect to pointers!)


Prototype Factory
"""""""""""""""""

Use a factory to make prototypes more comfortable to use.

.. literalinclude:: ../1-Creational/4-Prototype/1-PrototypeFactory/Prototype.cpp
   :language: cpp
   :caption: Prototype.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code Prototype.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/4-Prototype/1-PrototypeFactory/Prototype.cpp>`_

Prototype with Boost Serialization
""""""""""""""""""""""""""""""""""

Use Boost Serialization for deep copying of protoype data.

.. literalinclude:: ../1-Creational/4-Prototype/2-BoostSerialization/Serialization.cpp
   :language: cpp
   :caption: Serialization.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code Serialization.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/4-Prototype/2-BoostSerializaton/Serialization.cpp>`_


Singleton
^^^^^^^^^

Definition of Singleton: A component which is instantiated only once.

*“When discussing which patterns to drop, we found that we still love them all. (Not really—I'm in favor of dropping Singleton. Its use is almost always a design smell.)” - Erich Gamma*

* For some components it only makes sense to have one in the system

  * Database repository
  * Object factory

* E.g. when the constructor call is expensive

  * We only do it once
  * We provide everyone with the same instance

* Want to prevent anyone creating additional copies
* Need to take care of lazy instantiation and multithreading

* A safe singleton is easy: just make a static variable and return a reference to it
* Singetons are difficult to test
* Consider defining singleton lifetime with a DI container

Singleton Database
""""""""""""""""""

.. literalinclude:: ../1-Creational/5-Singleton/1-SingletonDatabase/SingletonDatabase.cpp
   :language: cpp
   :caption: SingletonDatabase.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code SingletonDatabase.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/5-Singleton/1-SingletonDatabase/SingletonDatabase.cpp>`_
