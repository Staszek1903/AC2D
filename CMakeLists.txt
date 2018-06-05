project(SFMLTest)

if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${COMPILER_RELEASE_FLAGS}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${COMPILER_DEBUG_FLAGS}")
endif()

file(GLOB_RECURSE ${PROJECT_NAME}_headers *.h *.hpp)
file(GLOB_RECURSE ${PROJECT_NAME}_sources *.cpp)

set(${PROJECT_NAME}_all_headers ${${PROJECT_NAME}_headers} ${SHARED_headers} ${SHARED_NETWORK_headers} ${SHARED_SDO_headers} ${SHARED_GAMEPLAY_headers})
set(${PROJECT_NAME}_all_sources ${${PROJECT_NAME}_sources} ${SHARED_sources} ${SHARED_NETWORK_sources} ${SHARED_SDO_sources} ${SHARED_GAMEPLAY_sources})

add_executable (${PROJECT_NAME} ${${PROJECT_NAME}_all_headers} ${${PROJECT_NAME}_all_sources})

set(SFML_STATIC_LIBRARIES false)
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
set(${PROJECT_NAME}_LIBS ${${PROJECT_NAME}_LIBS} ${SFML_LIBRARIES})

find_package(EntityX REQUIRED)
include_directories(${EntityX_INCLUDE_DIRS})
set(${PROJECT_NAME}_LIBS ${${PROJECT_NAME}_LIBS} ${EntityX_LIBRARIES})

if (MSVC)
	set(${PROJECT_NAME}_LIBS ${${PROJECT_NAME}_LIBS} ws2_32)
endif()

target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}_LIBS} ${${PROJECT_NAME}_LIBS_DEBUG})

install(TARGETS ${PROJECT_NAME}
				RUNTIME DESTINATION bin
				LIBRARY DESTINATION dll
				ARCHIVE DESTINATION lib)
				
