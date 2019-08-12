#pragma once

#include <memory>
#include <string>

#include "imgproc/filters.hpp"
#include "io/video_image_supplier.hpp"
#include "ui/main_window.hpp"

namespace core {
class Core : public QObject
{
  Q_OBJECT

public:
  static constexpr uint32_t kDefaultFps = 25;
  static constexpr uint32_t kMsecPerSec = 1000;

  Core(std::string uri, uint32_t fps = kDefaultFps);

private:
  ui::MainWindow mWindow;
  io::VideoImageSupplier mVideoImageSupplier;
  std::unique_ptr<imgproc::BasicFilter> mFilter;
  uint32_t mDelay;

  static QPixmap convertCvMatToQPixmap(cv::Mat mat);

private slots:
  void showNextFrame();
};
}
