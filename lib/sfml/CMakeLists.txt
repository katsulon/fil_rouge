message(STATUS "Fetching SFML 2.5.1...")

set(SFML_BUILD_AUDIO TRUE)
# No need to build network module
set(SFML_BUILD_NETWORK FALSE)

FetchContent_MakeAvailable(sfml)