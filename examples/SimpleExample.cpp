
#include <SimpleProgressBar.hpp>

#include <thread>
#include <chrono>

int main() {

    // Create a progress bar with the default number of steps.
    // That's 100 steps.
    SimpleProgressBar::ProgressBar bar;

    for(int i = 0; i < bar.getTotalSteps(); ++i) {

        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Increment the progress bar. This adds one step to the progress
        // in the progress bar.
        bar.increment();

        // Print the progress bar in its current state to the console.
        bar.print();

    }

    std::cout << std::endl;

    return 0;

}