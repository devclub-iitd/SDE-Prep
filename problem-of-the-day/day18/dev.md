# Dev Problem of the Day - RAII

## Resource Acquisition is Initialisation (RAII)

RAII is a fundamental concept in modern C++ programming that ensures resource management is handled in a safe, efficient, and intuitive manner.

- ### What is RAII?

  RAII is a programming idiom used in several object-oriented languages, including C++. It binds the lifecycle of a resource to the lifetime of an object. When the object is created, it acquires the resource, and when it goes out of scope, its destructor is called, releasing the resource. This prevents resource leaks, ensures exception safety, and improves code readability and maintainability.

- #### Smart Pointers

  Smart Pointers are crucial to RAII. They are used to help ensure that programs are free of memory and resource leaks and are exception-safe.

  This [resource](https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170) explains smart pointers and its usage, as well as the types of pointers used in modern C++ programming. These are some important topics that are asked in technical tests, so it is recommended to be clear with the differences and usecases of pointers.

  **_Implement them for clarity of functioning!_**

- ### Resources
  - This [documentation](https://en.cppreference.com/w/cpp/language/raii) explains RAII classes in C++ in detail.
  - This [link](https://learn.microsoft.com/en-us/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170) is a good resource for RAII as well.
