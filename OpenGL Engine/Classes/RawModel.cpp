#include "RawModel.h"
#include "Camera.h"
#include "Core/Renderer.h"

RawModel::RawModel(VertexArray* vertexArray, IndexBuffer* indexBuffer) {
	this->vertexArray = vertexArray, this->indexBuffer = indexBuffer;
}
VertexArray* RawModel::GetVertexArray() {
	return vertexArray;
}
IndexBuffer* RawModel::GetIndexBuffer() {
	return indexBuffer;
}