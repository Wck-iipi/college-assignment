#include <opencv2/opencv.hpp>

int main() {
    int w = 1920;
    int h = 1080;
    int hw = w / 2;
    int hh = h / 2;

    int indent = 200;
    cv::Point pointRectUpLeft(hw - indent, hh - indent);
    cv::Point pointRectUpRight(hw + indent, hh - indent);
    cv::Point pointRectDownLeft(hw - indent, hh + indent);
    cv::Point pointRectDownRight(hw + indent, hh + indent);
    cv::Point pointTriangleUp(hw, hh - 2 * indent);

    cv::Point pointDoorRectUpLeft(hw - (indent / 3), hh - (indent / 3));
    cv::Point pointDoorRectDownRight(hw + (indent / 3), hh + indent);

    cv::Point pointHouseWallUpLeft(pointRectUpLeft.x - indent * 2, pointRectUpLeft.y);
    cv::Point pointTriangleUpLeft(pointTriangleUp.x - indent * 2, pointTriangleUp.y);

    cv::Point pointWindowUpLeft(pointHouseWallUpLeft.x + (indent / 2), pointHouseWallUpLeft.y + (indent / 2));
    cv::Point pointWindowDownRight(pointRectDownLeft.x - (indent / 2), pointRectDownLeft.y - (indent / 2));

    cv::Mat img = cv::Mat::zeros(h, w, CV_8UC3);

    cv::rectangle(img, pointRectUpLeft, pointRectDownRight, cv::Scalar(255, 255, 255), 1);
    cv::line(img, pointRectUpLeft, pointTriangleUp, cv::Scalar(255, 255, 255), 1);
    cv::line(img, pointRectUpRight, pointTriangleUp, cv::Scalar(255, 255, 255), 1);
    cv::rectangle(img, pointDoorRectUpLeft, pointDoorRectDownRight, cv::Scalar(255, 255, 255), 1);
    cv::rectangle(img, pointHouseWallUpLeft, pointRectDownLeft, cv::Scalar(255, 255, 255), 1);
    cv::line(img, pointTriangleUpLeft, pointTriangleUp, cv::Scalar(255, 255, 255), 1);
    cv::line(img, pointTriangleUpLeft, pointHouseWallUpLeft, cv::Scalar(255, 255, 255), 1);
    cv::rectangle(img, pointWindowUpLeft, pointWindowDownRight, cv::Scalar(255, 255, 255), 1);

    cv::imshow("Image", img);
    cv::waitKey(0);

    return 0;
}
