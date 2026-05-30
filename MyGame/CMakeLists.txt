# CMakeList.txt: MyGame için CMake projesi, kaynağı ekleyin ve tanımlayın
# projeye özgü mantık burada bulunur.
#

# Kaynağı bu projenin yürütülebilir dosyasına ekleyin.
add_executable (MyGame 
    "main.cpp"
    "Game.cpp"
    "Game.h"
    "Board.cpp"
    "Board.h"
    "Tetromino.cpp"
    "Tetromino.h"
    "Renderer.cpp"
    "Renderer.h"
)

set_property(TARGET MyGame PROPERTY CXX_STANDARD 20)
set_property(TARGET MyGame PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(MyGame PRIVATE raylib)

if(WIN32)
	target_link_libraries(MyGame PRIVATE winmm)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MyGame PROPERTY CXX_STANDARD 20)
endif()

# TODO: Gerekirse testleri ve yükleme hedeflerini ekleyin.
