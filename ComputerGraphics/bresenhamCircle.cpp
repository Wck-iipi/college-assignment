#include <opencv2/opencv.hpp>
#include <iostream>

const cv::Scalar BLACK(0, 0, 0);
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 500;

cv::Mat window(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3);

cv::Point shiftO(cv::Point cord, cv::Point origin = cv::Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)) {
    return cv::Point(cord.x + origin.x, -cord.y + origin.y);
}

void bresenhamCircle(cv::Point center, int rad) {
    cv::Vec3b color = cv::Vec3b(255, 255, 255); //white
    int x0 = center.x;
    int y0 = center.y;
    int x = 0;
    int y = rad;
    int delta = 2 * (1 - rad);
    
    while (y >= x) {
        window.at<cv::Vec3b>(shiftO(cv::Point(x + x0, y + y0))) = color;
        window.at<cv::Vec3b>(shiftO(cv::Point(y + x0, x + y0))) = color;
        window.at<cv::Vec3b>(shiftO(cv::Point(-x + x0, y + y0))) = color;
        window.at<cv::Vec3b>(shiftO(cv::Point(-y + x0, x + y0))) = color;
        window.at<cv::Vec3b>(shiftO(cv::Point(x + x0, -y + y0))) = color;
        window.at<cv::Vec3b>(shiftO(cv::Point(y + x0, -x + y0))) = color;
        window.at<cv::Vec3b>(shiftO(cv::Point(-x + x0, -y + y0))) = color;
        window.at<cv::Vec3b>(shiftO(cv::Point(-y + x0, -x + y0))) = color;

        if (delta < 0) {
            int d = 2 * delta + 2 * y - 1;
            if (d <= 0) {
                x += 1;
                delta += 2 * x + 1;
            } else {
                x += 1;
                y -= 1;
                delta += 2 * x - 2 * y + 2;
            }
        } else if (delta > 0) {
            int dp = 2 * delta - 2 * x - 1;
            if (dp <= 0) {
                x += 1;
                y -= 1;
                delta += 2 * x - 2 * y + 2;
            } else {
                y -= 1;
                delta += -2 * y + 1;
            }
        } else {
            x += 1;
            y -= 1;
            delta += 2 * x - 2 * y + 2;
        }
    }
}

int main() {
    cv::namedWindow("Bresenham Circle", cv::WINDOW_NORMAL);
    cv::resizeWindow("Bresenham Circle", WINDOW_WIDTH, WINDOW_HEIGHT);

    window.setTo(BLACK);
    bresenhamCircle(cv::Point(1, 1), 100);
    cv::imshow("Bresenham Circle", window);
    cv::waitKey(0);
    return 0;
}
