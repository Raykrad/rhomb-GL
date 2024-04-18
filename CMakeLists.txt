cmake_minimum_required(VERSION 3.20)
project(rhomb-GL
 VERSION 0.0.1
 LANGUAGES C CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
add_subdirectory(external)
add_executable(rhomb-GL main.cpp)
target_include_directories(${PROJECT_NAME}
 PUBLIC
 external
 ${OPENGL_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME}
 PUBLIC
 ${OPENGL_gl_LIBRARY}
 glfw
 imgui
)
include(GNUInstallDirs)
install(TARGETS rhomb-GL
 LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
 RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
