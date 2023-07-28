#include <opencv2/opencv.hpp>

int main() {
    int width = 800;
    int height = 600;

    cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);
    cv::Scalar white(255, 255, 255);
    cv::Scalar black(0, 0, 0);

    cv::namedWindow("Bresenham Line Algorithm", cv::WINDOW_NORMAL);
    cv::resizeWindow("Bresenham Line Algorithm", width, height);

    cv::imshow("Bresenham Line Algorithm", image);
    cv::waitKey(1);

    cv::Point p1(150, 150);
    cv::Point p2(720, 510);

    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = (p1.x < p2.x) ? 1 : -1;
    int sy = (p1.y < p2.y) ? 1 : -1;
    int err = dx - dy;

    while (p1 != p2) {
        image.at<cv::Vec3b>(p1) = cv::Vec3b(255, 255, 255);
        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            p1.x += sx;
        }

        if (e2 < dx) {
            err += dx;
            p1.y += sy;
        }

        cv::imshow("Bresenham Line Algorithm", image);
        cv::waitKey(1);
    }

    while (true) {
        int key = cv::waitKey(0);
        if (key == 27) // Press Esc to exit
            break;
    }

    cv::destroyAllWindows();

    return 0;
}
