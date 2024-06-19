#include <catch2/catch_test_macros.hpp>

#include "SimpleProgressBar.hpp"

#include <sstream>

using SimpleProgressBar::ProgressBar;

using std::stringstream;

const char DEFAULT_L_ENDCAP = '[';
const char DEFAULT_R_ENDCAP = ']';
const char DEFAULT_FILL_SYMBOL = '=';

TEST_CASE("Default width is correctly displayed", "[width]") {

    ProgressBar bar;

    stringstream ss;

    bar.disableOverwrite();

    bar.print(ss);

    REQUIRE(ss.str().size() == 80);

}

TEST_CASE("Widths are correctly set", "[width]") {

    ProgressBar bar;

    stringstream ss;

    bar.setWidth(50U);
    bar.disableOverwrite();

    bar.print(ss);

    REQUIRE(ss.str().size() == 50);

}

TEST_CASE("Default encaps are correctly displayed", "[endcaps]") {

    ProgressBar bar;

    stringstream ss;

    bar.disableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str().front() == DEFAULT_L_ENDCAP);
    REQUIRE(ss.str().back() == DEFAULT_R_ENDCAP);

}

TEST_CASE("Endcaps are correctly set", "[endcaps]") {

    ProgressBar bar;

    stringstream ss;

    bar.setLeftEndcapSymbol('a');
    bar.setRightEndcapSymbol('b');

    bar.disableOverwrite();

    bar.print(ss);

    REQUIRE(ss.str().front() == 'a');
    REQUIRE(ss.str().back() == 'b');

}

TEST_CASE("Default fill symbol is correctly displayed", "[fillSymbol]") {

    ProgressBar bar;

    stringstream ss;

    bar.increment(100U);

    bar.disableOverwrite();

    bar.print(ss);

    REQUIRE(ss.str()[1] == DEFAULT_FILL_SYMBOL);

}

TEST_CASE("Fill symbol is correctly set", "[fillSymbol]") {

    ProgressBar bar;

    stringstream ss;

    bar.increment(100U);

    bar.setFillSymbol('n');

    bar.disableOverwrite();

    bar.print(ss);

    REQUIRE(ss.str()[1] == 'n');

}

TEST_CASE("Bar is empty by default", "barDisplay") {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.disableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str() == "[        ]");

}

TEST_CASE("Full bar is correctly displayed", "barDisplay") {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(100U);

    bar.disableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str() == "[========]");

}

TEST_CASE("Half-filled bar is correctly displayed", "barDisplay") {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(50U);

    bar.disableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str() == "[====    ]");

}

TEST_CASE("Almost full bar is not full", "[barDisplay]") {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(99U);

    bar.disableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str() == "[======= ]");

}

TEST_CASE("Almost empty bar is empty", "[barDisplay]") {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(1U);

    bar.disableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str() == "[        ]");

}

TEST_CASE("Bar is correctly filled", "[barDisplay]") {

    ProgressBar bar;

    stringstream ss;

    // Make our string literals more manageable
    bar.setWidth(10U);

    // This makes things well-defined even if defaults change.
    bar.setLeftEndcapSymbol('[');
    bar.setRightEndcapSymbol(']');
    bar.setFillSymbol('=');

    bar.increment(39U);

    bar.disableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str() == "[===     ]");

}

TEST_CASE("Enabling overwrite adds carriage return", "[overwrite]") {

    ProgressBar bar;

    stringstream ss;

    bar.disableOverwrite();
    bar.enableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str().back() == '\r');

}

TEST_CASE("Disabling overwrite removes carriage return", "[overwrite]") {

    ProgressBar bar;

    stringstream ss;

    bar.enableOverwrite();
    bar.disableOverwrite();
    bar.print(ss);

    REQUIRE(ss.str().back() != '\r');

}

TEST_CASE("Overwrite is enabled by default", "[overwrite]") {

    ProgressBar bar;

    stringstream ss;

    bar.print(ss);

    REQUIRE(ss.str().back() == '\r');

}