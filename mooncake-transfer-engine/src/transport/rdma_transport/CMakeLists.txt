file(GLOB RDMA_SOURCES "*.cpp")

add_library(rdma_transport OBJECT ${RDMA_SOURCES})
target_link_libraries(rdma_transport PRIVATE jsoncpp glog::glog pthread)

if (USE_SUNRISE)
    target_include_directories(rdma_transport PUBLIC
            /usr/local/pccl/include
            /usr/local/tangrt/include/
            /data/liujialai/codes/pccl/source/include)
endif()

if (USE_SUNRISE)
    include_directories(
            /usr/local/pccl/include
            /usr/local/tangrt/include/
            /data/liujialai/codes/pccl/source/include)
endif()