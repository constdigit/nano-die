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
};
}
