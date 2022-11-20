cmake_minimum_required (VERSION 3.8)

project ("ArkEngine")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
	"ArkEngine/Core/DebugSystem/Assertion.hpp"
	"ArkEngine/Core/DebugSystem/Log.hpp"
	"ArkEngine/ToolBox/Math/Headers/Mat4x4.hpp"
	"ArkEngine/ToolBox/Math/Headers/Utils.hpp"
	"ArkEngine/ToolBox/Math/Headers/Vector2.hpp"
	"ArkEngine/ToolBox/Math/Headers/Vector3.hpp"
	"ArkEngine/ToolBox/Math/Headers/Vector4.hpp"
 )

set(SOURCES
	"ArkEngine/Core/main.cpp"
	"ArkEngine/Core/DebugSystem/Log.cpp"
)

add_executable ( ${PROJECT_NAME}
				 ${SOURCES}
				 ${HEADERS}
)

if (CMAKE_CXX_COMPILER_ID STREQUAL GNU)
    set(CXX_FILESYSTEM_LIBRARIES stdc++fs)
else()
    set(CXX_FILESYSTEM_LIBRARIES)
endif()

include_directories( "ArkEngine/Common"
					 "ArkEngine/Core"
					 "ArkEngine/Core/DebugSystem"
					 "ArkEngine/External"
					 "ArkEngine/ToolBox/Math/Headers"

)

target_link_libraries( ${PROJECT_NAME}
					   ${CXX_FILESYSTEM_LIBRARIES}
)

target_compile_features( ${PROJECT_NAME}
						 PUBLIC cxx_std_17
)
 
set_target_properties(  ${PROJECT_NAME}
                        PROPERTIES
                        CXX_STANDARD 17
                        CXX_STANDARD_REQUIRED YES
                        CXX_EXTENSIONS NO
                        LINKER_LANGUAGE CXX
)
