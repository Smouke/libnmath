/*

    This file is part of the Nemesis3dMath library.

    vector.h
    Vector

    Copyright (C) 2008, 2010
    Papadopoulos Nikolaos

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General
    Public License along with this library; if not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301 USA

*/

#ifndef LIBNMATH_VECTOR_H_INCLUDED
#define LIBNMATH_VECTOR_H_INCLUDED

#include "types.h"

#ifdef __cplusplus
    #include <cstdio>
#else
    #include <stdio.h>
#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/*
    C 2D vector functions
*/
inline vec2_t vec2_pack(real_t x, real_t y);

inline vec2_t vec2_add(vec2_t v1, vec2_t v2);
inline vec2_t vec2_sub(vec2_t v1, vec2_t v2);
inline vec2_t vec2_neg(vec2_t v);
inline vec2_t vec2_mul(vec2_t v1, vec2_t v2);
inline vec2_t vec2_scale(vec2_t v, real_t s);

inline real_t vec2_length(vec2_t v);
inline real_t vec2_length_sq(vec2_t v);
inline vec2_t vec2_normalize(vec2_t v);

inline real_t vec2_dot(vec2_t v1, vec2_t v2);

inline void vec2_print(FILE *fp, vec2_t v);

/*
    C 3D vector functions
*/
inline vec3_t vec3_pack(real_t x, real_t y, real_t z);

inline vec3_t vec3_add(vec3_t v1, vec3_t v2);
inline vec3_t vec3_sub(vec3_t v1, vec3_t v2);
inline vec3_t vec3_neg(vec3_t v);
inline vec3_t vec3_mul(vec3_t v1, vec3_t v2);
inline vec3_t vec3_scale(vec3_t v1, real_t s);

inline real_t vec3_length(vec3_t v);
inline real_t vec3_length_sq(vec3_t v);
inline vec3_t vec3_normalize(vec3_t v);

inline real_t vec3_dot(vec3_t v1, vec3_t v2);
inline vec3_t vec3_cross(vec3_t v1, vec3_t v2);

inline vec3_t vec3_lerp(vec3_t v1, vec3_t v2, real_t t);

inline void vec3_print(FILE *fp, vec3_t v);

/*
    C 4D vector functions
*/
inline vec4_t vec4_pack(real_t x, real_t y, real_t z, real_t w);

inline vec4_t vec4_add(vec4_t v1, vec4_t v2);
inline vec4_t vec4_sub(vec4_t v1, vec4_t v2);
inline vec4_t vec4_neg(vec4_t v);
inline vec4_t vec4_mul(vec4_t v1, vec4_t v2);
inline vec4_t vec4_scale(vec4_t v, real_t s);

inline real_t vec4_length(vec4_t v);
inline real_t vec4_length_sq(vec4_t v);
inline vec4_t vec4_normalize(vec4_t v);

inline real_t vec4_dot(vec4_t v1, vec4_t v2);

inline vec4_t vec4_transform(vec4_t v, mat4x4_t m);

#ifdef __cplusplus
}   /* extern "C" */

#include <ostream>

/*
    2D VECTOR
*/
class Vector2
{
    public:
        /* Constructors */
        Vector2(real_t aX = 0.0, real_t aY = 0.0);
        Vector2(const Vector2& v);
        Vector2(const Vector3& v);
        Vector2(const Vector4& v);

        /* Array subscript */
        inline real_t& operator [](unsigned int index);
        inline const real_t& operator [](unsigned int index) const;

        /* Assignment operator */
        inline const Vector2& operator =(const Vector2& v);

        /* Unary operator */
        friend inline const Vector2 operator -(const Vector2& v);

        /* Arithmetic operators */
        /* - Binary */
        friend inline const Vector2 operator +(const Vector2& v1, const Vector2& v2);
        friend inline const Vector2 operator -(const Vector2& v1, const Vector2& v2);
        friend inline const Vector2 operator *(const Vector2& v1, const Vector2& v2);
        friend inline const Vector2 operator /(const Vector2& v1, const Vector2& v2);
        /* - Scalar */
        friend inline const Vector2 operator +(real_t r, const Vector2& v);
        friend inline const Vector2 operator +(const Vector2& v, real_t r);
        friend inline const Vector2 operator -(const Vector2& v, real_t r);
        friend inline const Vector2 operator *(real_t r, const Vector2& v);
        friend inline const Vector2 operator *(const Vector2& v, real_t r);
        friend inline const Vector2 operator /(const Vector2& v, real_t r);

        /* Compound assignment operators */
        /* - Binary */
        friend inline Vector2& operator +=(Vector2& v1, const Vector2& v2);
        friend inline Vector2& operator -=(Vector2& v1, const Vector2& v2);
        friend inline Vector2& operator *=(Vector2& v1, const Vector2& v2);
        friend inline Vector2& operator /=(Vector2& v1, const Vector2& v2);
        /* - Scalar */
        friend inline Vector2& operator +=(Vector2& vec, real_t scalar);
        friend inline Vector2& operator -=(Vector2& vec, real_t scalar);
        friend inline Vector2& operator *=(Vector2& vec, real_t scalar);
        friend inline Vector2& operator /=(Vector2& vec, real_t scalar);

        /* Comparison operations */
        friend inline bool operator ==(const Vector2& v1, const Vector2& v2);
        friend inline bool operator !=(const Vector2& v1, const Vector2& v2);

        /* Stream operations */
        friend std::ostream& operator <<(std::ostream& out, const Vector2& vec);

        /* Vector member functions */
        /* - Length */
        inline real_t length() const;
        inline real_t length_squared() const;
        /* - Normalization */
        inline void normalize();
        inline Vector2 normalized() const;

        real_t x, y;
};

inline real_t dot(const Vector2& v1, const Vector2& v2);

