// Copyright (C) 2009-2022, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#pragma once

//
// Macros & functions C++
//
#if defined(__cplusplus)

#	include <AnKi/Math.h>

#	define ANKI_BEGIN_NAMESPACE namespace anki {
#	define ANKI_END_NAMESPACE }
#	define ANKI_SHADER_FUNC_INLINE inline

#	define ANKI_SHADER_INOUT(type_) type_&
#	define ANKI_SHADER_IN(type_) const type_&
#	define ANKI_SHADER_OUT(type_) type_&

#	define ANKI_SHADER_STATIC_ASSERT(cond_) static_assert(cond_, "See file")

#	define ANKI_SIZEOF(x) sizeof(x)

ANKI_BEGIN_NAMESPACE
template<typename T>
inline F32 dot(const T& a, const T& b)
{
	return a.dot(b);
}

using Address = U64;

using ScalarVec4 = Array<F32, 4>;
using ScalarMat3x4 = Array<F32, 12>;
using ScalarMat4 = Array<F32, 16>;
ANKI_END_NAMESPACE

#	define ANKI_CPP_CODE(x) x

#	define ANKI_RP

//
// Macros & functions GLSL
//
#else
#	define x() x
#	define y() y
#	define z() z
#	define w() w

#	define xyz() xyz

#	define ANKI_BEGIN_NAMESPACE
#	define ANKI_END_NAMESPACE
#	define ANKI_SHADER_FUNC_INLINE

#	define ANKI_SHADER_INOUT(type_) inout type_
#	define ANKI_SHADER_IN(type_) in type_
#	define ANKI_SHADER_OUT(type_) out type_

#	define ANKI_SHADER_STATIC_ASSERT(cond_)

#	define ANKI_CPP_CODE(x)

#	define ScalarVec4 Vec4
#	define ScalarMat3x4 Mat3x4
#	define ScalarMat4 Mat4

#	define constexpr const
#endif

//
// Constants
//
ANKI_BEGIN_NAMESPACE

#if !defined(__cplusplus)
constexpr F32 kEpsilonf = 0.000001f;
constexpr F16 kEpsilonhf = 0.0001hf; // Divisions by this should be OK according to http://weitz.de/ieee/
constexpr ANKI_RP F32 kEpsilonRp = F32(kEpsilonhf);

constexpr U32 kMaxU32 = 0xFFFFFFFFu;
constexpr F32 kMaxF32 = 3.402823e+38;
constexpr F16 kMaxF16 = 65504.0hf;
constexpr F16 kMinF16 = 0.00006104hf;

constexpr F32 kPi = 3.14159265358979323846f;
#endif

/// The renderer will group drawcalls into instances up to this number.
constexpr U32 kMaxInstanceCount = 64u;

constexpr U32 kMaxLodCount = 3u;
constexpr U32 kMaxShadowCascades = 4u;

constexpr F32 kShadowsPolygonOffsetFactor = 1.25f;
constexpr F32 kShadowsPolygonOffsetUnits = 2.75f;

ANKI_END_NAMESPACE
