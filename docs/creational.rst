Creational Design Patterns
==========================


Builder
^^^^^^^

When piecewise object construction is complicated, provide an API for doing it succinctly.

**Builder Examples**

* Building a string out of substrings

  * e.g. web server page rendering

* Concatenate a single std::string

  * my_text += boost::lexical_cast<string>(my_int);

* printf("%s = %n", "meaning of life", 42);

* Boost.Format

  * format("%1%,x=%2% : %3%-th try") % "toto" % 40.23 % 50

* Represent as OO structure and implement operator<< on an object graph



Builder
"""""""

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/1-Builder/Builder.cpp>`_

Fluent Builder
""""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/2-FluentBuilder/FluentBuilder.cpp
   :language: cpp
   :caption: FluentBuilder.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code FluentBuilder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/2-FluentBuilder/FluentBuilder.cpp>`_

Groovy Style Builder
""""""""""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/3-GroovyStyleBuilder/GroovyStyle.cpp
   :language: cpp
   :caption: GroovyStyle.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code GroovyStyle.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/3-GroovyStyleBuilder/GroovyStyle.cpp>`_

Builder Facets
""""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/4-BuilderFacets/Facets.cpp
   :language: cpp
   :caption: Facets.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code Facets.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/2_Builder/4-BuilderFacets/Facets.cpp>`_

Factories
^^^^^^^^^

Point Example
"""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

.. `Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Builder/Builder.cpp>`_

Factory Method
""""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

.. `Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Builder/Builder.cpp>`_

Factory
"""""""

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

.. `Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Builder/Builder.cpp>`_

Inner Factory
"""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

.. `Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Builder/Builder.cpp>`_

Abstract Factory
""""""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

.. `Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Builder/Builder.cpp>`_

Functional Factory
""""""""""""""""""

.. literalinclude:: ../1-Creational/2_Builder/1-Builder/Builder.cpp
   :language: cpp
   :caption: Builder.cpp
   :start-after: int main() {
   :end-before: return 0

.. `Full source code Builder.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Builder/Builder.cpp>`_

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
