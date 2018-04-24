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

Observer
^^^^^^^^

Definition of Observer: An observer is an object that wishes to be informed about events happening in the system, typically by providing a callback function to call when events occur. The entity generating the events is sometimes called *observable*.

* We need to be informed when certain things happen

  * Object’s property changes.
  * Object does something.
  * Some external event occurs.

* We want to listen to events and be notified when they occur.
* No built-in event functionality in C++.
* Function pointers, std::function, OOP constructs, special libraries
* Implementation of Observer is an intrusive approach: an observable must provide subscribe and unsubscribe functions and must have explicit notification code.
* Special care must be taken to prevent issues in multithreaded scenarios.
* Reentrancy is very difficult to deal with.
* Libraries such as Boost.Signals2 provide a usable implementation of Observer.

Observer with Boost Signal2
"""""""""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/07-Observer/1-BoostSignal2Observer/observer.cpp
   :language: cpp
   :caption: observer.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code observer.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/07-Observer/1-BoostSignal2Observer/observer.cpp>`_

Thread Safety and  Observer
"""""""""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/07-Observer/2-ThreadSafetyObserver/observer2.cpp
   :language: cpp
   :caption: observer2.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code observer2.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/07-Observer/2-ThreadSafetyObserver/observer2.cpp>`_

State
^^^^^

Definition of State: A pattern in which the object's behavior is determined by its state. An object transitions from one state to another (something needs to *trigger* the transition). A formalized construct which manages states and transitions is called a *state machine*.

* Consider an ordinary telephone.
* What you do with it depends on the state of the phone/line.

  * If it's ringing or you want to make a call, you can pick it up.
  * Phone must be off the hook to take/make a call.
  * If you are calling someone, and it's busy, you put the handset down.

* Changes in state can be explicit or in response to events (e.g. Observer).
* Given sufficient complexity, it pays to formally define possible states and events/triggers.
* Can define:

  * State entry/exit behaviors.
  * Action when a particular event causes a transition.
  * Guard conditions enabling/disabling a transition.
  * Default action when no transitions are found for an event.

Handwritten State Machine
"""""""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/08-State/1-HandwrittenStateMachine/basic.cpp
   :language: cpp
   :caption: basic.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code basic.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/08-State/1-HandwrittenStateMachine/basic.cpp>`_

Boost State Machine - MSM
"""""""""""""""""""""""""

.. literalinclude:: ../3-Behavioral/08-State/2-BoostStateMachine/msm.cpp
   :language: cpp
   :caption: msm.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code msm.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/08-State/2-BoostStateMachine/msm.cpp>`_

Strategy (Policy)
^^^^^^^^^^^^^^^^^

Definition of Strategy: Enables the exact behavior of a system to be selected at either *run-time (dynamic)* or *compile-time (static)*. Also known as a *policy*.

* Many algorithms can be decomposed into higher-level and lower-level parts.
* Making tea can be decomposed into:

  * The process of making a hot beverage (boil water, pour into cup); and
  * Tea-specific things (get a teabag).

* The high-level algorithm can then be reused for making coffee or hot chocolate.

  * Supported by beverage-specific strategies.

* Define an algorithm at a high level.
* Define the interface you expect each strategy to follow.
* Provide for either dynamic or static(C++ templates) composition of strategy in the overall algorithm.

Static Strategy
"""""""""""""""

.. literalinclude:: ../3-Behavioral/09-Strategy/1-StaticStrategy/strategy_static.cpp
   :language: cpp
   :caption: strategy_static.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code strategy_static.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/09-Strategy/1-StaticStrategy/strategy_static.cpp>`_

Dynamic Strategy
""""""""""""""""

.. literalinclude:: ../3-Behavioral/09-Strategy/2-DynamicStrategy/strategy_dynamic.cpp
   :language: cpp
   :caption: strategy_dynamic.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code strategy_dynamic.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/09-Strategy/2-DynamicStrategy/strategy_dynamic.cpp>`_

Template
^^^^^^^^

Definition of Template: Allows us to define the 'skeleton' of the algorithm, with concrete implementations defined in subclasses.

* Algorithms can be decomposed into common parts and specifics.
* Strategy pattern does this through composition

  * High-level algorithm uses an interface.
  * Concrete implementations implement the interface.

* Template Method does the same thing through inheritance.
* Define an algorithm at a high level.
* Define constituent parts as pure virtual functions.
* Inherit the algorithm class, providing necessary function implementations.
* Similar to GP (Generative Programming).

Chess
"""""

.. literalinclude:: ../3-Behavioral/10-Template/template_method.cpp
   :language: cpp
   :caption: template_method.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code template_method.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/09-Strategy/2-DynamicStrategy/10-Template/template_method.cpp>`_

Visitor
^^^^^^^

Definition of Visitor: A pattern where a component (visitor) is allowed to traverse the entire inheritance hierarchy. Implemented by propagating a single *visit()* function through the entire hierarchy.

* Dispatch: Which function to call?

  * Single dispatch: depends on name of request and type of receiver. This is standard C++ behavior.
  * Double dispatch: depends on name of request and type of two receivers - type of visitor and type of element being visited.

* Need to define a new operation on an entire class hierarchy

  * E.g. make a document model printable to HTML/Markdown.

* Do not want to keep modifying every class in the hierarchy.
* Create external component to handle the rendering.

  * But avoid type checks.

* Propagate a pure virtual *accept(Visitor&)* function through the entire hierarchy.
* Create visitor (interface) with *visit(Foo&), visit(Bar&)* for each element in the hierarchy.
* Each *accept()* simply calls *v.visit(*this)*.

Static Visitor
""""""""""""""

.. literalinclude:: ../3-Behavioral/11-Visitor/1-StaticVisitor/staticVisitor.cpp
   :language: cpp
   :caption: staticVisitor.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code staticVisitor.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/11-Visitor/1-StaticVisitor/staticVisitor.cpp>`_

Double Dispatch
"""""""""""""""

.. literalinclude:: ../3-Behavioral/11-Visitor/2-DoubleDispatchVisitor/dynamicVisitor.cpp
   :language: cpp
   :caption: dynamicVisitor.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code dynamicVisitor.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/11-Visitor/2-DoubleDispatchVisitor/dynamicVisitor.cpp>`_

Multiple Dispatch
"""""""""""""""""

.. literalinclude:: ../3-Behavioral/11-Visitor/3-MultiDispatchVisitor/multiDispatchVisitor.cpp
   :language: cpp
   :caption: multiDispatchVisitor.cpp
   :start-after: int main() {
   :end-before: return 0

`Full source code multiDispatchVisitor.cpp <https://github.com/schmidh/CPP-Design-Patterns/blob/master/3-Behavioral/11-Visitor/3-MultiDispatchVisitor/multiDispatchVisitor.cpp>`_
