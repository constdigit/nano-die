#include "video_image_supplier.hpp"

io::VideoImageSupplier::VideoImageSupplier(std::string uri)
  : ImageSupplier(uri)
{
  // check is uri valid (optional)
  // open video
}

cv::Mat
io::VideoImageSupplier::getImage()
{
  // obtain next frame from capture
  // check for video end
}
