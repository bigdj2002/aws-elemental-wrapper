# Add source files
add_executable(medialive_wrapper app/main.cpp src/MediaLiveWrapper.cpp)

# Link AWS SDK libraries
target_link_libraries(medialive_wrapper ${AWSSDK_LINK_LIBRARIES})