set(SDL2_MIXER_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include/SDL/")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_MIXER_LIBRARIES "${CMAKE_SOURCE_DIR}/data/lib/x64/SDL2_mixer.lib")
else ()
  set(SDL2_MIXER_LIBRARIES "${CMAKE_SOURCE_DIR}/data/lib/x86/SDL2_mixer.lib")
endif ()

string(STRIP "${SDL2_MIXER_LIBRARIES}" SDL2_MIXER_LIBRARIES)
