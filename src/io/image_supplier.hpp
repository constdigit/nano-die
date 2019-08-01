#pragma once

#include <string>

#include <opencv2/core.hpp>

namespace io {
class ImageSupplier
{
public:
  explicit ImageSupplier(std::string uri)
    : mUri{ std::move(uri) }
  {}
  virtual cv::Mat getImage() = 0;

protected:
  std::string mUri;
};
}