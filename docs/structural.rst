Structural Design Patterns
==========================

Adapter
^^^^^^^

Definition of Adapter: A construct which adapts an existing interface X to conform to a required interface Y.

* Electrical devices have different power (interface) requirements.

  * Voltage (5V, 220V)
  * Socket/plug type (Europe, UK, USA)

* We cannot modify our gadgets to support every possible interface.
* Thus, we use a device - an adapter - that gives us the interface we require.

* Implementing an Adapter is easy:

  * Determine the API you have and the API you need.
  * Create a component which aggregates (has a reference to, ...) the adaptee.
  * Intermediate representations can pile up. Use caching and other optimizations.

Stack
"""""

.. literalinclude:: ../2-Structural/1-Adapter/1-Stack/StructuralStack.cpp
   :language: cpp
   :caption: StructuralStack.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code StructuralStack.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/1-Adapter/1-Stack/StructuralStack.cpp>`_

String
""""""

.. literalinclude:: ../2-Structural/1-Adapter/2-String/StructuralString.cpp
   :language: cpp
   :caption: StructuralString.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code StructuralString.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/1-Adapter/2-String/StructuralString.cpp>`_

Bridge
^^^^^^

Definition of Bridge: A mechanism that decouples an interface (interface hierarchy) from an implementation (implementation hierarchy).

* Decouple abstraction from implementation.
* Both can exist as hierarchies.
* A stronger form of encapsulation.

PIMPL
"""""

PIMPL = **P**\ointer to an **IMPL**\ementation

`See also Pimpl For Compile-Time Encapsulation <https://msdn.microsoft.com/en-us/library/hh438477.aspx>`_

.. literalinclude:: ../2-Structural/2-Bridge/1-PimplIdiom/main.cpp
   :language: cpp
   :caption: main.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code main.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/2-Bridge/1-PimplIdiom/main.cpp>`_

Shape Sizing
""""""""""""

.. literalinclude:: ../2-Structural/2-Bridge/2-ShapeSizing/ShapeSizing.cpp
   :language: cpp
   :caption: ShapeSizing.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code ShapeSizing.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/2-Bridge/2-ShapeSizing/ShapeSizing.cpp>`_

Composite
^^^^^^^^^

Definition of Composite: A mechanism for treating individual (scalar) and compositions of objects in a uniform manner.

* Objects use other objects' fields and members through inheritance and composition.
* Composition lets us make compound objects.

  * A mathematical expression composed of simpler expressions
  * A grouping of shapes that make up several shapes

* Composite design pattern is used to treat both single and composite objects **uniformly** (i.e. with identical APIs)

* Objects can use either objects either via inheritance or composition.
* Some composed and singular objects need similar/identical behaviors.
* Composite design pattern lets us treat both types of objects uniformly.
* C++ has no special support for the idea of ‘enumeration’ of objects.
* **Trick:** A single object can *masquerade* to become suitable for begin/end iteration.

  * See Neural Network code which unfortunately compiles only under Windows.


Object Composition and Iteration
""""""""""""""""""""""""""""""""

.. literalinclude:: ../2-Structural/3-Composite/1-ObjectCompositionAndIteration/composite.cpp
   :language: cpp
   :caption: composite.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code composite.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/3-Composite/1-ObjectCompositionAndIteration/composite.cpp>`_

Geometric Shapes
""""""""""""""""

.. literalinclude:: ../2-Structural/3-Composite/2-GeometricShapes/graphics.cpp
   :language: cpp
   :caption: graphics.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code graphics.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/3-Composite/2-GeometricShapes/graphics.cpp>`_

