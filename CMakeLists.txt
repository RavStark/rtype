CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(r-type)

if(POLICY CMP0020)
	cmake_policy(SET CMP0020 NEW) # remove if CMake >= 2.8.11 required
endif()

macro(GroupSources curdir)

   file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

   foreach(child ${children})

          if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})

                  GroupSources(${curdir}/${child})

          else()

                  string(REPLACE "/" "\\" groupname ${curdir})

          # I would like to call the src root folder in a different name, only in visual studio (not mandatory requirement)

                  # string(REPLACE "src" "Common" groupname ${groupname})

            source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})

          endif()

   endforeach()

endmacro()

GroupSources(Source)
GroupSources(Include)

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Bin)

FILE(
	GLOB_RECURSE
	RTYPE_SRC
	Source/*.cpp
)

FILE(
	GLOB_RECURSE
	RTYPE_INC
	Include/*.hpp
)

INCLUDE_DIRECTORIES(
	Include
	${CMAKE_SOURCE_DIR}/dependencies/SFML-2.3/include
)

LINK_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/dependencies/SFML-2.3/lib
)

IF(WIN32)
    SET(CMAKE_CXX_FLAGS "/EHsc /W4 /GR")

    # Use unicode character set
    ADD_DEFINITIONS(-DUNICODE -D_UNICODE)


    # Removing warnings about constant conditions
    ADD_DEFINITIONS(/wd4127)
	ADD_DEFINITIONS(/wd4512)
ELSE(WIN32)
    SET(CMAKE_CXX_FLAGS "-Wall -ansi -O3 -std=c++11")
ENDIF(WIN32)



ADD_EXECUTABLE(
  rtype
  ${RTYPE_SRC}
  ${RTYPE_INC}
)


SET_TARGET_PROPERTIES(rtype PROPERTIES DEBUG_POSTFIX "_d")
SET(RTYPE_BIN_DIR ${PROJECT_SOURCE_DIR}/Bin)
SET_PROPERTY(TARGET rtype PROPERTY RUNTIME_OUTPUT_DIRECTORY_DEBUG ${RTYPE_BIN_DIR})
SET_PROPERTY(TARGET rtype PROPERTY RUNTIME_OUTPUT_DIRECTORY_RELEASE ${RTYPE_BIN_DIR})

TARGET_LINK_LIBRARIES(
	rtype
	debug sfml-system-d
	debug sfml-main-d
	debug sfml-graphics-d
	debug sfml-audio-d
	debug sfml-network-d
	debug sfml-window-d
	optimized sfml-system
	optimized sfml-main
	optimized sfml-graphics
	optimized sfml-audio
	optimized sfml-network
	optimized sfml-window
)
