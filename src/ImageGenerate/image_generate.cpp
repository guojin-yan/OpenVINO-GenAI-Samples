#include "image_generate.h"

std::string gbk_to_utf8(const std::string& gbkStr)
{
    std::string outUtf8 = "";
    int n = MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, NULL, 0);

    WCHAR* str1 = new WCHAR[n];
    MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, str1, n);
    n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);

    char* str2 = new char[n];
    WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
    outUtf8 = str2;

    delete[]str1;
    str1 = NULL;

    delete[]str2;
    str2 = NULL;

    return outUtf8;
}
std::string utf8_to_gbk(const std::string& utf8Str)
{
    std::string outGBK = "";
    int n = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);

    WCHAR* str1 = new WCHAR[n];
    MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, str1, n);
    n = WideCharToMultiByte(CP_ACP, 0, str1, -1, NULL, 0, NULL, NULL);

    char* str2 = new char[n];
    WideCharToMultiByte(CP_ACP, 0, str1, -1, str2, n, NULL, NULL);
    outGBK = str2;

    delete[] str1;
    str1 = NULL;

    delete[] str2;
    str2 = NULL;

    return outGBK;
}

cv::Mat tensor_to_mat(ov::Tensor data) {
    //std::cout << data.get_shape()[0] << ", " << data.get_shape()[1] << ", " << data.get_shape()[2] << ", " << data.get_shape()[3] << std::endl;
    //std::cout << data.get_element_type() << std::endl;
    cv::Mat mat(data.get_shape()[1], data.get_shape()[2], CV_8UC3, data.data());
    cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
    return mat;
}
