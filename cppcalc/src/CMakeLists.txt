cmake_minimum_required(VERSION 3.6)
project(cppcalc)

set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-std=c++11")

set(IN_OPENWRT $ENV{IN_OPENWRT})
IF (IN_OPENWRT)
add_definitions("$ENV{TARGET_LDFLAGS}" "$ENV{TARGET_CPPFLAGS}" "$ENV{TARGET_CFLAGS}")
include_directories("$ENV{TARGET_LDFLAGS}" "$ENV{TARGET_CPPFLAGS}" "$ENV{TARGET_CFLAGS}")
#change uClibc++ to stdc++ for standard c++ library
target_link_libraries(${PROJECT_NAME} uClibc++ c gcc_s "$ENV{TARGET_LDFLAGS}")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-nodefaultlibs -fno-builtin -fno-rtti -nostdinc++")
#remove this string for standard c++ library
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-I $ENV{STAGING_DIR}/usr/include/uClibc++")
ELSE (IN_OPENWRT)
add_definitions("-Wall -g")
install(PROGRAMS ${PROJECT_NAME}  DESTINATION /usr/bin)
add_custom_target(uninstall COMMAND "rm" -f "/usr/bin/${PROJECT_NAME}")
ENDIF(IN_OPENWRT)
