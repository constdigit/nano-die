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
  uint64_t mCount = mVideoCapture.get(CAP_PROP_FRAME_COUNT);;
  uint64_t mRun_counter = 0;
  uint64_t mEnd_frame = mCount - 4;
  cv::VideoCapture mVideoCapture;
};
}
