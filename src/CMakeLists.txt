set( EXE_NAME htmlbutcher2 )

find_package(Qt5Widgets REQUIRED)

#----------
# SOURCES
#----------

set( EXE_SRCS
    main.cpp
    
	HTMLButcherMain.cpp
)

set( EXE_INCS
	${BASE_INCLUDE_PATH}/HTMLButcher2/HTMLButcherMain.h
)

#set( EXE_RCCS ${BASE_SOURCE_PATH}/resources/ebclient.qrc )

#if (WIN32)
#	set( EXE_SRCS ${EXE_SRCS} ${BASE_SOURCE_PATH}/resources/ebclient.rc )
#endif()

#qt5_add_resources(EXE_RCC_SRCS ${EXE_RCCS})

#----------
# BINARY
#----------

add_executable(${EXE_NAME} WIN32 ${EXE_SRCS} ${EXE_INCS} ${EXE_RCC_SRCS})

target_link_libraries ( ${EXE_NAME}

)

target_link_libraries(${EXE_NAME} Qt5::Widgets)