/*
    3D VECTOR
*/
class Vector3
{
    public:
        /* Constructors */
        Vector3(real_t aX = 0.0, real_t aY = 0.0, real_t aZ = 0.0);
        Vector3(const Vector3& v);
        Vector3(const Vector2& v);
        Vector3(const Vector4& v);

        /* Array subscript */
        inline real_t& operator [](unsigned int index);
        inline const real_t& operator [](unsigned int index) const;

        /* Assignment operator */
        inline const Vector3& operator =(const Vector3& v);

        /* Unary operator */
        friend inline const Vector3 operator -(const Vector3& v);

        /* Arithmetic operators */
        /* - Binary */
        friend inline const Vector3 operator +(const Vector3& v1, const Vector3& v2);
        friend inline const Vector3 operator -(const Vector3& v1, const Vector3& v2);
        friend inline const Vector3 operator *(const Vector3& v1, const Vector3& v2);
        friend inline const Vector3 operator /(const Vector3& v1, const Vector3& v2);
        /* - Scalar */
        friend inline const Vector3 operator +(real_t r, const Vector3& v);
        friend inline const Vector3 operator +(const Vector3& v, real_t r);
        friend inline const Vector3 operator -(const Vector3& v, real_t r);
        friend inline const Vector3 operator *(real_t r, const Vector3& v);
        friend inline const Vector3 operator *(const Vector3& v, real_t r);
        friend inline const Vector3 operator /(const Vector3& v, real_t r);

        /* Compound assignment operators */
        /* - Binary */
        friend inline Vector3& operator +=(Vector3& v1, const Vector3& v2);
        friend inline Vector3& operator -=(Vector3& v1, const Vector3& v2);
        friend inline Vector3& operator *=(Vector3& v1, const Vector3& v2);
        friend inline Vector3& operator /=(Vector3& v1, const Vector3& v2);
        /* - Scalar */
        friend inline Vector3& operator +=(Vector3& vec, real_t scalar);
        friend inline Vector3& operator -=(Vector3& vec, real_t scalar);
        friend inline Vector3& operator *=(Vector3& vec, real_t scalar);
        friend inline Vector3& operator /=(Vector3& vec, real_t scalar);

        /* Comparison operations */
        friend inline bool operator ==(const Vector3& v1, const Vector3& v2);
        friend inline bool operator !=(const Vector3& v1, const Vector3& v2);

        /* Stream operations */
        friend std::ostream& operator <<(std::ostream& out, const Vector3& vec);

        /* Vector member functions */
        /* - Length */
        inline real_t length() const;
        inline real_t length_squared() const;
        /* - Normalization */
        inline void normalize();
        inline Vector3 normalized() const;

        real_t x, y, z;
};

inline real_t dot(const Vector3& v1, const Vector3& v2);
inline Vector3 cross(const Vector3& v1, const Vector3& v2);

/*
    4D VECTOR
*/
class Vector4
{
    public:
        /* Constructors */
        Vector4(real_t aX = 0.0, real_t aY = 0.0, real_t aZ = 0.0, real_t aW = 0.0);
        Vector4(const Vector4& v);
        Vector4(const Vector2& v);
        Vector4(const Vector3& v);

        /* Array subscript */
        inline real_t& operator [](unsigned int index);
        inline const real_t& operator [](unsigned int index) const;

        /* Assignment operator */
        inline const Vector4& operator =(const Vector4& v);

        /* Unary operator */
        friend inline const Vector4 operator -(const Vector4& v);

        /* Arithmetic operators */
        /* - Binary */
        friend inline const Vector4 operator +(const Vector4& v1, const Vector4& v2);
        friend inline const Vector4 operator -(const Vector4& v1, const Vector4& v2);
        friend inline const Vector4 operator *(const Vector4& v1, const Vector4& v2);
        friend inline const Vector4 operator /(const Vector4& v1, const Vector4& v2);
        /* - Scalar */
        friend inline const Vector4 operator +(real_t r, const Vector4& v);
        friend inline const Vector4 operator +(const Vector4& v, real_t r);
        friend inline const Vector4 operator -(const Vector4& v, real_t r);
        friend inline const Vector4 operator *(real_t r, const Vector4& v);
        friend inline const Vector4 operator *(const Vector4& v, real_t r);
        friend inline const Vector4 operator /(const Vector4& v, real_t r);

        /* Compound assignment operators */
        /* - Binary */
        friend inline Vector4& operator +=(Vector4& v1, const Vector4& v2);
        friend inline Vector4& operator -=(Vector4& v1, const Vector4& v2);
        friend inline Vector4& operator *=(Vector4& v1, const Vector4& v2);
        friend inline Vector4& operator /=(Vector4& v1, const Vector4& v2);
        /* - Scalar */
        friend inline Vector4& operator +=(Vector4& vec, real_t scalar);
        friend inline Vector4& operator -=(Vector4& vec, real_t scalar);
        friend inline Vector4& operator *=(Vector4& vec, real_t scalar);
        friend inline Vector4& operator /=(Vector4& vec, real_t scalar);

        /* Comparison operations */
        friend inline bool operator ==(const Vector4& v1, const Vector4& v2);
        friend inline bool operator !=(const Vector4& v1, const Vector4& v2);

        /* Stream operations */
        friend std::ostream& operator <<(std::ostream& out, const Vector4& vec);

        /* Vector member functions */
        /* - Length */
        inline real_t length() const;
        inline real_t length_squared() const;
        /* - Normalization */
        inline void normalize();
        inline Vector4 normalized() const;

        real_t x, y, z, w;
};

inline real_t dot(const Vector4& v1, const Vector4& v2);

#endif	/* __cplusplus */

#include "vector.inl"

#endif /* LIBNMATH_VECTOR_H_INCLUDED */