# Simple Progress Bar

A very, very simple progress bar for C++ console applications.

![A GIF of the progress bar in the console.](docs/img/ProgressBar.gif)

## Installation

This library is header-only. Just make sure 'SimpleProgressBar.hpp' is present 
in your project's include path, and include it in your project.

CMake integration is also provided, but is not required.

## Usage

To use the progress bar, simply construct an instance of the ProgressBar class
with the desired number of steps (100 by default), and call `increment()` to 
advance the bar's progress by one step. Then print the progress bar to the 
console (or any ostream) with `print()`.

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

A further example is provided in the `example` directory, and can be built by 
running cmake with the `BUILD_EXAMPLES` option set to `ON`.

## Testing the Library

A test suite is provided in the `test` directory, using the 
[Catch2](https://github.com/catchorg/Catch2) unit testing
framework. Run cmake with the `BUILD_TESTING` option set to `ON` to download
Catch2 and build the tests:
```
$ cmake -DBUILD_TESTING=ON [path to source directory]
```