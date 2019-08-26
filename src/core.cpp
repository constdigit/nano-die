#include <QTimer>

#include "core.hpp"

using namespace core;

Core::Core(std::string uri, uint32_t fps)
  : mVideoImageSupplier{ uri }
  , mDelay{ kMsecPerSec / fps }
  , mFilter{ std::make_unique<imgproc::SharpenFilter3x3>() }
{
  mWindow.show();
  showNextFrame();

  // connect signals from MainWindow to appropriate slots
}

QPixmap
Core::convertCvMatToQPixmap(cv::Mat mat)
{
  return QPixmap::fromImage(
    QImage(mat.data, mat.cols, mat.rows, QImage::Format_RGB888).rgbSwapped());
}

void
Core::showNextFrame()
{
  auto sourceImage = mVideoImageSupplier.getImage();
  // select here current filter from vector by id
  auto processedImage = mFilter->apply(sourceImage);
  mWindow.updateFrame(convertCvMatToQPixmap(sourceImage),
                      convertCvMatToQPixmap(processedImage));

  QTimer::singleShot(mDelay, this, SLOT(showNextFrame()));
}
