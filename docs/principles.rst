Design Principles
=================

SOLID
-----

| **S** =  Single Responsibility Principle
| **O** = Open-Closed Principle
| **L** = Liskov Substitution Principle
| **I** = Interface Segregation Principle
| **D** = Dependency Inversion/Injection
|

Single Responsibility Principle
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A class should only have a single responsibility.

.. literalinclude:: ../1-Creational/1-Design-Principles/1-SOLID/1-S-ingleResponsibilityPrinciple/SRP.cpp
   :language: cpp
   :caption: SRP.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code SRP.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Design-Principles/1-SOLID/1-S-ingleResponsibilityPrinciple/SRP.cpp>`_


Open-Closed Principle
^^^^^^^^^^^^^^^^^^^^^

Entities should be open for extension but closed for modification.

.. literalinclude:: ../1-Creational/1-Design-Principles/1-SOLID/2-O-penClosedPrinciple/OCP.cpp
   :language: cpp
   :caption: OCP.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code OCP.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Design-Principles/1-SOLID/2-O-penClosedPrinciple/OCP.cpp>`_

Liskov Substitution Principle
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Objects should be replaceable with instances of their subtypes without altering program correctness.

.. literalinclude:: ../1-Creational/1-Design-Principles/1-SOLID/3-L-iskovSubstitutionPrinciple/LSP.cpp
   :language: cpp
   :caption: LSP.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code LSP.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Design-Principles/1-SOLID/3-L-iskovSubstitutionPrinciple/LSP.cpp>`_

Interface Segregation Principle
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Many client-specific interfaces better than one general-purpose interface.

.. literalinclude:: ../1-Creational/1-Design-Principles/1-SOLID/4-I-nterfaceSegregationPrinciple/ISP.cpp
   :language: cpp
   :caption: ISP.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code ISP.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Design-Principles/1-SOLID/4-I-nterfaceSegregationPrinciple/ISP.cpp>`_

Dependency Inversion/Injection
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Dependencies should be abstract rather than concrete.

**Dependency Inversion Principle**

1. **High-level modules should not depend on low-level modules. Both should depend on abstractions.**
   Example: reporting component should depend on a ConsoleLogger, but can depend on an ILogger.

2. **Abstractions should not depend upon details. Details should depend upon abstractions.**
   In other words, dependencies on interfaces and supertypes is better than dependencies on concrete types.

**Inversion of Control (IoC)** – the actual process of creating abstractions and getting them to replace dependencies.

**Dependency Injection** – use of software frameworks to ensure that a component’s dependencies are satisfied.

.. literalinclude:: ../1-Creational/1-Design-Principles/1-SOLID/5-D-ependencyInjection/BoostDI.cpp
   :language: cpp
   :caption: BoostDI.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code BoostDI.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/1-Creational/1-Design-Principles/1-SOLID/5-D-ependencyInjection/BoostDI.cpp>`_
