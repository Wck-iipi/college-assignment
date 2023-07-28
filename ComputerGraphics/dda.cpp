#include <opencv2/opencv.hpp>

int main() {
  int x0 = 0;
  int y0 = 0;
  int x1 = 5;
  int y1 = 5;

  int dx = x1 - x0;
  int dy = y1 - y0;

  cv::Mat img = cv::Mat::zeros(1080, 1920, CV_8UC3);

  int prevX = x0;
  int prevY = y0;

  while (x0 <= x1 && y0 <= y1) {
    img.at<cv::Vec3b>(y0, x0) = cv::Vec3b(255, 255, 255);
    x0 += 0.5;
    y0 += dy;
    std::cout << x0 << " " << y0 << std::endl;
  }

  cv::imshow("Image", img);
  cv::waitKey(0);

  return 0;
}
