# Simple Progress Bar

A very, very simple progress bar for C++ console applications.

## Installation

This library is header-only. Just make sure 'SimpleProgressBar.hpp' is present 
in your project's include path, and include it in your project.

A CMakeLists.txt file is provided for building tests and examples, but is not
required to use the library.

## Usage

To use the progress bar, simply construct an instance of the ProgressBar class
with the desired number of steps (100 by default), and call `increment()` to 
advance the bar's progress by one step. Then print the progress bar to the 
console (or any ostream) with `print()`.

The `increment()` function takes an optional argument specifying the number of
steps to increment (1 by default). The `print()` function takes an ostream
to print to and an optional argument specifying whether the progress bar should
overwrite the current line (true by default).

If `print()` is set to overwrite, the progress bar will include a carriage 
return character in its output. This is useful for updating the progress bar
in-place in console output.

The width of the progress bar in characters can be set with the `setWidth()`
function. The default width is 80 characters.

The left and right endcap symbols for the progress bar can be set with 
`setLeftEndcapSymbol()` and `setRightEndcapSymbol()`, respectively. The default
symbols are '[' and ']'.

The fill symbol for the progress bar can be set with 'setFillSymbol()'. The
default fill symbol is '='.

## Example Usage

A short program that demonstrates the use of the progress bar:

```cpp
#include "SimpleProgressBar.hpp"

#include <iostream>

int main() {

    SimpleProgressBar::ProgressBar bar(100);

    for(int i = 0; i < 50; ++i) {

        bar.increment(2);

        bar.print(std::cout);

    }

    std::cout << std::endl;

    return 0;

}
```

A further example is provided in the `example` directory, and can be built with
the provided CMakeLists.txt file.

## Testing the Library

A test suite is provided in the `test` directory. The test suite uses the 
GoogleTest testing framework, which will be downloaded and built automatically
when the test suite is built with CMake.