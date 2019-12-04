add_executable(${PROJECT_NAME}
src/main.cpp
)

# Installation
install(CODE "MESSAGE(\"Installing ${PROJECT_NAME} \")")
install(TARGETS  ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)