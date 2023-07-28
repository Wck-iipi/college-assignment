#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

void drawBresenhamEllipse(cv::Mat &image, int center_x, int center_y, int radius_x, int radius_y) {
    cv::Vec3b color = cv::Vec3b(255, 255, 255); //white
    int x = 0;
    int y = radius_y;
    int p1 = radius_y * radius_y - radius_x * radius_x * radius_y + (0.25 * radius_x * radius_x);
    int two_radius_x_sq = 2 * radius_x * radius_x;
    int two_radius_y_sq = 2 * radius_y * radius_y;

    while (two_radius_y_sq * x < two_radius_x_sq * y) {
        image.at<cv::Vec3b>(center_y + y, center_x + x) = color;
        image.at<cv::Vec3b>(center_y + y, center_x - x) = color;
        image.at<cv::Vec3b>(center_y - y, center_x + x) = color;
        image.at<cv::Vec3b>(center_y - y, center_x - x) = color;

        if (p1 < 0) {
            x += 1;
            p1 += two_radius_y_sq * x + radius_y * radius_y;
        } else {
            x += 1;
            y -= 1;
            p1 += two_radius_y_sq * x - two_radius_x_sq * y + radius_y * radius_y;
        }
    }

    int p2 = (radius_y * radius_y) * (x + 0.5) * (x + 0.5) + (radius_x * radius_x) * (y - 1) * (y - 1) - (radius_x * radius_x) * (radius_y * radius_y);

    while (y >= 0) {
        image.at<cv::Vec3b>(center_y + y, center_x + x) = color;
        image.at<cv::Vec3b>(center_y + y, center_x - x) = color;
        image.at<cv::Vec3b>(center_y - y, center_x + x) = color;
        image.at<cv::Vec3b>(center_y - y, center_x - x) = color;

        if (p2 > 0) {
            y -= 1;
            p2 += -two_radius_x_sq * y + radius_x * radius_x;
        } else {
            y -= 1;
            x += 1;
            p2 += two_radius_y_sq * x - two_radius_x_sq * y + radius_x * radius_x;
        }
    }
}

int main() {
    int width = 800;
    int height = 600;

    cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);
    cv::Scalar black(0, 0, 0);
    cv::Scalar white(255, 255, 255);

    cv::namedWindow("Bresenham Ellipse Algorithm", cv::WINDOW_NORMAL);
    cv::resizeWindow("Bresenham Ellipse Algorithm", width, height);

    int center_x = width / 2;
    int center_y = height / 2;
    int radius_x = 150;
    int radius_y = 100;

    drawBresenhamEllipse(image, center_x, center_y, radius_x, radius_y);

    cv::imshow("Bresenham Ellipse Algorithm", image);

    cv::waitKey(0);

    return 0;
}
