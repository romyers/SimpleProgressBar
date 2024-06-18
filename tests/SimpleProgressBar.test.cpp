#include <gtest/gtest.h>

#include "SimpleProgressBar.hpp"

#include <sstream>

using SimpleProgressBar::ProgressBar;

using std::stringstream;

const char DEFAULT_L_ENDCAP = '[';
const char DEFAULT_R_ENDCAP = ']';
const char DEFAULT_FILL_SYMBOL = '=';

TEST(widthIsCorrect, defaultWidth) {

    ProgressBar bar;

    stringstream ss;

    bar.print(ss, false);

    EXPECT_EQ(ss.str().size(), 80);

}

TEST(widthIsCorrect, newWidth) {

    ProgressBar bar;

    stringstream ss;

    bar.setWidth(50U);

    bar.print(ss, false);

    EXPECT_EQ(ss.str().size(), 50);

}

TEST(endcaps, defaultSymbol) {

    ProgressBar bar;

    stringstream ss;

    bar.print(ss, false);

    EXPECT_EQ(ss.str().front(), DEFAULT_L_ENDCAP);
    EXPECT_EQ(ss.str().back(), DEFAULT_R_ENDCAP);

}

TEST(endcaps, setNewSymbols) {

    ProgressBar bar;

    stringstream ss;

    bar.setLeftEndcapSymbol('a');
    bar.setRightEndcapSymbol('b');

    bar.print(ss, false);

    EXPECT_EQ(ss.str().front(), 'a');
    EXPECT_EQ(ss.str().back(), 'b');

}

TEST(barSymbol, defaultSymbol) {

    ProgressBar bar;

    stringstream ss;

    bar.increment(100U);

    bar.print(ss, false);

    EXPECT_EQ(ss.str()[1], DEFAULT_FILL_SYMBOL);

}

TEST(barSymbol, newSymbol) {

    ProgressBar bar;

    stringstream ss;

    bar.increment(100U);

    bar.setFillSymbol('n');

    bar.print(ss, false);

    EXPECT_EQ(ss.str()[1], 'n');

}

TEST(barDisplay, emptyByDefault) {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.print(ss, false);

    EXPECT_EQ(ss.str(), "[        ]");

}

TEST(barDisplay, fullBar) {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(100U);

    bar.print(ss, false);

    EXPECT_EQ(ss.str(), "[========]");

}

TEST(barDisplay, halfBar) {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(50U);

    bar.print(ss, false);

    EXPECT_EQ(ss.str(), "[====    ]");

}

TEST(barDisplay, almostFullBarIsNotFull) {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(99U);

    bar.print(ss, false);

    EXPECT_EQ(ss.str(), "[======= ]");

}

TEST(barDisplay, almostEmptyBarIsEmpty) {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(1U);

    bar.print(ss, false);

    EXPECT_EQ(ss.str(), "[        ]");

}

TEST(barDisplay, norm) {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(39U);

    bar.print(ss, false);

    EXPECT_EQ(ss.str(), "[===     ]");

}