add_library(loginLib
    LoginManager.cpp
    LoginManager.hpp
)

target_link_libraries(loginLib
    PRIVATE
        Qt6::Core
        Qt6::Network
)
