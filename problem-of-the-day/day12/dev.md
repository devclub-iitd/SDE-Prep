# Dev Problem Of the Day#12

## Operator Overloading

- ### What is Operator Overloading?

  `Operator overloading` is a feature in C++ that allows you to redefine the behavior of standard C++ operators when they are used with user-defined classes or structures.

- ### Points to keep in mind

  - Overloading an operator does not change its precedence or associativity.
  - Not all operators can be overloaded in C++. New operators cannot be created.
  - The overloaded operator must have at least one operand that is of a user-defined type.
  - **Overloading the `<<` operator :**
    - This [Link](https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170) explains with example how `cout` can be overloaded for your own classes.
  - **Overloading for comparing objects :**
    - This [Link](https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/) gives the implementation to `compare two objects`.

- ### Resources

  - This [link](https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170) contains everything you need to know about operator overloading and its implementation.
  - This [documentation](https://en.cppreference.com/w/cpp/language/operators) can also be referred for implementation.

    #### Do implement and experiment in C++ to get a better understanding of the concept!
