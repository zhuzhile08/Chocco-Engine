set(SDL2_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include/SDL/")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_LIBRARIES "${CMAKE_SOURCE_DIR}/data/lib/x64/SDL2.lib;${CMAKE_SOURCE_DIR}/data/lib/x64/SDL2main.lib")
else ()
  set(SDL2_LIBRARIES "${CMAKE_SOURCE_DIR}/data/lib/x86/SDL2.lib;${CMAKE_SOURCE_DIR}/data/lib/x86/SDL2main.lib")
endif ()

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)