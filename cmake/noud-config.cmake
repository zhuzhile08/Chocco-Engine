set(NOUD_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include/Noud/")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(NOUD_LIBRARIES "${CMAKE_SOURCE_DIR}/data/lib/x64/noud.lib")
else ()
  set(NOUD_LIBRARIES MSVC_R"${CMAKE_SOURCE_DIR}/data/lib/x86/noud.lib")
endif ()

string(STRIP "${NOUD_LIBRARIES}" NOUD_LIBRARIES)