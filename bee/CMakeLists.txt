file(GLOB ROOT_SOURCE *.cpp)
file(GLOB ROOT_HEADER *.h)

add_library(bee-header-only INTERFACE)
add_library(bee::bee-header-only ALIAS bee-header-only)

target_include_directories(bee-header-only INTERFACE
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

if(BEE_BUILD_LIBRARY)
    add_library(bee
    ${ROOT_SOURCE} ${ROOT_HEADER}
    )
    add_library(bee::bee ALIAS bee)
    target_link_libraries(bee PUBLIC bee-header-only)
else()
    add_library(bee INTERFACE)
    add_library(bee::bee ALIAS bee)
    target_link_libraries(bee INTERFACE bee-header-only)
endif()