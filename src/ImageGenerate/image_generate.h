#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <windows.h>
#include "opencv2/opencv.hpp"
#include "openvino/openvino.hpp"
#include "openvino/genai/image_generation/text2image_pipeline.hpp"

extern std::string gbk_to_utf8(const std::string& gbkStr);
extern std::string utf8_to_gbk(const std::string& utf8Str);

extern cv::Mat tensor_to_mat(ov::Tensor data);

extern int text_generate_image(std::string model_path, std::string device);