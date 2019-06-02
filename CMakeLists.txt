cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(gtk3-tutorial)

find_package(PkgConfig REQUIRED)
if(NOT PKG_CONFIG_FOUND)
  message(SEND_ERROR "pkg-config utility not found")
endif()

pkg_check_modules(GTK3 REQUIRED "gtk+-3.0")

include_directories(${GTK3_INCLUDE_DIRS})
link_libraries(${GTK3_LIBRARIES})

if(WINDOWS)
  add_link_options("-Wl,--subsystem,windows")
endif()

add_subdirectory(foundation)
