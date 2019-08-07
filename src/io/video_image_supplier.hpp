#pragma once

#include <opencv2/videoio.hpp>

#include "image_supplier.hpp"

namespace io {
class VideoImageSupplier : public ImageSupplier
{
public:
  explicit VideoImageSupplier(std::string uri);

  /**
   * Obtains next frame from images sequence.
   */
  cv::Mat getImage() override;

private:
  uint64_t count = 0;
  uint64_t run_counter = 0;
  cv::VideoCapture mVideoCapture;
};
}
