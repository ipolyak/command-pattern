set(target ${COMMAND_LIBRARY})

include_directories(${COMMAND_INCLUDE_DIR})

set(hdrs "${COMMAND_INCLUDE_DIR}/command_manager.h"
    "${COMMAND_INCLUDE_DIR}/command.h"
    "${COMMAND_INCLUDE_DIR}/init_command.h"
    "${COMMAND_INCLUDE_DIR}/add_value_command.h"
    "${COMMAND_INCLUDE_DIR}/set_value_command.h"
    "${COMMAND_INCLUDE_DIR}/prototype.h"   
    )
set(srcs command_manager.cpp
    command.cpp
    init_command.cpp
    set_value_command.cpp
    add_value_command.cpp
    prototype.cpp
    )

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target}
    ${MATRIX_LIBRARY}
    )

# copy static library to the binary directory
add_custom_command(TARGET ${COMMAND_LIBRARY} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_BINARY_DIR}/\$\(Configuration\)"
        "${CMAKE_CURRENT_BINARY_DIR}/../../bin")
