#include "Vector3.h"

Vector3::Vector3() {
	x = y = z = 0.0f;
}

Vector3::Vector3(float x, float y, float z) {
	this->x = x, this->y = y, this->z = z;
}

std::ostream& operator<<(std::ostream& out, const Vector3& data) {
	out << data.x << " " << data.y << " " << data.z << "\n";
	return out;
}

float Vector3::Length() {
	return sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::Normalize() {
	float length = Length();
	x /= length, y /= length, z /= length;
	return *this;
}

Vector3 Vector3::CrossProduct(const Vector3& a, const Vector3& b) {
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.z * b.y - a.y * b.z);
}

Vector3& Vector3::Add(const Vector3& other) {
	x += other.x, y += other.y, z += other.z;
	return *this;
}
Vector3& Vector3::Subtract(const Vector3& other) {
	x -= other.x, y -= other.y, z -= other.z;
	return *this;
}
Vector3& Vector3::Multiply(const Vector3& other) {
	x *= other.x, y *= other.y, z *= other.z;
	return *this;
}
Vector3& Vector3::Divide(const Vector3& other) {
	x /= other.x, y /= other.y, z /= other.z;
	return *this;
}
Vector3& Vector3::Multiply(const float& other) {
	x *= other, y *= other, z *= other;
	return *this;
}
Vector3& Vector3::Divide(const float& other) {
	x /= other, y /= other, z /= other;
	return *this;
}

Vector3 operator+(Vector3 left, const Vector3& right) {
	return left.Add(right);
}
Vector3 operator-(Vector3 left, const Vector3& right) {
	return left.Subtract(right);
}
Vector3 operator*(Vector3 left, const Vector3& right) {
	return left.Multiply(right);
}
Vector3 operator/(Vector3 left, const Vector3& right) {
	return left.Divide(right);
}
Vector3 operator*(Vector3 left, const float& right) {
	return left.Multiply(right);
}
Vector3 operator/(Vector3 left, const float& right) {
	return left.Divide(right);
}

Vector3& Vector3::operator+=(const Vector3& other) {
	return Add(other);
}
Vector3& Vector3::operator-=(const Vector3& other) {
	return Subtract(other);
}
Vector3& Vector3::operator*=(const Vector3& other) {
	return Multiply(other);
}
Vector3& Vector3::operator/=(const Vector3& other) {
	return Divide(other);
}
Vector3& Vector3::operator*=(const float& other) {
	return Multiply(other);
}
Vector3& Vector3::operator/=(const float& other) {
	return Divide(other);
}

bool Vector3::operator==(const Vector3& other) const {
	return x == other.x && y == other.y && z == other.z;
}
bool Vector3::operator!=(const Vector3& other) const {
	return !(*this == other);
}