
#include <iostream>

#include <opencv2/videoio.hpp>

#include "video_image_supplier.hpp"


using namespace std;
using namespace cv;

io::VideoImageSupplier::VideoImageSupplier(std::string uri)
  : ImageSupplier(uri)
{
  mVideoCapture.open(uri);       // open video
  if (!mVideoCapture.isOpened()) // check if we succeeded
  {
    throw runtime_error("Can not open video");
  }
  mCount = mVideoCapture.get(CAP_PROP_FRAME_COUNT);
  mEnd_frame = mCount - 4;
}


cv::Mat
io::VideoImageSupplier::getImage()
{

  Mat frame;
  
 if (mRun_counter != mEnd_frame) {
    mVideoCapture >> frame;
    mRun_counter = mVideoCapture.get(CAP_PROP_POS_FRAMES);
  } else {
    mVideoCapture.set(CAP_PROP_POS_FRAMES, mEnd_frame);
    mVideoCapture >> frame;
  }
  
  if (!frame.empty()) {
    return frame;
  }
}