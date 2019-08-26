#pragma once

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <opencv2/core.hpp>

namespace ui {
class MainWindow : public QWidget
{
  Q_OBJECT

public:
  MainWindow();

public slots:
  void updateFrame(const QPixmap& source, const QPixmap& processed);

signals:
  void switchToNextFilter();
  void switchToPreviousFilter();

private:
  static constexpr int kMinimumLabelWidth = 640;
  static constexpr int kMinimumLabelHeight = 360;
  QHBoxLayout mLayout;
  QLabel mSourceImageLabel;
  QLabel mProcessedImageLabel;
};
}
