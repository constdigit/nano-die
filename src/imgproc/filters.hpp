#pragma once

#include <utility>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>



namespace imgproc {

	class BasicFilter
	{
	public:
		virtual cv::Mat apply(cv::Mat source) = 0;
		cv::Mat operator()(cv::Mat source) { return apply(std::move(source)); }
	};

	class SharpenFilter3x3 : public BasicFilter
	{
	public:
		cv::Mat apply(cv::Mat source) override
		{
			cv::Mat kernel{ -1, -1, -1, -1, 9, -1, -1, -1, -1 };
			cv::Mat sharpenedImage;
			cv::filter2D(source, sharpenedImage, CV_8UC1, kernel);
			return sharpenedImage;
		}
	};
	// Filter Negative
	class NegativeFilter : public BasicFilter
	{
	public:
		cv::Mat apply(cv::Mat source) override
		{
			cv::Mat negative;
			negative = 255 - source;
			return negative;
		}
	};
	// Filter Gauss
	class GaussFilter : public BasicFilter
	{
	public:
		cv::Mat apply(cv::Mat source) override
		{
			cv::Mat gauss;
			GaussianBlur(source, gauss, cv::Size(27, 27), 0, 0);
			return gauss;
		}
	};
	// Filter Blur
	class BlurFilter : public BasicFilter
	{
	public:
		cv::Mat apply(cv::Mat source) override
		{
			cv::Mat blurs;
			blur(source, blurs, cv::Size(27, 27));
			return blurs;
		}
	};
	// Filter Dilate
	class DilateFilter : public BasicFilter
	{
	public:
		cv::Mat apply(cv::Mat source) override
		{
			cv::Mat Dilate;
			dilate(source, Dilate, cv::Mat(), cv::Point(-1, -1), 3);
			return Dilate;
		}
	};
	// Filter Bilateral
	class BilatFilter : public BasicFilter
	{
	public:
		cv::Mat apply(cv::Mat source) override
		{
			cv::Mat Bilat;
			bilateralFilter(source, Bilat, 20, 40, 10);
			return Bilat;
		}
	};
	// Filter Erode
	class ErodeFilter : public BasicFilter
	{
	public:
		cv::Mat apply(cv::Mat source) override
		{
			cv::Mat Erode;
			erode(source, Erode, cv::Mat(), cv::Point(-1, -1), 20);

			//bilateralFilter(source, Bilat, 20, 40, 10);
			return Erode;
		}
	};
}