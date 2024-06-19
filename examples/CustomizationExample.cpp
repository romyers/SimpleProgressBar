
#include <SimpleProgressBar.hpp>

#include <thread>
#include <chrono>

int main() {

    // Create a progress bar with 500 steps
    SimpleProgressBar::ProgressBar bar(500U);

    // Set how many characters wide the bar will appear in the terminal
    bar.setWidth(50U);

    // Configure the bar to look like "<----....>"
    bar.setLeftEndcapSymbol('<');
    bar.setRightEndcapSymbol('>');
    bar.setDoneSymbol('-');
    bar.setTodoSymbol('.');

    // Successive calls to print will now print one after another rather than
    // in-place.
    bar.disableOverwrite();

    for(int i = 0; i < 100; ++i) {

        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Increment the progress bar by 5 steps
        bar.increment(5);

        // Print the progress bar in its current state to std::cerr
        bar.print(std::cerr);

        // Go to a new line
        std::cerr << std::endl;

    }

    return 0;

}