
aux_source_directory(. DIR_WHEEL_SRCS)

include_directories(../lib/config)
include_directories(../lib/lcd)
include_directories(../lib/font)
include_directories(../lib/fatfs)
include_directories(../lib/sdcard)

add_library(wheel ${DIR_WHEEL_SRCS})
target_link_libraries(wheel PUBLIC config lcd font fatfs sdcard)
