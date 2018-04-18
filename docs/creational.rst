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

Prototype
^^^^^^^^^

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

.. `Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Builder/Builder.cpp>`_

Singleton
^^^^^^^^^

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

.. `Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Builder/Builder.cpp>`_
