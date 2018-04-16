#pragma once

#include <stdint.h>
#include "GeometryDefine.h"
#include <float.h>
#include <cstddef>

struct Vector2;
struct Vector3;

namespace GeometryUtils
{
	// ʹ����������ϵ��˳ʱ��Ϊ��ת������2d 3d����unity 3d��SignAngle�����Ľ��Ϊ��׼
	float DeltaAngle(const Vector3 &from, const Vector3 & to);
	float DeltaAngle(const Vector2 &from, const Vector2 &to);
};


