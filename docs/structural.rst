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

  * See Neural Network code which unfortunately compiles only under Microsoft Windows.
  * `Link to Neurons code. <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/3-Composite/3-NeuralNetworks/neurons.cpp>`_

  .. literalinclude:: ../2-Structural/3-Composite/3-NeuralNetworks/neurons.cpp
     :language: cpp
     :lines: 30-32

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

Decorator
^^^^^^^^^
Definition of Decorator: Allows for adding behavior to individual objects without affecting the behavior of other objects of the same class.

* Want to augment existing functionality.
* Do not want to rewrite or alter existing code (Open-Closed Principle).
* Want to keep new functionality separate (Single Responsibility Principle)
* Need to be able to interact with existing structures

* Functional decorators let you wrap functions with before/after code (e.g. for logging).
* An aggregate decorator does not give you the underlying object’s features, but can be composed at runtime.
* A decorator based on mixin inheritance is more flexible, exposes underlying object's features, but is only constructible at compile time because of implementation as C++ template functions.

Function Decorator
""""""""""""""""""

.. literalinclude:: ../2-Structural/4-Decorator/1-FunctionDecorator/functionDecorator.cpp
   :language: cpp
   :caption: functionDecorator.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code functionDecorator.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/4-Decorator/1-FunctionDecorator/functionDecorator.cpp>`_

Wrapping Decorator
""""""""""""""""""

.. literalinclude:: ../2-Structural/4-Decorator/2-WrappingDecorator/wrappingDecorator.cpp
   :language: cpp
   :caption: wrappingDecorator.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code wrappingDecorator.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/4-Decorator/2-WrappingDecorator/wrappingDecorator.cpp>`_

Mixin Decorator
"""""""""""""""

.. literalinclude:: ../2-Structural/4-Decorator/3-MixinInheritance/mixinDecorator.cpp
   :language: cpp
   :caption: mixinDecorator.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code mixinDecorator.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/4-Decorator/3-MixinInheritance/mixinDecorator.cpp>`_

Improved Decorator
""""""""""""""""""

.. literalinclude:: ../2-Structural/4-Decorator/4-UsabilityImprovements/improvedDecorator.cpp
   :language: cpp
   :caption: improvedDecorator.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code improvedDecorator.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/4-Decorator/4-UsabilityImprovements/improvedDecorator.cpp>`_

Façade
^^^^^^

Definition of Façade: Provides a simple, easy to understand/use interface over a large and sophisticated body of code.

* Balancing complexity and presentation/usability.
* Typical home:

  * Many subsystems (electrical, sanitation).
  * Complex internal structure (e.g. floor layers).
  * End user not exposed to internals.

* Same with software!

  * Many systems working together provide flexibility, but...
  * API consumers want it to 'just work'.

* Make a library easier to understand, use and test.
* Reduce dependencies of user code on internal APIs that may change.

  * Allows more flexibility in developing/refactoring the library.

* Wrap a poorly designed collection of APIs with a single well-designed API.
* Build a Façade to provide a simplified API over a set of classes.
* May wish to (optionally) expose internals though the façade.
* May allow users to ‘escalate’ to use more complex APIs if they need to.

Bloom Terminal
""""""""""""""

.. literalinclude:: ../2-Structural/5-Façade/1-Bloom/Bloom.cpp
   :language: cpp
   :caption: Bloom.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code Bloom.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/5-Façade/1-Bloom/Bloom.cpp>`_

Flyweight
^^^^^^^^^

Definition of Flyweight: A space optimization technique that lets us use less memory by storing externally the data associated with similar objects.

* Avoiding redundancy when storing data, e.g. MMORPG:

  * Plenty of users with identical first/last names
  * No sense in storing same first/last name over and over again
  * Store a list of names and pointers to them

* Bold or italic text in the console:

  * Don't want each character to have an extra formatting character.
  * Operate on ranges (e.g. line, start/end).

First/Last Name
"""""""""""""""

.. literalinclude:: ../2-Structural/6-Flyweight/flyweight.cpp
   :language: cpp
   :caption: flyweight.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code flyweight.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/6-Flyweight/flyweight.cpp>`_

Null Object
^^^^^^^^^^^

Definition of Null Object: A no-op object that satisfies the dependency requirement of some other object.

* When component A uses component B, if typically assumes that B is actually present.

  * You inject B, not e.g. optional<B>.
  * You do not inject a pointer and then check for nullptr everywhere.

* There is no option of telling A not to use an instance of B.

  * Its use is hard-coded.

* Thus, we build a no-op, non-functioning inheritor of B and pass that into A.
* Structural or Behavioral design pattern?
* Inherit from the required object.
* Implement the functions with empty bodies.

  * Return default values.
  * If those values are used, you are in trouble.

* Supply an instance of the Null Object in lieu of an actual object.

Null Logger
"""""""""""

.. literalinclude:: ../2-Structural/7-NullObject/nullobject.cpp
   :language: cpp
   :caption: nullobject.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code nullobject.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/7-NullObject/nullobject.cpp>`_

Proxy
^^^^^

Definition of Proxy: A class that is functioning as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging or some other added functionality.

* You are calling foo.bar().
* This assumes that foo resides in the same process as bar.
* What if, later on, you want to put all Foo related operations into a separate process?

  * How can you avoid changing all your code?

* Proxy to the rescue!

  * Same interface, entirely different behavior.

* This is an example for a communication proxy.

  * There are many others: logging, virtual, guarding,...

* How is Proxy different from Decorator?

  * Proxy provides an identical interface; decorator provides an enhanced interface.
  * Decorator typically aggregates (or has reference to) what it is decorating; proxy doesn't have to.
  * Proxy might not even be working with a materialized object.

* A proxy has the same interface as the underlying object.
* To create a proxy, simply replicate the existing interface of an object.
* Add relevant functionality to the redefined member functions.

  * As well as constructor, destructor, etc.

* Different proxies (communication, logging, caching, etc.) have completely different behaviors.


Smart Pointer Proxy
"""""""""""""""""""

Smart pointers from the standard library don't need an explicit delete. Smart pointers are proxies for underlying raw pointers.

.. literalinclude:: ../2-Structural/8-Proxy/1-SmartPointerProxy/smartPointerProxy.cpp
   :language: cpp
   :caption: smartPointerProxy.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code smartPointerProxy.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/8-Proxy/1-SmartPointerProxy/smartPointerProxy.cpp>`_

Virtual Proxy
"""""""""""""

.. literalinclude:: ../2-Structural/8-Proxy/2-VirtualProxy/virtualProxy.cpp
   :language: cpp
   :caption: virtualProxy.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code virtualProxy.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/2-Structural/8-Proxy/2-VirtualProxy/virtualProxy.cpp>`_
