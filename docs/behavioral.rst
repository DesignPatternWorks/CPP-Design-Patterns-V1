Behavioral Design Patterns
==========================

Chain of Responsibility
^^^^^^^^^^^^^^^^^^^^^^^

Definition of Chain of Responsibility: A chain of components who all get a chance to process a command or query, optionally having a default processing implementation and an ability to terminate the processing chain.

+ You click a graphical element on a form

  * Button handles it, might stop further processing
  * Underlying group box
  * Underlying window

* CCG computer game

  * Creature has attack and defense values.
  * Those can be boosted by other cards.

* Command Query Separation (CQS)

  * Command = asking for an action or change (e.g. please set your attack value to 2).
  * Query = asking for information (e.g. please give me your attack value).
  * CQS = having separate means fo sending commands and queries.

    * Antithetical to set fields directly.

* Chain of Responsibility can be implemented as a pointer chain or a centralized construct (event bus).
* Enlist objects in the chain, possibly controlling their order.
* Remove object from chain when no longer applicable (e.g. in its own destructor).

Pointer Chain
"""""""""""""

.. literalinclude:: ../3-Behavioral/01-ChainOfResponsibility/1-PointerChain/cor_pointer.cpp
   :language: cpp
   :caption: cor_pointer.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code cor_pointer.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/01-ChainOfResponsibility/1-PointerChain/cor_pointer.cpp>`_

Broker Chain
""""""""""""

.. literalinclude:: ../3-Behavioral/01-ChainOfResponsibility/2-BrokerChain/cor_broker.cpp
   :language: cpp
   :caption: cor_broker.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code cor_broker.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/01-ChainOfResponsibility/2-BrokerChain/cor_broker.cpp>`_

Command
^^^^^^^

Definition of Command: An object which represents an instruction to perform a particular action. Contains all information necessary for the action to be taken.

* Ordinary C++ statements are perishable

  * Cannot undo a field assignment
  * Cannot directly serialize a sequence of actions

* Want an object that represents an operation

  * X should change its Y to Z
  * X should do W

* Usage: GUI commands, multi-level undo/redo, macro recording and more!

* Encapsulate all details of an operation in a separate object.
* Define instructions for applying the command (either in the command itself, or elsewhere).
* Optionally define instructions for undoing the command.
* Can create composite commands (a.k.a. macros).

Composite Command with Undo/Redo
""""""""""""""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/02-Command/command.cpp
   :language: cpp
   :caption: command.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code command.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/02-Command/command.cpp>`_

Interpreter
^^^^^^^^^^^

Definition of Interpretor: A component that processes structured text data. Does so by turning it into separate lexical tokens (lexing) and then interpreting sequences of said tokens (parsing).

* Textual input needs to be processed.

  * e.g. turned into OOP structures.

* Some examples:

  * Proramming language compilers, interpreters and IDEs.
  * HTML, XML and similar.
  * Numeric expressions (2+3/4).
  * Regular expressions.

* Turning strings into OOP based structures is a complicated process.
* Barring simple cases, an interpreter does two stages:

  * Lexing turns text in to a set of tokens, e.g.

    * 2*(3+4) -> Lit[2] Star LParen Lit[3] Plus Lit[4] Rparen

  * Parsing turns tokens into meaningful constructs

    * MultiplicationExpression{Integer{2}, AdditionExpression{Integer{3}, Integer{4}}}

* Parsed data can be traversed

Handwritten Interpreter
"""""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/03-Interpreter/interpreter.cpp
   :language: cpp
   :caption: interpreter.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code interpreter.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/03-Interpreter/interpreter.cpp>`_

Iterator
^^^^^^^^

Definition of Iterator: An object that facilitates the traversal of a data structure.

* Iteration (traversal) is a core functionality of various data structures.
* An *iterator* is a class that facilitates the traversal

  * Keeps pointer to an element.
  * Knows how to move to a different element.

* Iterator types

  * Forward (e.g. on a list)
  * Bidirectional (e.g. on a doubly linked list)
  * Random access (e.g. on a vector)

