#include "main_window.hpp"

using namespace ui;

MainWindow::MainWindow()
{
  mSourceImageLabel.setMinimumSize(kMinimumLabelWidth, kMinimumLabelHeight);
  mProcessedImageLabel.setMinimumSize(kMinimumLabelWidth, kMinimumLabelHeight);

  mLayout.setContentsMargins(0, 0, 0, 0);
  mLayout.addWidget(&mSourceImageLabel);
  mLayout.addWidget(&mProcessedImageLabel);

  setLayout(&mLayout);
  setWindowTitle("Nano Die");

  // make two shortcuts that will be trigger switchToNextFilter and
  // switchToPreviousFilter signals
}

void
MainWindow::updateFrame(const QPixmap& source, const QPixmap& processed)
{
  mSourceImageLabel.setPixmap(source.scaled(
    mSourceImageLabel.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

  mProcessedImageLabel.setPixmap(processed.scaled(mProcessedImageLabel.size(),
                                                  Qt::KeepAspectRatio,
                                                  Qt::SmoothTransformation));

  repaint();
}
