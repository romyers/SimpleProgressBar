/*
 * MIT License
 *
 * Copyright (c) 2024 Robert Myers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file SimpleProgressBar.h
 * 
 * @brief A simple progress bar for console applications.
 * 
 * @author Robert Myers
 * Contact: romyers@umich.edu
 */

#pragma once

#include <iostream>

namespace SimpleProgressBar {

    /**
     * A simple progress bar for console applications.
     */
    class ProgressBar {

    public:

        /**
         * Constructor.
         * 
         * @param totalSteps The total number of progress bar steps.
         */
        ProgressBar(unsigned int totalSteps = 100U);

        /**
         * Increments the progress displayed by the progress bar by a given
         * number of steps (one by default).
         * 
         * If increment() brings the current progress above totalSteps,
         * the current progress will be snapped to totalSteps.
         * 
         * @param steps The number of steps by which to increment the displayed
         * progress.
         */
        void increment(unsigned int steps = 1U);

        /**
         * Retrieve the total number of steps in the progress bar.
         * 
         * @return The total number of steps
         */
        unsigned int getTotalSteps() const;

        /**
         * Prints the progress bar in its current state to a stream.
         * Prints to std::cout by default.
         * 
         * @param out The stream to print to.
         */
        void print(std::ostream &out = std::cout) const;

        /**
         * Sets the width of the progress bar display in number of characters.
         * The width of the progress bar is set to 80 characters by default.
         * 
         * REQUIRES: w is at least 2.
         * 
         * @param w The desired width of the progress bar, as a number of 
         * characters.
         */
        void setWidth(unsigned int w);

        /**
         * Sets the symbol for the progress bar's left endcap.
         * Set to '[' by default.
         * 
         * @param c The new symbol.
         */
        void setLeftEndcapSymbol(char c);

        /**
         * Sets the symbol for the progress bar's right endcap.
         * Set to ']' by default.
         * 
         * @param c The new symbol.
         */
        void setRightEndcapSymbol(char c);

        /**
         * Sets the symbol indicating completed progress.
         * Set to '=' by default.
         * 
         * @param c The new symbol.
         */
        void setDoneSymbol(char c);

        /**
         * Sets the symbol indicating progress that hasn't been completed yet.
         * Set to ' ' by default.
         */
        void setTodoSymbol(char c);

        /**
         * Sets the progress bar to overwrite the current output line on each
         * call to print(). This is equivalent to adding the '\r' character to
         * the end of the printed output.
         */
        void enableOverwrite();

        /**
         * Sets the progress bar not to overwrite the current output line on
         * each call to print(). Successive calls to print will be printed
         * one after another.
         */
        void disableOverwrite();

    private:

        unsigned int progress;
        unsigned int totalSteps;

        char leftEndcapSymbol;
        char rightEndcapSymbol;
        char doneSymbol;
        char todoSymbol;

        unsigned int width;

        bool overwrite;

    };

}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// IMPLEMENTATION ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

SimpleProgressBar::ProgressBar::ProgressBar(unsigned int totalSteps) : 
    progress(0),
    leftEndcapSymbol('['),
    rightEndcapSymbol(']'),
    doneSymbol('='),
    todoSymbol(' '),
    width(80U),
    overwrite(true),
    totalSteps(totalSteps) {}

unsigned int SimpleProgressBar::ProgressBar::getTotalSteps() const {

    return totalSteps;

}

void SimpleProgressBar::ProgressBar::setLeftEndcapSymbol(char c) {

    leftEndcapSymbol = c;

}

void SimpleProgressBar::ProgressBar::setRightEndcapSymbol(char c) {

    rightEndcapSymbol = c;

}

void SimpleProgressBar::ProgressBar::setDoneSymbol(char c) {

    doneSymbol = c;

}

void SimpleProgressBar::ProgressBar::setTodoSymbol(char c) {

    todoSymbol = c;

}

void SimpleProgressBar::ProgressBar::setWidth(unsigned int w) {

    width = w;

}

void SimpleProgressBar::ProgressBar::increment(unsigned int steps) {

    progress += steps;

    if(progress > totalSteps) {

        progress = totalSteps;

    }

}

void SimpleProgressBar::ProgressBar::print(std::ostream &out) const {

    out << leftEndcapSymbol;

    double proportionalProgress = static_cast<double>(progress) 
                                / static_cast<double>(totalSteps);

    // For nonnegative values, casting to int is equivalent to flooring.
    unsigned int numBarChars = static_cast<unsigned int>(
        proportionalProgress * (width - 2)
    );

    for(unsigned int w = 0; w < numBarChars; ++w) {

        out << doneSymbol;
    
    }

    for(unsigned int w = numBarChars; w < width - 2; ++w) {

        out << todoSymbol;

    }

    out << rightEndcapSymbol;
    out << std::flush;
    if(overwrite) out << '\r';

}

void SimpleProgressBar::ProgressBar::enableOverwrite() {

    overwrite = true;

}

void SimpleProgressBar::ProgressBar::disableOverwrite() {

    overwrite = false;

}