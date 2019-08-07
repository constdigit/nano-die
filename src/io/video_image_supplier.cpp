
#include <opencv2/videoio.hpp>

#include "video_image_supplier.hpp"

#include <iostream>

using namespace std;
using namespace cv;

io::VideoImageSupplier::VideoImageSupplier(std::string uri)
  : ImageSupplier(uri)
{
  // uri adres image
  // check is uri valid (optional)
  // open video (true)
  mVideoCapture.open(uri);       // open the default camera
  if (!mVideoCapture.isOpened()) // check if we succeeded
  {
    throw runtime_error("Can not open video");
  }
}


cv::Mat
io::VideoImageSupplier::getImage()
{
  // obtain next frame from capture
  // check for video end

  Mat frame;
  
  count = mVideoCapture.get(CAP_PROP_FRAME_COUNT);
  uint16_t end_frame = count - 4;
  
 if (run_counter != end_frame) {
    mVideoCapture >> frame;
    run_counter = mVideoCapture.get(CAP_PROP_POS_FRAMES);
  }else{
    mVideoCapture.set(CAP_PROP_POS_FRAMES, end_frame);
    mVideoCapture >> frame;
  }
  
  if (!frame.empty()) {
    return frame;
  } else {
    cout << "frame empty" << endl;
    cout << "Count = " << count << " Run_counter = " << run_counter << endl;
  }
}