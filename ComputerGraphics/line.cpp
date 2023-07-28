#include <opencv2/opencv.hpp>

int main() {
  cv::Mat image = cv::Mat::zeros(500, 500, CV_8UC3);

  cv::Point startPoint(100, 100);
  cv::Point endPoint(350, 350);

  cv::line(image, startPoint, endPoint, cv::Scalar(255, 255, 255), 2);

  cv::imshow("Line Drawing", image);
  cv::waitKey(0);

  return 0;
}
