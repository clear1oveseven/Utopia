﻿
#pragma once

#include <stdint.h>
#include "GeometryDefine.h"

struct Vector2;
struct Vector3;

namespace GeometryUtils
{
	float DegToRad(float deg);
	float RadToDeg(float rad);
	
	// 逆时针为正
	float DeltaAngle(Vector3 from, Vector3 to);
	float DeltaAngle(Vector2 from, Vector2 to);
	Vector2 RotateVector2(const Vector2 &from, float rotationDeg);
	Vector2 RotateVector2(const Vector2 &from, const Vector2 &newYAxis);

	void IsPointInRect(Vector2 &r1, Vector2 &r2, Vector2 &r3, Vector2 &r4, Vector2 &p1, Vector2 &p2, Vector2 &result);
	bool IsIntersectLineSegment(Vector2 p1, Vector2 p2, Vector2 q1, Vector2 q2);
	float GetLineIntersectPoint(Vector2 &a1, Vector2 &a2, Vector2 &b1, Vector2 &b2);
	float Cross(Vector2 p1, Vector2 p2);

	bool IsIntersectCirlceRect(const Vector2 &circle_center, float radius, Vector2 rect_center, float length, float width);
	bool IsIntersectRectLineSegment(const Vector2 &r1, const Vector2 &r2, const Vector2 &lp1, const Vector2 &lp2);
	bool IsPointInRect(const Vector2 &r1, const Vector2 &r2, const Vector2 &p);

	bool InFlatDistance(const Vector2 &from, const Vector2 &to, float distance);
	bool InFlatDistance(const Vector3 &from, const Vector3 &to, float distance);

	AABB2 BuildAABB2(const OBB2 &obb2);
	AABB2 BuildAABB2(const Circle &circle);
	AABB2 BuildAABB2(const Sector &sector);

	bool IsIntersectAABB2(const AABB2 &l, const AABB2 &r);
	bool IsIncludeAABB2(const AABB2 &area, const AABB2  &target);	// area include target
	bool CalIntersectAABB2(const AABB2 &l, const AABB2 &r, AABB2 *out);

	bool IsIntersectCircle(const Circle &c1, const Circle &c2);
	bool IsIntersectObb2(const OBB2 &b1, const OBB2 &b2);
	bool IsIntersectSector(const Sector &s1, const Sector &s2);
	bool IsIntersectCircleOBB2(const Circle &circle, const OBB2 &obb2);
	bool IsIntersectCircleSector(const Circle &circle, const Sector &sector);
	bool IsIntersectObb2Sector(const OBB2 &obb2, const Sector &sector);

};


