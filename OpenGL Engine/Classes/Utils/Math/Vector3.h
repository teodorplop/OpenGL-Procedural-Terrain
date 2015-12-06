#ifndef __VECTOR_3_H__
#define __VECTOR_3_H__

struct Vector3 {
	float x, y, z;
	Vector3();
	Vector3(float x, float y, float z = 0.0f);

	Vector3& Add(const Vector3& other);
	Vector3& Subtract(const Vector3& other);
	Vector3& Multiply(const Vector3& other);
	Vector3& Divide(const Vector3& other);

	friend Vector3 operator+(Vector3 left, const Vector3& other);
	friend Vector3 operator-(Vector3 left, const Vector3& other);
	friend Vector3 operator*(Vector3 left, const Vector3& other);
	friend Vector3 operator/(Vector3 left, const Vector3& other);

	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);
	Vector3& operator*=(const Vector3& other);
	Vector3& operator/=(const Vector3& other);

	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;
};

#endif //__VECTOR_3_H__