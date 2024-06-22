# Dev Problem of the Day - Pimpl

## Pointer to Implementation (PImpl)

Amongst one of the techniques to achieve compile time speed is `Pimpl` (Pointer to implementation) idiom that separates internals of the class from the interface.

- #### What is PImpl?

  The `PIMPL` idiom (Pointer to IMPLementation) is a design pattern in C++ that hides class implementation details from users, reducing compile-time dependencies and breaking cyclic dependencies between header files.

- #### Why is Pimpl Important?

  - To achieve total encapsulation.
  - Helps in keeping binary compatibility of shared libraries
  - The separation of interface and implementation minimizes dependencies and improves ABI stability, reducing compile time during development.
  - This [article](https://ryonaldteofilo.medium.com/writing-stable-apis-with-pimpl-and-fast-pimpl-in-c-9ec387fe4339) explains use of pimpl in writing stable apis and work around with fast pimpl.
  - This [article](https://medium.com/@manoj563125/c-deep-dive-pimpl-idiom-swap-function-and-adl-8e1920ca1b1c) explains another important implementation of Pimpl.
  - _Task_ - Read about the disadvantages of Pimpl.

- #### Resources

  - This [documentation](https://en.cppreference.com/w/cpp/language/pimpl) explains everything you need to know about pimpl and its implementation.
  - This [thread](https://stackoverflow.com/questions/8972588/is-the-pimpl-idiom-really-used-in-practice?source=post_page-----8e1920ca1b1c--------------------------------) discusses well _in-detail_ on pimpl and why it is really used. It is recommended for those who want a deeper dive into the topic.

_This is another important topic asked in technical tests, so it is best you implement and understand the usecases of pimpl!_

**Happy Learning!**
