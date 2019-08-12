#include <iostream>

#include <QtWidgets/QApplication>
#include <opencv2/highgui.hpp>

#include "core.hpp"
#include "io/video_image_supplier.hpp"

int
main(int argc, char* argv[1])
{
  if (argc < 2) {
    std::cout << "Usage: nano_die path_to_video \n";
    return 0;
  }

  QApplication qtApp(argc, argv);
  core::Core controller(argv[1]);

  return qtApp.exec();
}
