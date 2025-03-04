#include "image_generate.h"

int text_generate_image(std::string model_path, std::string device) {
    try {
        std::string prompt;
        ov::genai::Text2ImagePipeline pipe(model_path, device);
        while (1) {
            std::cout << "------------------------" << std::endl << "Please ask:" << std::endl;
            std::getline(std::cin, prompt);
            ov::Tensor image = pipe.generate(gbk_to_utf8(prompt),
                ov::genai::width(1024),
                ov::genai::height(512),
                ov::genai::num_inference_steps(4),
                ov::genai::num_images_per_prompt(1));

            cv::Mat mat = tensor_to_mat(image);
            cv::imshow("image", mat);
            cv::waitKey(0);
        }


        return EXIT_SUCCESS;
    }
    catch (const std::exception& error) {
        try {
            std::cerr << error.what() << '\n';
        }
        catch (const std::ios_base::failure&) {}
        return EXIT_FAILURE;
    }
    catch (...) {
        try {
            std::cerr << "Non-exception object thrown\n";
        }
        catch (const std::ios_base::failure&) {}
        return EXIT_FAILURE;
    }
}