ROOT_ADD_UNITTEST_DIR(TreePlayer)
add_custom_command(TARGET treetreeplayertestUnit POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/data.h data.h)

