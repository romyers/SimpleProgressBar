# Simple Progress Bar {#mainpage}

A very, very simple progress bar for C++ console applications.

![A GIF of the progress bar in the console.](../img/ProgressBar.gif)

## Installation

This library is header-only. Just make sure 'SimpleProgressBar.hpp' is present 
in your project's include path, and include it in your project.

A CMakeLists.txt file is provided for building tests and examples, but is not
required to use the library.

## Usage

To use the progress bar, simply construct an instance of the 
[ProgressBar](@ref SimpleProgressBar::ProgressBar) class
with the desired number of steps (100 by default), and call 
[increment()](@ref SimpleProgressBar::ProgressBar::increment()) to 
advance the bar's progress by one step. Then print the progress bar to the 
console (or any ostream) with 
[print()](@ref SimpleProgressBar::ProgressBar::print()).

The `increment()` function takes an optional argument specifying the number of
steps to increment (1 by default). The `print()` function takes the ostream the
progress bar should be printed to.

## Example

A short program that demonstrates the use of the progress bar:

```cpp
#include "SimpleProgressBar.hpp"

#include <iostream>

int main() {

    SimpleProgressBar::ProgressBar bar(100);

    for(int i = 0; i < 100; ++i) {

        bar.increment();

        bar.print(std::cout);

    }

    std::cout << std::endl;

    return 0;

}
```

A further example is provided in the `example` directory, and can be built with
the provided CMakeLists.txt file.

## Documentation

The full documentation for Simple Progress Bar can be generated using cmake 
with 
```
$ make docs
```
provided that Doxygen is installed on your system. The generated documentation
will be placed in the 'docs/doxygen' directory.

Included in the documentation is a full reference for the ProgressBar class,
with additional documented methods used to customize the appearance and
behavior of the progress bar.

## Testing the Library

A test suite is provided in the `test` directory. The test suite uses the 
GoogleTest testing framework, which will be downloaded and built automatically
when the test suite is built with CMake.