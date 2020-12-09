#SFML Package
find_package(SFML 2.5 CONFIG COMPONENTS system window graphics network audio REQUIRED)

# source files
set(SOURCE_FILES cfirst.cpp)

configure_file(
	${PROJECT_SOURCE_DIR}/main/config.h.in
       	${PROJECT_BINARY_DIR}/config.h)
include_directories("${PROJECT_BINARY_DIR}")

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} gtest_main sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