* Iterator Requirements

  * Container Member Functions:

    * **begin()**

      * Points to the first element in the container. If empty is equal to **end()**.

    * **end()**

      * Points to the element immediately after the last element.

    * Facilitates use of standard algorithms.
    * Allow the use of range-based for loops:

      * *for (auto& x : my_container)*

    * Different names for different iterators.

  * Iterator Operators:

    * **operator !=**

      * Must return false if two iterators point to the same element.

    * **operator *** (dereferencing)

      * Must return a reference to (or a copy of) the data the iterator points to.

    * **operator ++**

      * Gets the iterator to point to the next element.

  * Additional operators as required (e.g. operator --, arithmetic, etc.)

* An iterator specifies how you can traverse an object.
* Typically needs to support comparison (**!=**), advancing (**++**) and dereferencing (*****).

  * May support other things, e.g. arithmetic, operator --, etc.

* Can have many different iterators (reverse, const, etc.)
  
  * Default on returned in begin()/end()

* Iterators can not be recursive.

STL Iterators
"""""""""""""

.. literalinclude:: ../3-Behavioral/04-Iterator/1-IteratorSTL/iteratorSTL.cpp
   :language: cpp
   :caption: iteratorSTL.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code iteratorSTL.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/04-Iterator/1-IteratorSTL/iteratorSTL.cpp>`_

Binary Tree Iterator
""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/04-Iterator/2-BinaryTreeIterator/binaryTreeIterator.cpp
   :language: cpp
   :caption: binaryTreeIterator.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code binaryTreeIterator.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/04-Iterator/2-BinaryTreeIterator/binaryTreeIterator.cpp>`_

Boost Iterator Facade
"""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/04-Iterator/3-BoostIteratorFacade/facade.cpp
   :language: cpp
   :caption: facade.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code facade.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/04-Iterator/3-BoostIteratorFacade/facade.cpp>`_

Mediator
^^^^^^^^

Definition of Mediator: A component that facilitates communication between other components without them being aware of each other or having direct (referential) access to each other.

* Components may go in and out of a system at any time.

  * Chat room participants.
  * Players in an MMORPG.

* It makes no sense for them to have direct references to each other.

  * Those references may go dead.

* Solution: Have them all refer to the some central component that facilitates communication.
* Create the mediator and have each object in the system refer to it.

  * e.g. a reference field.

* Mediator engages in bidirectional communication with its connected components.
* Mediator has functions the components can call.
* Components have functions the mediator can call.
* Signals/slots (Boost.Signals2) and event processsing (RxCpp) libraries make communication easier to implement.

Chat Room
"""""""""

.. literalinclude:: ../3-Behavioral/05-Mediator/1-ChatRoom/chat.cpp
   :language: cpp
   :caption: chat.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code chat.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/05-Mediator/1-ChatRoom/chat.cpp>`_

Event Broker
""""""""""""

.. literalinclude:: ../3-Behavioral/05-Mediator/2-EventBroker/mediator.cpp
   :language: cpp
   :caption: mediator.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code mediator.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/05-Mediator/2-EventBroker/mediator.cpp>`_

Memento
^^^^^^^

Definition of Memento: A token/handle representing the system state. Lets us roll back to the state when the token was generated. May or may not directly expose state information.

* An object or system goes through changes.

  * e.g. a bank account gets deposits and withdrawels.

* There are different ways of navigating those changes.
* One way is to record every change (Command design pattern) and teach a command to 'undo' itself.
* Another is simply to save snapshots of the system.
* Mementos are used to roll back changes arbitrarily.
* A memento is simply a token/handle class with (typically) no functions of its own.
* A memento is not required to expose directly the state(s) to which it reverts the system.
* Can be used to implement undo/redo.

Memento with Undo/Redo
""""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/06-Memento/memento.cpp
   :language: cpp
   :caption: memento.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code memento.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/06-Memento/memento.cpp>`_
