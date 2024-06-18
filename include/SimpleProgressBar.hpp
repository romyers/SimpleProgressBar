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

#include <ostream>

namespace SimpleProgressBar {

    /**
     * A simple progress bar for console applications.
     */
    class ProgressBar {

    public:

        /**
         * Constructor.
         * 
         * @param maxProgress The maximum value to which the ProgressBar
         * can be incremented. When incremented to maxProgress, the 
         * progress bar will be displayed as completely full.
         */
        ProgressBar(unsigned int maxProgress = 100U);

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
         * Sets the symbol for the interior of the progress bar.
         * Set to '=' by default.
         * 
         * @param c The new symbol.
         */
        void setFillSymbol(char c);

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
         * Increments the progress displayed by the progress bar by amount.
         * The displayed progress will increase by amount / maxProgress,
         * where maxProgress is the maximum progress value set in the
         * constructor.
         * 
         * If increment() brings the current progress above maxProgress,
         * the current progress will be snapped to maxProgress.
         * 
         * @param amount The amount by which to increment the displayed
         * progress.
         */
        void increment(unsigned int amount = 1U);

        /**
         * Prints the progress bar to a stream.
         * 
         * @param out The stream to print to.
         * @param overwrite Whether to overwrite the current line in the
         * stream. If set to true, print() will behave as though it was
         * followed by insertion of a '\r' character. Set to true by
         * default.
         */
        void print(std::ostream &out, bool overwrite = true) const;

    private:

        unsigned int progress;
        unsigned int maxProgress;

        char leftEndcapSymbol;
        char rightEndcapSymbol;
        char barSymbol;

        unsigned int width;

    };

}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// IMPLEMENTATION ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

SimpleProgressBar::ProgressBar::ProgressBar(unsigned int maxProgress) : 
    progress(0),
    leftEndcapSymbol('['),
    rightEndcapSymbol(']'),
    barSymbol('='),
    width(80U),
    maxProgress(maxProgress) {}

void SimpleProgressBar::ProgressBar::setLeftEndcapSymbol(char c) {

    leftEndcapSymbol = c;

}

void SimpleProgressBar::ProgressBar::setRightEndcapSymbol(char c) {

    rightEndcapSymbol = c;

}

void SimpleProgressBar::ProgressBar::setFillSymbol(char c) {

    barSymbol = c;

}

void SimpleProgressBar::ProgressBar::setWidth(unsigned int w) {

    width = w;

}

void SimpleProgressBar::ProgressBar::increment(unsigned int amount) {

    progress += amount;

    if(progress > maxProgress) {

        progress = maxProgress;

    }

}

void SimpleProgressBar::ProgressBar::print(
    std::ostream &out, bool overwrite
) const {

    out << leftEndcapSymbol;

    double proportionalProgress = static_cast<double>(progress) 
                                / static_cast<double>(maxProgress);

    // For nonnegative values, casting to int is equivalent to flooring.
    unsigned int numBarChars = static_cast<unsigned int>(
        proportionalProgress * (width - 2)
    );

    for(unsigned int w = 0; w < numBarChars; ++w) {

        out << barSymbol;
    
    }

    for(unsigned int w = numBarChars; w < width - 2; ++w) {

        out << " ";

    }

    out << rightEndcapSymbol;
    out << std::flush;
    if(overwrite) out << '\r';

}