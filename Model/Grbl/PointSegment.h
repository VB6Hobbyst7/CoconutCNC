// This file Is a part of "CoconutCNC" application.
// This file was originally ported from "PointSegment.java" class
// of "Universal GcodeSender" application written by Will Winder
// (https://github.com/winder/Universal-G-Code-Sender)

// Copyright 2015-2016 Hayrullin Denis Ravilevich

#pragma once

#include <glm/vec3.hpp>
#include <vector>

#include "ArcProperties.h"

using std::vector;

namespace Coconut
{
	class GCodeCommand;

	class PointSegment
	{
	public:
		enum planes
		{
			XY,
			ZX,
			YZ
		};

		PointSegment(const GCodeCommand& parent);
		PointSegment(const PointSegment& ps);
		PointSegment(const GCodeCommand& parent, const vec3 &b, int num);
		PointSegment(const GCodeCommand& parent, const vec3 &GetPointHandle, int num, const vec3 &center, double radius, bool clockwise);
		~PointSegment();

        PointSegment& operator=(const PointSegment&);

		vec3& GetPoint();

		vector<double> Points() const;

		void SetToolHead(int head);
		int GetToolhead() const;

		void SetLineNumber(int num);
		int GetLineNumber() const;

		void SetSpeed(double s);
		double GetSpeed() const;

		void SetIsZMovement(bool isZ);
		bool IsZMovement() const;

		void SetIsMetric(bool mIsMetric);
		bool IsMetric() const;

		void SetIsArc(bool isA);
		bool IsArc() const;

		void SetIsRapidMovement(bool isF);
		bool IsRapidMovement() const;

		void SetArcCenter(const vec3 &center);

		vector<double> CenterPoints() const;
		vec3& Center();

		void SetIsClockwise(bool clockwise);
		bool IsClockwise() const;

		void SetRadius(double rad);
		double GetRadius() const;

		void ConvertToMetric();

		bool IsAbsolute() const;
		void SetIsAbsolute(bool IsAbsolute);

		planes Plane() const;
		void SetPlane(const planes &plane);

		double GetSpindleSpeed() const;
		void SetSpindleSpeed(double spindleSpeed);

		double GetDwell() const;
		void SetDwell(double dwell);

		const GCodeCommand& GetParent() const;

	private:
		const GCodeCommand& mParent;
		ArcProperties mArcProperties;
		int mToolhead;
		double mSpeed;
		double mSpindleSpeed;
		double mDwell;
		vec3 mPoint;
		bool mIsMetric;
		bool mIsZMovement;
		bool mIsArc;
		bool mIsRapidMovement;
		bool mIsAbsolute;
		int mLineNumber;
		planes mPlane;
	};

}
