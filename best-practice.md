# C++ Best Practices

Where to Put Class Definitions
------------------------------

Source: [Stack Overflow][1]
It depends, as usual.

Generally, it's best practice to split each class into a header (.h or .hpp) and source (.cpp) file, where you put everything you can in the source file¹, because it considerably speeds up building your program. This is incredibly important in real world development because large projects can take anywhere from 15 minutes to several hours to fully recompile and link. If you change anything in a source file the compiler only needs to recompile that cpp file into an object file and link the programs that include this object file. If you change anything in a header file, the compiler needs to recompile all cpp files that include that header and link all the programs that include any of these object files.

If the class is lightweight and very unlikely to change it's usually better to have it all in a header file. An example would be a class that serves as a strongly typed ID and only has a constructor and a comparison operator. Using only a header file keeps the code simpler and easier to read, and in this special case doesn't harm compile time because the class will "never" change.

If the class is a template it is usually not possible to put anything in a cpp file (unless we use template specialization), but it is often convention to place the definitions below the class declaration in the header file, using the inline keyword to allow compilation.

¹You can put even more in the source file if your project suffers strongly from header dependencies and the resulting compile time: pImpl Idiom

---

Source: [Stack Overflow][2]
Normally you put the class definition and the function declarations in the header file. And the function definitions in a source (`*.cpp`) file.

The reason to put the class definition and function declarations in the header file is so that other parts of the software can include the header and use the class and its method.
The reason to put the method definitions in a cpp-source file was that the methods should be defined only once. Modern compilers (i.e. C++-14 and above) can cope with the same method defined multiple times (given that all definitions are equal, as is the case with included header files). However, most C++ programmers expect the method definitions to be in cpp-files and only in header files when the methods should be inlined, therefore I would advise to put the methods in cpp-files.


[1]: https://softwareengineering.stackexchange.com/a/320036/278079
[2]: https://softwareengineering.stackexchange.com/a/320037/278079
