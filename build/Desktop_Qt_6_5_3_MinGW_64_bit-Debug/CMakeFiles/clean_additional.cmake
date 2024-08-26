# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\passwordValidation_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\passwordValidation_autogen.dir\\ParseCache.txt"
  "passwordValidation_autogen"
  )
endif()
