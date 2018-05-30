# Get c-files in the current directory
file(GLOB list RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c*)

include_directories(${COMMAND_INCLUDE_DIR}
  )

foreach(filename ${list})
  # Get file name without extension
  get_filename_component(component ${filename} NAME_WE)
  # Add and configure executable file
  add_executable(${component} ${filename})
  target_link_libraries(${component} ${COMMAND_LIBRARY})

  install(TARGETS ${component} DESTINATION bin)
endforeach()

