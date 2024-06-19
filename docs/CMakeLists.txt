set(DOXYGEN_HTML_OUTPUT "${CMAKE_SOURCE_DIR}/docs/doxygen")
set(DOXYGEN_PROJECT_NAME "Simple Progress Bar")
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(
    docs 
    ${CMAKE_SOURCE_DIR}/include/SimpleProgressBar.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md
    COMMENT "Generate documentation"
)