#include <iostream>

#include <opencv2/highgui.hpp>

#include "io/video_image_supplier.hpp"

int
main(int argc, char const* argv[])
{
  if (argc < 2) {
    std::cout << "Usage: nano_die path_to_video \n";
    return 0;
  }

  io::VideoImageSupplier videoImageSupplier{ std::string(argv[1]) };

  cv::namedWindow("Image View", cv::WINDOW_NORMAL);
  while (true) {
    cv::imshow("Image View", videoImageSupplier.getImage());
    cv::waitKey(40);
  }

  return 0;
}
