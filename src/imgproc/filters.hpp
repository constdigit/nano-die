#pragma once

#include <utility>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

namespace imgproc {

class BasicFilter
{
public:
  virtual cv::Mat apply(cv::Mat source) = 0;
  cv::Mat operator()(cv::Mat source) { return apply(std::move(source)); }
};

class SharpenFilter3x3 : public BasicFilter
{
public:
private:
  cv::Mat apply(cv::Mat source) override
  {
    cv::Mat kernel{ -1, -1, -1, -1, 9, -1, -1, -1, -1 };
    cv::Mat sharpenedImage;
    cv::filter2D(source, sharpenedImage, CV_8UC1, kernel);
    return sharpenedImage;
  }
};
}
