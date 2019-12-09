add_executable(${EXE_NAME}
src/main.cpp
src/application.cpp
src/util.cpp
)

add_library(${LIB_NAME} SHARED
src/main.cpp
src/application.cpp
src/util.cpp
)

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD 
  COMMAND ${CMAKE_COMMAND} -E copy    
  ${CMAKE_SOURCE_DIR}/data/adjectives.txt 
  ${CMAKE_BINARY_DIR}/data/adjectives.txt
)  

# add_custom_target(copy_data_directory
#     DEPENDS
#     "${CMAKE_CURRENT_BINARY_DIR}/generated_file"
# )

# add_custom_command(
#     OUTPUT
#         "${CMAKE_CURRENT_BINARY_DIR}/generated_file"
#     COMMAND
#         ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/generated_file
# )

# Installation
install(CODE "MESSAGE(\"Installing ${PROJECT_NAME} \")")
install(TARGETS  ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)