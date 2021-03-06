/**
 * \file dnn/test/cuda/utils.cpp
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2020 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#include "./utils.h"

namespace megdnn {
namespace test {
bool check_compute_capability(int major, int minor) {
    int dev;
    cuda_check(cudaGetDevice(&dev));
    cudaDeviceProp prop;
    cuda_check(cudaGetDeviceProperties(&prop, dev));
    return prop.major > major || (prop.major == major && prop.minor >= minor);
}
}  // namespace test
}  // namespace megdnn

// vim: syntax=cpp.doxygen
