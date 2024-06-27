# C++ Smart Pointers

## Introduction
Smart pointers are a feature of C++ that allows for more robust memory management. They ensure automatic and appropriate destruction of dynamically allocated memory, preventing memory leaks and other common memory management errors.

## Types of Smart Pointers
- `unique_ptr`: Allows exactly one owner of the underlying pointer.
- `shared_ptr`: Allows multiple owners of the same pointer; the pointer is destroyed when the last owner goes out of scope.
- `weak_ptr`: Complements `shared_ptr` by holding a non-owning reference to an object that is managed by `shared_ptr`.

## Benefits
- Automatic memory management.
- Prevention of memory leaks.
- Can be used to implement sophisticated data structures like linked lists, graphs etc!

## Resources
- [C++ Smart Pointers - cppreference.com](https://en.cppreference.com/w/cpp/memory)
- [Smart Pointers in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/smart-pointers-cpp/)
- [Understanding Smart Pointers in C++ - YouTube](https://www.youtube.com/watch?v=UOB7-B2MfwA)

## Conclusion
Understanding and utilizing smart pointers effectively can greatly enhance your C++ programming skills and contribute to writing clean, efficient, and safe code.
