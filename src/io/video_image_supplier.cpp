
#include <iostream>

#include <opencv2/videoio.hpp>

#include "video_image_supplier.hpp"

using namespace std;
using namespace cv;

io::VideoImageSupplier::VideoImageSupplier(std::string uri)
  : ImageSupplier(uri)
{
  // open video
  mVideoCapture.open(uri);
  // check if we succeeded
  if (!mVideoCapture.isOpened()) {
    throw runtime_error("Can not open video");
  }
  mVideoLength = mVideoCapture.get(CAP_PROP_FRAME_COUNT);
  mLastFrameId = mVideoLength - 1;
}

cv::Mat
io::VideoImageSupplier::getImage()
{
  Mat frame;

  if (mCurrentFrameId != mLastFrameId) {
    mVideoCapture >> frame;
    mCurrentFrameId = mVideoCapture.get(CAP_PROP_POS_FRAMES);
  } else {
    mVideoCapture.set(CAP_PROP_POS_FRAMES, mLastFrameId);
    mVideoCapture >> frame;
  }

  if (frame.empty()) {
    throw std::runtime_error(std::string{ "Get empty frame with id: " } +
                             std::to_string(mCurrentFrameId));
  }

  return frame;
}
