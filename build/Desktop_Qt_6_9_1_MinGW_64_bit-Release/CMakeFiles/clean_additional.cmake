# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "ActualVectorCalculator_autogen"
  "CMakeFiles\\ActualVectorCalculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ActualVectorCalculator_autogen.dir\\ParseCache.txt"
  )
endif()
